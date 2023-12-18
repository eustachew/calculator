/*
 * Program to test the calculator program 
 */
#include <stdio.h>
#include <stdbool.h>

#include "calc.h"

#define NUM_TESTS 10

struct pair{
  char* expression;
  int result;
};

struct pair input_output_pairs[NUM_TESTS] = {
  // TODO
  {.expression = "10/((0-5)/(0-4))", .result = 10},
  {.expression = "(0-3)/2", .result = -1},
  {.expression = "(3+2)*2", .result = 10},
  {.expression = "2/2/2", .result = 0},
  {.expression = "2*(15/3)", .result = 10},
  {.expression = "3+2*5", .result = 13},
  {.expression = "(0-3)*2", .result = -6},
  {.expression = "(0-3)*(0-2)", .result = 6},
  {.expression = "(0-3)/((0-2))", .result = 1},
  {.expression = "4/((1-3)/(0-1))", .result = 2}
};

// Given the index of an input-output pair, run the test on the username
// validator. Returns true if the tests passes, false otherwise.
bool run_test(int test_num) {
  char* test_expression = input_output_pairs[test_num].expression;
  int expected_answer = input_output_pairs[test_num].result;
  int actual_answer = calc(test_expression);
  if(expected_answer != actual_answer){
    printf("Test %d failed! Expected %s to be %d, but instead got %d\n", test_num + 1, test_expression, expected_answer, actual_answer);
    return false;
  }
  return true;
}

int main(int argc, char **argv) {
  int num_passed = 0;
  for(int i = 0; i < NUM_TESTS; i++) {
    if(run_test(i))
      num_passed++;
  }
  printf("%i out of %i tests passed.\n", num_passed, NUM_TESTS);
}
