#include "unit_test.h"

START_TEST(s21_decimal_to_int_1) {
  s21_decimal dec = {0};
  int res = 0;
  int check = 0;
  char *check_str = "0";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_int(dec, &res), 0);
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(s21_decimal_to_int_2) {
  s21_decimal dec = {0};
  int res = 0;
  int check = 0;
  char *check_str = "0.00000013234";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_int(dec, &res), 0);
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(s21_decimal_to_int_3) {
  s21_decimal dec = {0};
  int res = 0;
  int check = INT32_MAX;
  char *check_str = "134244313224145";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_int(dec, &res), 1);
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(s21_decimal_to_int_4) {
  s21_decimal dec = {0};
  int res = 0;
  int check = -INT32_MAX;
  char *check_str = "-134244313224145";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_int(dec, &res), 1);
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(s21_decimal_to_int_5) {
  s21_decimal dec = {0};
  int res = 0;
  int check = 123;
  char *check_str = "123.321";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_int(dec, &res), 0);
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(s21_decimal_to_int_6) {
  s21_decimal dec = {0};
  int res;
  int check = -123312;
  char *check_str = "-123312";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_int(dec, &res), 0);
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(s21_decimal_to_int_7) {
  s21_decimal dec = {0};
  int res = -1;
  int check = 0;
  char *check_str = "-0";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_int(dec, &res), 0);
  ck_assert_int_eq(res, check);
}
END_TEST

Suite *decimal_to_int_suite(void) {
  Suite *suite = suite_create("s21_decimal_to_int");
  TCase *tc_core = tcase_create("s21_decimal_to_int");
  tcase_add_test(tc_core, s21_decimal_to_int_1);
  tcase_add_test(tc_core, s21_decimal_to_int_2);
  tcase_add_test(tc_core, s21_decimal_to_int_3);
  tcase_add_test(tc_core, s21_decimal_to_int_4);
  tcase_add_test(tc_core, s21_decimal_to_int_5);
  tcase_add_test(tc_core, s21_decimal_to_int_6);
  tcase_add_test(tc_core, s21_decimal_to_int_7);

  suite_add_tcase(suite, tc_core);
  return suite;
}
