#include "unit_test.h"

// ck_assert_int_eq(s21_from_int_to_decimal(15, NULL), 1);
START_TEST(s21_int_to_dec_1) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_from_int_to_decimal(0, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_int_to_dec_2) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("21", &res_check);
  ck_assert_int_eq(s21_from_int_to_decimal(21, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_int_to_dec_3) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-21", &res_check);
  ck_assert_int_eq(s21_from_int_to_decimal(-21, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_int_to_dec_4) {
  s21_decimal res;
  s21_decimal res_check = {0};
  str_to_decimal("2147483647", &res_check);
  res.bits[2] = 21;
  ck_assert_int_eq(s21_from_int_to_decimal(2147483647, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_int_to_dec_5) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-2147483647", &res_check);
  res.bits[3] = 21;
  ck_assert_int_eq(s21_from_int_to_decimal(-2147483647, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_int_to_dec_6) {
  s21_decimal res;
  s21_decimal res_check = {0};
  str_to_decimal("-21474", &res_check);
  ck_assert_int_eq(s21_from_int_to_decimal(-21474, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_int_to_dec_7) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-2147483648", &res_check);
  ck_assert_int_eq(s21_from_int_to_decimal(INT32_MIN, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

Suite *int_to_dec_suite(void) {
  Suite *suite = suite_create("s21_int_to_dec");
  TCase *tc_core = tcase_create("s21_int_to_dec");
  tcase_add_test(tc_core, s21_int_to_dec_1);
  tcase_add_test(tc_core, s21_int_to_dec_2);
  tcase_add_test(tc_core, s21_int_to_dec_3);
  tcase_add_test(tc_core, s21_int_to_dec_4);
  tcase_add_test(tc_core, s21_int_to_dec_5);
  tcase_add_test(tc_core, s21_int_to_dec_6);
  tcase_add_test(tc_core, s21_int_to_dec_7);

  suite_add_tcase(suite, tc_core);
  return suite;
}
