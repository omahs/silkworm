/*
   Copyright 2022 The Silkworm Authors

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

#include <memory>
#include <string>

#include <silkworm/concurrency/coroutine.hpp>

#include <boost/asio/awaitable.hpp>

#include <silkworm/lightclient/ssz/beacon-chain/beacon_state.hpp>

namespace silkworm::cl {

//! \brief Get the beacon-chain state using checkpoint sync
boost::asio::awaitable<std::unique_ptr<eth::BeaconState>> retrieve_beacon_state(const std::string& checkpoint_uri);

}  // namespace silkworm::cl