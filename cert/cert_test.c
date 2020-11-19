#include <pb_encode.h>
#include <pb_decode.h>
#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "cert.pb.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

void test_encode_cert_RawNebulaCertificate(void **state) {
    uint8_t buffer[4096];
    size_t message_length;
    cert_RawNebulaCertificate message = cert_RawNebulaCertificate_init_zero;
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
    // message.Signature.funcs
    message.has_Details = true;
    cert_RawNebulaCertificateDetails details = {.IsCA = false, .NotAfter = 69, .NotBefore = 66};
    message.Details = details;
    bool status = pb_encode(&stream, cert_RawNebulaCertificate_fields, &message);
    message_length = stream.bytes_written;
    if (status == false) {
        printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
        assert(false == true);
    }
    printf("message size: %li\n", message_length);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_encode_cert_RawNebulaCertificate),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}