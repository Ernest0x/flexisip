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

// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // EventLogDb
  //

  inline
  access::object_traits< ::EventLogDb >::id_type
  access::object_traits< ::EventLogDb >::
  id (const object_type& o)
  {
    return o.id_;
  }

  inline
  void access::object_traits< ::EventLogDb >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::EventLogDb >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  // RegistrationLogDb
  //

  inline
  access::object_traits< ::RegistrationLogDb >::id_type
  access::object_traits< ::RegistrationLogDb >::
  id (const object_type& o)
  {
    return object_traits< ::EventLogDb >::id (o);
  }

  inline
  void access::object_traits< ::RegistrationLogDb >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::RegistrationLogDb >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  // CallLogDb
  //

  inline
  access::object_traits< ::CallLogDb >::id_type
  access::object_traits< ::CallLogDb >::
  id (const object_type& o)
  {
    return object_traits< ::EventLogDb >::id (o);
  }

  inline
  void access::object_traits< ::CallLogDb >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::CallLogDb >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  // MessageLogDb
  //

  inline
  access::object_traits< ::MessageLogDb >::id_type
  access::object_traits< ::MessageLogDb >::
  id (const object_type& o)
  {
    return object_traits< ::EventLogDb >::id (o);
  }

  inline
  void access::object_traits< ::MessageLogDb >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::MessageLogDb >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  // AuthLogDb
  //

  inline
  access::object_traits< ::AuthLogDb >::id_type
  access::object_traits< ::AuthLogDb >::
  id (const object_type& o)
  {
    return object_traits< ::EventLogDb >::id (o);
  }

  inline
  void access::object_traits< ::AuthLogDb >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::AuthLogDb >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  // CallQualityStatisticsLogDb
  //

  inline
  access::object_traits< ::CallQualityStatisticsLogDb >::id_type
  access::object_traits< ::CallQualityStatisticsLogDb >::
  id (const object_type& o)
  {
    return object_traits< ::EventLogDb >::id (o);
  }

  inline
  void access::object_traits< ::CallQualityStatisticsLogDb >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::CallQualityStatisticsLogDb >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }
}

#include <odb/details/unique-ptr.hxx>

namespace odb
{
  // EventLogDb
  //

  inline
  void access::object_traits_impl< ::EventLogDb, id_mysql >::
  load_ (statements_type& sts,
         object_type& obj,
         bool)
  {
    ODB_POTENTIALLY_UNUSED (sts);
    ODB_POTENTIALLY_UNUSED (obj);
  }

  // RegistrationLogDb
  //

