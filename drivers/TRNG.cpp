/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "platform/mbed_assert.h"
#include "TRNG.h"

#if DEVICE_TRNG

namespace mbed {
    
const char TRNG::_hexChars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

TRNG::TRNG()
{
    trng_init(&_trng);
}

TRNG::~TRNG()
{
    trng_free(&_trng);
}

void TRNG::GetString(std::string& str, const uint32_t& len)
{
    uint8_t* buffer = NewRndBuf(len);
    str.clear();
    for (uint32_t i = 0; i < len; ++i) {
        str += _hexChars[buffer[i] >> 4];
        str += _hexChars[buffer[i] & 0x0F];
    }
    DeleteRndBuf(buffer);
}

uint8_t* TRNG::NewRndBuf(const uint32_t& len)
{
    size_t output_length;
    uint8_t* buffer = new uint8_t[len];
    trng_get_bytes(&_trng, buffer, len, &output_length);
    return buffer;
}

void TRNG::DeleteRndBuf(uint8_t* buf)
{
    delete buf;
}

} // namespace mbed

#endif
