/*******************************************************************************
 *   Ledger Platon App
 *   (c) 2016-2019 Ledger
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#ifndef _TOKENS_H_
#define _TOKENS_H_

#include <stdint.h>
#include "latUstream.h"

#define MAX_TICKER_LEN 12  // 10 characters + ' ' + '\0'

typedef struct tokenDefinition_t {
#ifdef HAVE_CONTRACT_NAME_IN_DESCRIPTOR
    uint8_t contractName[ADDRESS_LENGTH];
#endif
    uint8_t address[ADDRESS_LENGTH];
    char ticker[MAX_TICKER_LEN];
    uint8_t decimals;
} tokenDefinition_t;

#ifdef HAVE_TOKENS_EXTRA_LIST

#define NUM_TOKENS_EXTRA 4

extern tokenDefinition_t const TOKENS_EXTRA[NUM_TOKENS_EXTRA];

#endif

#ifndef HAVE_TOKENS_LIST

#ifndef LEDGER_TEST_PUBLIC_KEY
static const uint8_t LEDGER_SIGNATURE_PUBLIC_KEY[] = {
    // (prc20signer)
    0x04, 0x85, 0x2d, 0x1b, 0x4e, 0x57, 0xa2, 0x1e, 0xcc, 0x86, 0x9f, 0x3e, 0x30,
    0x84, 0x85, 0xe9, 0x50, 0x5b, 0xc5, 0x84, 0xe1, 0xd3, 0xd0, 0x86, 0xf6, 0x9f,
    0xac, 0x93, 0xde, 0x1e, 0x0f, 0xd2, 0xba, 0x0f, 0x32, 0xaf, 0x92, 0x33, 0x8d,
    0x27, 0x35, 0xfe, 0x75, 0x4f, 0xe1, 0xca, 0x88, 0x36, 0xc5, 0xc0, 0xe1, 0x4c,
    0xc4, 0xa6, 0xe0, 0x5b, 0x55, 0x99, 0xa5, 0xd7, 0xd6, 0x95, 0xfc, 0xdf, 0xb6,
};

#else
static const uint8_t LEDGER_SIGNATURE_PUBLIC_KEY[] = {
    // (prc20signer)
    0x04, 0x85, 0x2d, 0x1b, 0x4e, 0x57, 0xa2, 0x1e, 0xcc, 0x86, 0x9f, 0x3e, 0x30,
    0x84, 0x85, 0xe9, 0x50, 0x5b, 0xc5, 0x84, 0xe1, 0xd3, 0xd0, 0x86, 0xf6, 0x9f,
    0xac, 0x93, 0xde, 0x1e, 0x0f, 0xd2, 0xba, 0x0f, 0x32, 0xaf, 0x92, 0x33, 0x8d,
    0x27, 0x35, 0xfe, 0x75, 0x4f, 0xe1, 0xca, 0x88, 0x36, 0xc5, 0xc0, 0xe1, 0x4c,
    0xc4, 0xa6, 0xe0, 0x5b, 0x55, 0x99, 0xa5, 0xd7, 0xd6, 0x95, 0xfc, 0xdf, 0xb6,
};
#endif

#else

#define NUM_TOKENS_PLATON 1102

extern tokenDefinition_t const TOKENS_PLATON[NUM_TOKENS_PLATON];

#endif /* HAVE_TOKENS_LIST */

#endif /* _TOKENS_H_ */
