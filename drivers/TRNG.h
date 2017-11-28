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
#ifndef MBED_TRNG_H
#define MBED_TRNG_H

#include "platform/platform.h"

#if defined(DEVICE_TRNG) || defined(DOXYGEN_ONLY)

#include <string>
#include <vector>
#include "hal/trng_api.h"
#include "platform/NonCopyable.h"

namespace mbed {
/** \addtogroup drivers */

class TRNG : private NonCopyable<TRNG> {
public:
    typedef std::vector<uint8_t> trng_byte_array_t;
    typedef std::vector<uint16_t> trng_word_array_t;
    typedef std::vector<uint32_t> trng_dword_array_t;
    typedef std::vector<uint64_t> trng_qword_array_t;
    
    TRNG();
    virtual ~TRNG();
    
    operator uint8_t() const;
    operator uint16_t() const;
    operator uint32_t() const;
    operator uint64_t() const;
    
    
    
    
private:
    trng_t _trng;
    
};
    
    
} // namespace mbed

#endif

#endif
