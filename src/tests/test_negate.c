#include "unit_test.h"

START_TEST(s21_negate_1) {
  s21_decimal dec1 = {0};
  s21_decimal res;
  s21_decimal resCheck = {0};
  str_to_decimal("21345632453142323212432", &dec1);
  str_to_decimal("-21345632453142323212432", &resCheck);
  ck_assert_int_eq(s21_negate(dec1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal dec1 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  str_to_decimal("-21345632453142323212432", &dec1);
  str_to_decimal("21345632453142323212432", &resCheck);
  ck_assert_int_eq(s21_negate(dec1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_negate_3) {
  s21_decimal dec1 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  str_to_decimal("-0", &dec1);
  str_to_decimal("0", &resCheck);
  ck_assert_int_eq(s21_negate(dec1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_negate_4) {
  s21_decimal dec1 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  str_to_decimal("0", &dec1);
  str_to_decimal("-0", &resCheck);
  ck_assert_int_eq(s21_negate(dec1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_negate_5) {
  s21_decimal dec1 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  str_to_decimal("21", &dec1);
  str_to_decimal("-21", &resCheck);
  ck_assert_int_eq(s21_negate(dec1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_negate_6) {
  s21_decimal dec1 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  str_to_decimal("-21", &dec1);
  str_to_decimal("21", &resCheck);
  ck_assert_int_eq(s21_negate(dec1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

Suite *negate_suite(void) {
  Suite *suite = suite_create("s21_negate");
  TCase *tc_core = tcase_create("s21_negate");
  tcase_add_test(tc_core, s21_negate_1);
  tcase_add_test(tc_core, s21_negate_2);
  tcase_add_test(tc_core, s21_negate_3);
  tcase_add_test(tc_core, s21_negate_4);
  tcase_add_test(tc_core, s21_negate_5);
  tcase_add_test(tc_core, s21_negate_6);

  suite_add_tcase(suite, tc_core);
  return suite;
}
