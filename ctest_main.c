#include "ctest.h"
#include "unity_internals.h"
#include <stddef.h>

extern size_t test_cases_start[];
extern size_t test_cases_end[];

void setUp(void) {}
void tearDown(void) {}

void run_test(test_case_t *test_case, const size_t line)
{
    UnityTestFunction Func = test_case->test;
    UnitySetTestFile(test_case->file_name);

    Unity.CurrentTestName = test_case->name;
    Unity.CurrentTestLineNumber = (UNITY_LINE_TYPE)line;
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    if (TEST_PROTECT())
    {
        setUp();
        Func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
    }
    UNITY_EXEC_TIME_STOP();
    UnitySetTestFile(__FILE__);
    UnityConcludeTest();
}

int main(int argc, char **argv)
{
    test_case_t *test_case = (test_case_t *)test_cases_start;
    while (test_case < (test_case_t *)test_cases_end) {
        run_test(test_case++, __LINE__);
    }
}
