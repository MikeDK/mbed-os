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
    TRNG();
    virtual ~TRNG();
    
    template <typename T> operator T ()
    {
        T ret;
        size_t output_length;
        trng_get_bytes(&_trng, (uint8_t*)&ret, sizeof(ret), &output_length);
        return ret;
    }
    operator bool()
    {
        uint8_t ret;
        size_t output_length;
        trng_get_bytes(&_trng, (uint8_t*)&ret, 1, &output_length);
        return (ret % 2);
    }
    template <typename T> void GetVectorArray(std::vector<T> &array, const uint32_t& len)
    {
        T* buffer = (T*)NewRndBuf(len * sizeof(T));
        array.clear();
        for (uint32_t i = 0; i < len; ++i)
        {
            array.push_back(buffer[i]);
        }
        delete buffer;
    }
    template <typename T> void GetDataArray(T *array, const uint32_t& len)
    {
        size_t output_length;
        trng_get_bytes(&_trng, (uint8_t*)array, len * sizeof(T), &output_length);
    }

    void GetString(std::string& str, const uint32_t& len);

private:
    uint8_t* NewRndBuf(const uint32_t& len);
    void DeleteRndBuf(uint8_t* buf);

    trng_t _trng;    
    static const char _hexChars[16];
};
    
    
} // namespace mbed

#endif

#endif
