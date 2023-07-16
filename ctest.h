#ifndef TEST_H
#define TEST_H

#include "unity.h"
typedef struct __attribute__((packed)) {
    void (*test)(void);
    const char *name;
    const char *file_name;
} test_case_t;

#define TEST(test_function)                                             \
    void test_function(void);                                           \
    __attribute__((section(".data.test_cases"), unused))                \
    static test_case_t test_function##_case = {                                 \
        .test = test_function,                                          \
        .name = #test_function,                                         \
        .file_name = __FILE__                                           \
    };                                                                  \
    void test_function(void)

#endif
