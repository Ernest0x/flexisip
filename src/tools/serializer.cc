/*
	Flexisip, a flexible SIP proxy server with media capabilities.
	Copyright (C) 2010-2015  Belledonne Communications SARL, All rights reserved.

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Affero General Public License as
	published by the Free Software Foundation, either version 3 of the
	License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "tool_utils.hh"
#include <chrono>

using namespace std;
using namespace chrono;

int test_bind_with_ecc(ExtendedContactCommon &ecc, const unique_ptr<RecordSerializer> &serializer, string contact,
					   time_t expireat, float quality, long cseq, time_t now, bool alias, sip_accept_t *accept) {
	Record initial("key");

	list<string> acceptHeaders;
	while (accept != NULL) {
		acceptHeaders.push_back(accept->ac_type);
		accept = accept->ac_next;
	}

	initial.update(ecc, contact.c_str(), expireat, quality, cseq, now, alias, acceptHeaders, false);
	if (!compare(firstContact(initial), alias, ecc, cseq, expireat, quality, contact, now)) {
		cerr << "Initial and parameters differ" << endl;
		return -1;
	}

	string serialized;
	if (!serializer->serialize(&initial, serialized, true)) {
		cerr << "Failed serializing" << endl;
		return -1;
	}

	Record final("key");
	if (!serializer->parse(serialized, &final)) {
		cerr << "Failed parsing" << endl;
		return -1;
	}

	if (!compare(initial, final)) {
		cerr << "Initial and final initial differs" << endl;
		return -1;
	}

	cerr << "success : test_bind_with_ecc" << endl;
	return 0;
}

int test_bind_without_ecc(ExtendedContactCommon &ecc, const unique_ptr<RecordSerializer> &serializer,
						  sip_contact_t *contacts, sip_path_t *path, int globalexpire, const char *callid,
						  string contact, time_t expireat, float quality, long cseq, time_t now, bool alias,
						  sip_accept_t *accept) {
	Record initial("key");

	list<string> acceptHeaders;
	while (accept != NULL) {
		acceptHeaders.push_back(accept->ac_type);
		accept = accept->ac_next;
	}

	initial.update(contacts, path, globalexpire, callid, cseq, now, alias, acceptHeaders, false);
	if (!compare(firstContact(initial), alias, ecc, cseq, expireat, quality, contact, now)) {
		cerr << "Initial and parameters differ" << endl;
		return -1;
	}

	string serialized;
	if (!serializer->serialize(&initial, serialized, true)) {
		cerr << "Failed serializing" << endl;
		return -1;
	} else {
		cout << "Serialized size: " << serialized.length() << endl;
	}

	Record final("key");
	if (!serializer->parse(serialized, &final)) {
		cerr << "Failed parsing" << endl;
		return -1;
	}

	if (!compare(initial, final)) {
		cerr << "Initial and final initial differs" << endl;
		return -1;
	}

	cerr << "success : test_bind_without_ecc" << endl;
	return 0;
}

int test_performances_with_iterations(int iterations,
									  ExtendedContactCommon &ecc,
									  const unique_ptr<RecordSerializer> &serializer,
									  string contact,
									  time_t expireat,
									  float quality,
									  long cseq,
									  time_t now,
									  bool alias,
									  sip_accept_t *accept)
{


	Record initial("key");

	list<string> acceptHeaders;
	while (accept != NULL) {
		acceptHeaders.push_back(accept->ac_type);
		accept = accept->ac_next;
	}

	initial.update(ecc, contact.c_str(), expireat, quality, cseq, now, alias, acceptHeaders, false);
	if (!compare(firstContact(initial), alias, ecc, cseq, expireat, quality, contact, now)) {
		cerr << "Initial and parameters differ" << endl;
		return -1;
	}

	string serialized;
	long total_size = 0;
	serialized.reserve(512);

	steady_clock::time_point start = steady_clock::now();

	for( int i=0; i<iterations; i++ ){
		if (!serializer->serialize(&initial, serialized, false)) {
			cerr << "Failed serializing" << endl;
			return -1;
		}
		total_size += serialized.length();
		serialized.clear();
	}

	steady_clock::time_point stop = steady_clock::now();
#define DURATION_MS(start, stop) (unsigned long) duration_cast<milliseconds>((stop) - (start)).count()

	unsigned long duration_ms = DURATION_MS(start, stop);

	cout << "[SERIALIZE] Duration of the " << iterations << " iterations: " << duration_ms << "ms" << endl;
	cout << "[SERIALIZE] Performances: " << (float)iterations/(duration_ms/1000.0F) << " serializations / s" << endl;
	cout << "[SERIALIZE] Performances: " << (float)(duration_ms)/(float)iterations << "ms / serialization" << endl;

	Record final("key");
	if (!serializer->serialize(&initial, serialized, false)) {
		cerr << "Failed serializing" << endl;
		return -1;
	}
	string to_deserialize;
	to_deserialize.reserve(512);
	to_deserialize = serialized;
	start = steady_clock::now();

	for( int i=0; i<iterations; i++ ){
		Record final("key");
		if (!serializer->parse(to_deserialize, &final)) {
			cerr << "Failed parsing" << endl;
			return -1;
		}
		to_deserialize = serialized;
	}
	stop = steady_clock::now();
	duration_ms = DURATION_MS(start, stop);

	cout << "[DESERIALIZE] Duration of the " << iterations << " iterations: " << duration_ms << "ms" << endl;
	cout << "[DESERIALIZE] Performances: " << (float)iterations/(duration_ms/1000.0F) << " deserializations / s" << endl;
	cout << "[DESERIALIZE] Performances: " << (float)(duration_ms)/(float)iterations << "ms / deserialization" << endl;

	return 0;

}

SofiaHome home;

int main(int argc, char **argv) {
	int iterations = 0;

	if (argc < 2 || argc > 3) {
		cerr << "bad usage" << endl;
		cerr << argv[0] << " (protobuf|c|json|msgpack) [iterations]" << endl;
		exit(-1);
	}
	
	init_tests();
	auto serializer = unique_ptr<RecordSerializer>(RecordSerializer::create(argv[1]));
	if (!serializer) {
		cerr << "bad serializer" << argv[1] << endl;
		exit(-1);
	}

	if( argc == 3 ){
		iterations = atoi(argv[2]);
	}

	int expire_delta = 1000;
	list<string> paths{"path1", "path2", "path3"};
	string contactid{"192.168.0.1:5223"};
	string callid{"callid"};
	string line{"line"};
	string contact = "sip:" + contactid + ";line=" + line;
	string contactWithChev = "<" + contact + ">";
	uint32_t cseq = 123456;
	time_t now = time(NULL);
	time_t expireat = now + expire_delta;
	float quality = 1;
	bool alias = false;

	ExtendedContactCommon ecc(contactid.c_str(), paths, callid.c_str(), line.c_str());

	sip_contact_t *sip_contact =
		sip_contact_format(home.h, "<%s>;q=%f;expires=%d", contact.c_str(), quality, expire_delta);
	sip_path_t *sip_path = path_fromstl(home.h, paths);
	sip_accept_t *accept = NULL;

	if (test_bind_with_ecc(ecc, serializer, contact, expireat, quality, cseq, now, alias, accept)) {
		BAD("failure in bind with ecc");
	}

	if (test_bind_without_ecc(ecc, serializer, sip_contact, sip_path, 55555, callid.c_str(), contactWithChev.c_str(),
							  expireat, quality, cseq, now, alias, accept)) {
		BAD("failure in bind without ecc");
	}

	if( iterations != 0){
		test_performances_with_iterations(iterations, ecc, serializer, contact, expireat, quality, cseq, now, alias, accept);

	}
	cout << "success" << endl;
	return 0;
}
