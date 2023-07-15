SECTIONS
{
    .data.test_cases :
    {
        test_cases_start = .;
        *(.data.test_cases)
        test_cases_end = .;
    }
}
INSERT AFTER .data;
