/*
   Copyright 2014-2015 Stanislav Ovsyannikov

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

	   Unless required by applicable law or agreed to in writing, software
	   distributed under the License is distributed on an "AS IS" BASIS,
	   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	   See the License for the specific language governing permissions and
	   limitations under the License.
*/

#pragma once

#include <vector>

#include <silkworm/silkrpc/common/log.hpp>
#include <silkworm/silkrpc/json/types.hpp>

#include <cbor/listener.h>

namespace silkrpc {

    class listener_cbor_log : public cbor::listener {
    private:
        typedef enum { WAIT_NLOGS,  WAIT_NFIELDS, WAIT_ADDRESS, WAIT_NTOPICS, WAIT_TOPICS, WAIT_DATA} state;
    public:
        listener_cbor_log (std::vector<Log>& logs): state_(WAIT_NLOGS), nlogs_(0), ntopics_(0), logs_(logs) {}
        void on_integer(int value) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(integer)"}; }
        void on_map(int size) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(map)"}; }
        void on_string(std::string &str) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(string)"}; }
        void on_tag(unsigned int tag) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(tag)"}; }
        void on_undefined() { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(undefined)"}; }
        void on_extra_integer(unsigned long long value, int sign) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(extra integer)"}; }
        void on_bool(bool) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(bool)"}; }
        void on_extra_tag(unsigned long long tag) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(extra_tag)"}; }
        void on_float32(float value) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(float)"}; }
        void on_double(double value) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(double)"}; }
        void on_extra_special(unsigned long long tag) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(extra_special)"}; }
        void on_error(const char *error) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(on_error)"}; }
        void on_special(unsigned int code) { throw std::system_error{std::make_error_code(std::errc::invalid_argument), "Log CBOR: unexpected format(special)"}; }

        bool is_processing_terminated_successfully();

        std::vector<Log>& get_log()  { return logs_; }

        void on_bytes(unsigned char *data, int size);
        void on_array(int size);
        void on_null();
 
    private:
        std::vector<Log>& logs_;
        Log curr_log_;

        int nlogs_;
        int ntopics_;
        int curr_topics_;
        state state_;
    };
}
