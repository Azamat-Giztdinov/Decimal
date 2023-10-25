#include "unit_test.h"

START_TEST(s21_dec_to_float_1) {
  s21_decimal dec = {0};
  float res = 0;
  float check = 112432.1F;
  char *check_str = "112432.1";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_float(dec, &res), 0);
  ck_assert_float_eq_tol(check, res, 1e-7);
}
END_TEST

START_TEST(s21_dec_to_float_2) {
  s21_decimal dec = {0};
  float res = 0;
  float check = 1234567000000000000.0F;
  char *check_str = "1234567000000000000";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_float(dec, &res), 0);
  ck_assert_float_eq_tol(check, res, 1e-7);
}
END_TEST

START_TEST(s21_dec_to_float_3) {
  s21_decimal dec = {0};
  float res = 0;
  float check = 0.123123F;
  char *check_str = "0.123123";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_float(dec, &res), 0);
  ck_assert_float_eq_tol(check, res, 1e-7);
}
END_TEST

START_TEST(s21_dec_to_float_4) {
  s21_decimal dec = {0};
  float res = 0;
  float check = 0.0000123123F;
  char *check_str = "0.0000123123";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_float(dec, &res), 0);
  ck_assert_float_eq_tol(check, res, 1e-7);
}
END_TEST

START_TEST(s21_dec_to_float_5) {
  s21_decimal dec = {0};
  float res = 0;
  float check = 0.000001F;
  char *check_str = "0.000001";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_float(dec, &res), 0);
  ck_assert_float_eq_tol(check, res, 1e-7);
}
END_TEST

START_TEST(s21_dec_to_float_6) {
  s21_decimal dec = {0};
  float res = 0;
  float check = 0.0000010005F;
  char *check_str = "0.0000010005";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_float(dec, &res), 0);
  ck_assert_float_eq_tol(check, res, 1e-7);
}
END_TEST

START_TEST(s21_dec_to_float_7) {
  s21_decimal dec = {0};
  float res = 0;
  float check = 0.000001000546F;
  char *check_str = "0.0000010005456789";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_float(dec, &res), 0);
  ck_assert_float_eq_tol(check, res, 1e-7);
}
END_TEST

START_TEST(s21_dec_to_float_8) {
  s21_decimal dec = {0};
  float res = 0;
  float check = 1.000001F;
  char *check_str = "1.0000010005456789";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_float(dec, &res), 0);
  ck_assert_float_eq_tol(check, res, 1e-7);
}
END_TEST

START_TEST(s21_dec_to_float_9) {
  s21_decimal dec = {0};
  float res = 0.0;
  float check = 0.0F;
  char *check_str = "-0.0000";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_float(dec, &res), 0);
  ck_assert_float_eq_tol(check, res, 1e-7);
}
END_TEST

START_TEST(s21_dec_to_float_10) {
  s21_decimal dec = {0};
  float res;
  float check = -0.123123F;
  char *check_str = "-0.123123";
  str_to_decimal(check_str, &dec);
  ck_assert_int_eq(s21_from_decimal_to_float(dec, &res), 0);
  ck_assert_float_eq_tol(check, res, 1e-7);
}
END_TEST

Suite *dec_to_float_suite(void) {
  Suite *suite = suite_create("s21_decimal_to_float");
  TCase *tc_core = tcase_create("s21_decimal_to_float");
  tcase_add_test(tc_core, s21_dec_to_float_1);
  tcase_add_test(tc_core, s21_dec_to_float_2);
  tcase_add_test(tc_core, s21_dec_to_float_3);
  tcase_add_test(tc_core, s21_dec_to_float_4);
  tcase_add_test(tc_core, s21_dec_to_float_5);
  tcase_add_test(tc_core, s21_dec_to_float_6);
  tcase_add_test(tc_core, s21_dec_to_float_7);
  tcase_add_test(tc_core, s21_dec_to_float_8);
  tcase_add_test(tc_core, s21_dec_to_float_9);
  tcase_add_test(tc_core, s21_dec_to_float_10);

  suite_add_tcase(suite, tc_core);
  return suite;
}