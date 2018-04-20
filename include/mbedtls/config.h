/*
// Copyright (c) 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#ifndef MBEDTLS_CONFIG_H
#define MBEDTLS_CONFIG_H

#include <config.h>
#include "port/oc_connectivity.h"
#include "port/oc_assert.h"

/* System support */
#define MBEDTLS_PLATFORM_C
#define MBEDTLS_PLATFORM_MEMORY

#ifdef OC_DYNAMIC_ALLOCATION
#include <stdlib.h>
#define MBEDTLS_PLATFORM_STD_CALLOC calloc
#define MBEDTLS_PLATFORM_STD_FREE free
#else /* OC_DYNAMIC_ALLOCATION */
#define MBEDTLS_MEMORY_BUFFER_ALLOC_C
#endif /* !OC_DYNAMIC_ALLOCATION */

#define MBEDTLS_PLATFORM_EXIT_ALT
#define MBEDTLS_PLATFORM_STD_EXIT oc_exit
#define MBEDTLS_PLATFORM_NO_STD_FUNCTIONS

/* mbed TLS feature support */
#define MBEDTLS_KEY_EXCHANGE_PSK_ENABLED
#define MBEDTLS_SSL_MAX_FRAGMENT_LENGTH
#define MBEDTLS_SSL_PROTO_TLS1_2
#define MBEDTLS_SSL_PROTO_DTLS
#define MBEDTLS_SSL_DTLS_ANTI_REPLAY
#define MBEDTLS_SSL_DTLS_HELLO_VERIFY


/* mbed TLS modules */
#define MBEDTLS_AES_C
#define MBEDTLS_CIPHER_C
#define MBEDTLS_CTR_DRBG_C
#define MBEDTLS_ENTROPY_C
#define MBEDTLS_MD_C
#define MBEDTLS_SHA256_C
#define MBEDTLS_SSL_COOKIE_C
#define MBEDTLS_SSL_CLI_C
#define MBEDTLS_SSL_SRV_C
#define MBEDTLS_SSL_TLS_C

/* Save RAM at the expense of ROM */
#define MBEDTLS_AES_ROM_TABLES

/* Save some RAM by adjusting to your exact needs */
#define MBEDTLS_PSK_MAX_LEN    16 /* 128-bits keys are generally enough */

/*
 * You should adjust this to the exact number of sources you're using: default
 * is the "platform_entropy_poll" source, but you may want to add other ones
 * Minimum is 2 for the entropy test suite.
 */
#define MBEDTLS_ENTROPY_MAX_SOURCES 2

#define MBEDTLS_SSL_BUFFER_MIN 512

#define MBEDTLS_ECP_DP_SECP256R1_ENABLED
#define MBEDTLS_ECP_C
#define MBEDTLS_BIGNUM_C
#define MBEDTLS_KEY_EXCHANGE_ECDH_ANON_ENABLED
#define MBEDTLS_ECDH_C
#define MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED
#define MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED
#define MBEDTLS_RSA_C
#define MBEDTLS_PKCS1_V15
#define MBEDTLS_X509_CRT_PARSE_C

#define MBEDTLS_X509_USE_C

#define MBEDTLS_ASN1_PARSE_C
#define MBEDTLS_OID_C
#define MBEDTLS_PK_PARSE_C
#define MBEDTLS_PK_C

#define MBEDTLS_CIPHER_MODE_CBC

#define MBEDTLS_SSL_SRV_RESPECT_CLIENT_PREFERENCE

#define MBEDTLS_SSL_EXTENDED_MASTER_SECRET
#define MBEDTLS_SSL_ALL_ALERT_MESSAGES

#ifdef OC_DEBUG
#define MBEDTLS_ERROR_C
#define MBEDTLS_DEBUG_C
#endif /* OC_DEBUG */

#include "mbedtls/check_config.h"

#endif /* MBEDTLS_CONFIG_H */
