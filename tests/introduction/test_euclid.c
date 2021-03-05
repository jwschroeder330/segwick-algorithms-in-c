#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>

#include "../../src/introduction/euclid.h"


int init_suite(void)
{
    return EXIT_SUCCESS;
}

int clean_suite(void) 
{
    return EXIT_SUCCESS;
}

void test_case_both_positive(void) 
{
    CU_ASSERT_TRUE(gcd(8, 12) == 4);
    CU_ASSERT_TRUE(gcd(12, 8) == 4);
    CU_ASSERT_TRUE(gcd(7539, 421) == 1);
    CU_ASSERT_TRUE(gcd(421, 7539) == 1);
}

void test_case_one_arg_is_zero(void) 
{
    CU_ASSERT_TRUE(gcd(0, 3) == -1);
    CU_ASSERT_TRUE(gcd(3, 0) == -1);
}

void test_case_both_arg_are_zero(void)
{
    CU_ASSERT_TRUE(gcd(0, 0) == -1);
}


void test_case_one_arg_is_negative(void)
{
    CU_ASSERT_TRUE(gcd(-1, 3) == -1);
    CU_ASSERT_TRUE(gcd(3, -1) == -1);
}


void test_case_to_lowest_terms_base(void) 
{
    Fraction x;
    x.numerator = 4;
    x.denominator = 8;
    Fraction y = toLowestTerms(x);
    CU_ASSERT_TRUE(y.numerator == 1);
    CU_ASSERT_TRUE(y.denominator == 2);
}

void test_case_to_lowest_terms_do_nothing(void) 
{
    Fraction x;
    x.numerator = 1;
    x.denominator = 2;
    Fraction y = toLowestTerms(x);
    CU_ASSERT_TRUE(y.numerator == 1);
    CU_ASSERT_TRUE(y.denominator == 2);
}


void test_case_to_lowest_terms_failure(void) 
{
    Fraction x;
    x.numerator = 0;
    x.denominator = 2;
    Fraction y = toLowestTerms(x);
    CU_ASSERT_TRUE(y.numerator == 0);
    CU_ASSERT_TRUE(y.denominator == 2);
}


void test_case_to_binary_base(void) 
{
    int x = 9;
    char * xBinary = toBinary(x);
    CU_ASSERT_TRUE(strcmp(xBinary, "1001") == 0);
}



int main (void) 
{
    CU_pSuite suite = NULL;
    if ( CUE_SUCCESS != CU_initialize_registry() ) {
        return CU_get_error();
    }


    suite = CU_add_suite("euclid_suite", init_suite, clean_suite);

    if (suite == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // add each test to the suite and check for issues
    if (NULL == CU_add_test(suite, "test_case_both_positive", test_case_both_positive)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(suite, "test_case_one_arg_is_zero", test_case_one_arg_is_zero)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(suite, "test_case_both_arg_are_zero", test_case_both_arg_are_zero)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(suite, "test_case_one_arg_is_negative", test_case_one_arg_is_negative)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(suite, "test_case_to_lowest_terms_base", test_case_to_lowest_terms_base)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(suite, "test_case_to_lowest_terms_do_nothing", test_case_to_lowest_terms_do_nothing)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(suite, "test_case_to_lowest_terms_failure", test_case_to_lowest_terms_failure)) {
        CU_cleanup_registry();
        return CU_get_error();
    } 
    if (NULL == CU_add_test(suite, "test_case_to_binary_base", test_case_to_binary_base)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");
   /*
   // Run all tests using the automated interface
   CU_automated_run_tests();
   CU_list_tests_to_file();

   // Run all tests using the console interface
   CU_console_run_tests();
   */
   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}