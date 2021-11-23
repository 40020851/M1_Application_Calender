#include "unity.h"
#include <calfunction.h>

/* Modify these two lines according to the project */
#include <calfunction.h>
#define PROJECT_NAME    "Billing System"

/* Prototypes for all the test functions */
void test_cal(void);


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_cal);


  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_cal(void) {
  TEST_ASSERT_EQUAL(day, open(day,month,year));
  TEST_ASSERT_EQUAL(day, open(day,month,year));
  TEST_ASSERT_EQUAL(day, open(day,month,year));
  TEST_ASSERT_EQUAL(day, open(day,month,year));
 
    /* Dummy fail*/
  // TEST_ASSERT_EQUAL(0, file does not exist);
  
}