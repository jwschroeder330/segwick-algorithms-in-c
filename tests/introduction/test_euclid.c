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
    CU_ASSERT_TRUE(CU_TRUE);
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