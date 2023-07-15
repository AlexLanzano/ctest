# Ctest

Ctest is a wrapper around the Unity C testing framework. It provides a
main function that will automagically run all the tests cases you
define with the provided TEST(test_function) macro.

## How it works

When you use the TEST(test_function) macro it will append a function
pointer of your test case to a specific section in memory
(.data.test_cases) at link time.

Then, the main function will loop through this section of memory,
passing the function pointer to the Unity test framework to run the
test.
