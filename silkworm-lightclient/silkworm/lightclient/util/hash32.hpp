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

// TODO(canepat) this file should be moved in silkworm-core

#pragma once

#include <cstdint>
#include <vector>

#include <evmc/evmc.hpp>

namespace silkworm {

//! 32-byte hash value
using Hash32 = evmc::bytes32;

//! Sequence of 32-byte hash values
using Hash32Sequence = std::vector<Hash32>;

}  // namespace silkworm