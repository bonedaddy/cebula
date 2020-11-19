add_library(nebulacert
    SHARED
        ${PROJECT_SOURCE_DIR}/cert/cert.pb.h
        ${PROJECT_SOURCE_DIR}/cert/cert.pb.c
)

target_compile_options(nebulacert PRIVATE ${flags})
target_link_libraries(nebulacert libnanopb)

add_executable(nebula-cert-test ${PROJECT_SOURCE_DIR}/cert/cert_test.c)
add_test(NAME NebulaCertTest COMMAND nebula-cert-test)
target_compile_options(nebula-cert-test PRIVATE ${flags})
target_link_libraries(nebula-cert-test nebulacert libnanopb cmocka)