  inline
  void access::object_traits_impl< ::RegistrationLogDb, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    object_traits_impl< ::EventLogDb, id_mysql >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::RegistrationLogDb, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::EventLogDb, id_mysql >::init (i, id);
  }

  inline
  bool access::object_traits_impl< ::RegistrationLogDb, id_mysql >::
  check_version (const std::size_t* v, const image_type& i)
  {
    return 
      v[0UL] != i.version ||
      v[1UL] != i.base->version;
  }

  inline
  void access::object_traits_impl< ::RegistrationLogDb, id_mysql >::
  update_version (std::size_t* v, const image_type& i, mysql::binding* b)
  {
    v[0UL] = i.version;
    v[1UL] = i.base->version;
    b[0UL].version++;
    b[1UL].version++;
  }

  // CallLogDb
  //

  inline
  void access::object_traits_impl< ::CallLogDb, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    object_traits_impl< ::EventLogDb, id_mysql >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::CallLogDb, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::EventLogDb, id_mysql >::init (i, id);
  }

  inline
  bool access::object_traits_impl< ::CallLogDb, id_mysql >::
  check_version (const std::size_t* v, const image_type& i)
  {
    return 
      v[0UL] != i.version ||
      v[1UL] != i.base->version;
  }

  inline
  void access::object_traits_impl< ::CallLogDb, id_mysql >::
  update_version (std::size_t* v, const image_type& i, mysql::binding* b)
  {
    v[0UL] = i.version;
    v[1UL] = i.base->version;
    b[0UL].version++;
    b[1UL].version++;
  }

  // MessageLogDb
  //

  inline
  void access::object_traits_impl< ::MessageLogDb, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    object_traits_impl< ::EventLogDb, id_mysql >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::MessageLogDb, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::EventLogDb, id_mysql >::init (i, id);
  }

  inline
  bool access::object_traits_impl< ::MessageLogDb, id_mysql >::
  check_version (const std::size_t* v, const image_type& i)
  {
    return 
      v[0UL] != i.version ||
      v[1UL] != i.base->version;
  }

  inline
  void access::object_traits_impl< ::MessageLogDb, id_mysql >::
  update_version (std::size_t* v, const image_type& i, mysql::binding* b)
  {
    v[0UL] = i.version;
    v[1UL] = i.base->version;
    b[0UL].version++;
    b[1UL].version++;
  }

  // AuthLogDb
  //

  inline
  void access::object_traits_impl< ::AuthLogDb, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    object_traits_impl< ::EventLogDb, id_mysql >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::AuthLogDb, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::EventLogDb, id_mysql >::init (i, id);
  }

  inline
  bool access::object_traits_impl< ::AuthLogDb, id_mysql >::
  check_version (const std::size_t* v, const image_type& i)
  {
    return 
      v[0UL] != i.version ||
      v[1UL] != i.base->version;
  }

  inline
  void access::object_traits_impl< ::AuthLogDb, id_mysql >::
  update_version (std::size_t* v, const image_type& i, mysql::binding* b)
  {
    v[0UL] = i.version;
    v[1UL] = i.base->version;
    b[0UL].version++;
    b[1UL].version++;
  }

  // reporting_addr
  //

  inline
  bool access::composite_value_traits< ::CallQualityStatisticsLogDb::reporting_addr, id_mysql >::
  get_null (const image_type& i)
  {
    bool r (true);
    r = r && i.id_null;
    r = r && i.ip_null;
    r = r && i.port_null;
    r = r && i.ssrc_null;
    r = r && i.group_null;
    r = r && i.mac_null;
    return r;
  }

  inline
  void access::composite_value_traits< ::CallQualityStatisticsLogDb::reporting_addr, id_mysql >::
  set_null (image_type& i,
            mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    i.id_null = 1;
    i.ip_null = 1;
    i.port_null = 1;
    i.ssrc_null = 1;
    i.group_null = 1;
    i.mac_null = 1;
  }

  // reporting_content_metrics
  //

  inline
  bool access::composite_value_traits< ::CallQualityStatisticsLogDb::reporting_content_metrics, id_mysql >::
  get_null (const image_type& i)
  {
    bool r (true);
    r = r && i.ts_start_null;
    r = r && i.ts_stop_null;
    r = r && i.sd_payload_type_null;
    r = r && i.sd_payload_desc_null;
    r = r && i.sd_sample_rate_null;
    r = r && i.sd_frame_duration_null;
    r = r && i.sd_fmtp_null;
    r = r && i.sd_packet_loss_concealment_null;
    r = r && i.jb_adaptive_null;
    r = r && i.jb_nominal_null;
    r = r && i.jb_max_null;
    r = r && i.jb_abs_max_null;
    r = r && i.pl_network_packet_loss_rate_null;
    r = r && i.pl_jitter_buffer_discard_rate_null;
    r = r && i.d_round_trip_delay_null;
    r = r && i.d_end_system_delay_null;
    r = r && i.d_symm_one_way_delay_null;
    r = r && i.d_interarrival_jitter_null;
    r = r && i.d_mean_abs_jitter_null;
    r = r && i.s_level_null;
    r = r && i.s_noise_level_null;
    r = r && i.qe_moslq_null;
    r = r && i.qe_moscq_null;
    r = r && i.user_agent_null;
    return r;
  }

  inline
  void access::composite_value_traits< ::CallQualityStatisticsLogDb::reporting_content_metrics, id_mysql >::
  set_null (image_type& i,
            mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    i.ts_start_null = 1;
    i.ts_stop_null = 1;
    i.sd_payload_type_null = 1;
    i.sd_payload_desc_null = 1;
    i.sd_sample_rate_null = 1;
    i.sd_frame_duration_null = 1;
    i.sd_fmtp_null = 1;
    i.sd_packet_loss_concealment_null = 1;
    i.jb_adaptive_null = 1;
    i.jb_nominal_null = 1;
    i.jb_max_null = 1;
    i.jb_abs_max_null = 1;
    i.pl_network_packet_loss_rate_null = 1;
    i.pl_jitter_buffer_discard_rate_null = 1;
    i.d_round_trip_delay_null = 1;
    i.d_end_system_delay_null = 1;
    i.d_symm_one_way_delay_null = 1;
    i.d_interarrival_jitter_null = 1;
    i.d_mean_abs_jitter_null = 1;
    i.s_level_null = 1;
    i.s_noise_level_null = 1;
    i.qe_moslq_null = 1;
    i.qe_moscq_null = 1;
    i.user_agent_null = 1;
  }

  // CallQualityStatisticsLogDb
  //

  inline
  void access::object_traits_impl< ::CallQualityStatisticsLogDb, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    object_traits_impl< ::EventLogDb, id_mysql >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::CallQualityStatisticsLogDb, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::EventLogDb, id_mysql >::init (i, id);
  }

  inline
  bool access::object_traits_impl< ::CallQualityStatisticsLogDb, id_mysql >::
  check_version (const std::size_t* v, const image_type& i)
  {
    return 
      v[0UL] != i.version ||
      v[1UL] != i.base->version;
  }

  inline
  void access::object_traits_impl< ::CallQualityStatisticsLogDb, id_mysql >::
  update_version (std::size_t* v, const image_type& i, mysql::binding* b)
  {
    v[0UL] = i.version;
    v[1UL] = i.base->version;
    b[0UL].version++;
    b[1UL].version++;
  }
}

