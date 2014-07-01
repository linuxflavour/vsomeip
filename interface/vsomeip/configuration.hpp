// Copyright (C) 2014 BMW Group
// Author: Lutz Bichler (lutz.bichler@bmw.de)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef VSOMEIP_CONFIGURATION_HPP
#define VSOMEIP_CONFIGURATION_HPP

#include <set>
#include <string>

#include <boost/asio/ip/address.hpp>
#include <boost/log/trivial.hpp>

#include <vsomeip/defines.hpp>
#include <vsomeip/primitive_types.hpp>

namespace vsomeip {

class configuration {
public:
	static configuration * get(const std::string &_path = VSOMEIP_DEFAULT_CONFIGURATION_FILE_PATH);
	virtual ~configuration() {};

	virtual bool load(const std::string &_path) = 0;

	virtual const boost::asio::ip::address & get_address() const = 0;
	virtual bool is_v4() const = 0;
	virtual bool is_v6() const = 0;

	virtual bool has_console_log() const = 0;
	virtual bool has_file_log() const = 0;
	virtual bool has_dlt_log() const = 0;
	virtual const std::string & get_logfile() const = 0;
	virtual boost::log::trivial::severity_level get_loglevel() const = 0;

	virtual const std::string & get_routing_host() const = 0;

	virtual bool is_service_discovery_enabled() const = 0;
	virtual const std::string & get_service_discovery_host() const = 0;
	virtual const std::string & get_service_discovery_protocol() const = 0;
	virtual uint16_t get_service_discovery_port() const = 0;

	virtual std::string get_address(service_t _service, instance_t _instance) const = 0;

	virtual uint32_t get_min_initial_delay(service_t _service, instance_t _instance) const = 0;
	virtual uint32_t get_max_initial_delay(service_t _service, instance_t _instance) const = 0;

	virtual uint32_t get_repetition_base_delay(service_t _service, instance_t _instance) const = 0;
	virtual uint8_t get_repetition_max(service_t _service, instance_t _instance) const = 0;

	virtual uint32_t get_cyclic_offer_delay(service_t _service, instance_t _instance) const = 0;
	virtual uint32_t get_cyclic_request_delay(service_t _service, instance_t _instance) const = 0;

	virtual uint16_t get_reliable_port(service_t _service, instance_t _instance) const = 0;
	virtual uint16_t get_unreliable_port(service_t _service, instance_t _instance) const = 0;
	virtual std::string get_multicast(service_t _service, instance_t _instance) const = 0;

	virtual std::set< std::pair< service_t, instance_t > > get_remote_services() const = 0;

	virtual client_t get_id(const std::string &_name) const = 0;
};

} // namespace vsomeip

#endif // VSOMEIP_CONFIGURATION_HPP