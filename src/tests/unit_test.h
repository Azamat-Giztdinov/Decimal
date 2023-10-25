#ifndef TESTS_UNIT_TEST_H_
#define TESTS_UNIT_TEST_H_
#include <check.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

// int str_to_decimal_test(const char *str, s21_decimal *value);

// tests
Suite *comparing_suite(void);
Suite *add_suite(void);
Suite *dec_to_float_suite(void);
Suite *decimal_to_int_suite(void);
Suite *div_suite(void);
Suite *float_to_dec_suite(void);
Suite *floor_suite(void);
Suite *int_to_dec_suite(void);
Suite *mod_suite(void);
Suite *mul_suite(void);
Suite *negate_suite(void);
Suite *round_suite(void);
Suite *sub_suite(void);
Suite *truncate_suite(void);

#endif  // TESTS_UNIT_TEST_H_