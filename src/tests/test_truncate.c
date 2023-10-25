#include "unit_test.h"

START_TEST(s21_truncate_1) {
  s21_decimal dec = {0};
  s21_decimal result;
  s21_decimal check = {0};
  char *str = "1.0000010005456789";
  char *check_str = "1";
  str_to_decimal(str, &dec);
  str_to_decimal(check_str, &check);
  ck_assert_int_eq(s21_truncate(dec, &result), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal dec = {0};
  s21_decimal result = {0};
  s21_decimal check = {0};
  char *str = "-132432432443.3423434432";
  char *check_str = "-132432432443";
  str_to_decimal(str, &dec);
  str_to_decimal(check_str, &check);
  ck_assert_int_eq(s21_truncate(dec, &result), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal dec = {0};
  s21_decimal result = {0};
  s21_decimal check = {0};
  char *str = "0.000000021344231";
  char *check_str = "0";
  str_to_decimal(str, &dec);
  str_to_decimal(check_str, &check);
  ck_assert_int_eq(s21_truncate(dec, &result), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(s21_truncate_4) {
  s21_decimal dec = {0};
  s21_decimal result = {0};
  s21_decimal check = {0};
  char *str = "123123.123430000000";
  char *check_str = "123123";
  str_to_decimal(str, &dec);
  str_to_decimal(check_str, &check);
  ck_assert_int_eq(s21_truncate(dec, &result), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(s21_truncate_5) {
  s21_decimal dec = {0};
  s21_decimal result = {0};
  s21_decimal check = {0};
  char *str = "7.9228162514264337593543950335";
  char *check_str = "7";
  str_to_decimal(str, &dec);
  str_to_decimal(check_str, &check);
  ck_assert_int_eq(s21_truncate(dec, &result), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal dec = {0};
  s21_decimal result = {0};
  s21_decimal check = {0};
  char *str = "-7.9228162514264337593543950335";
  char *check_str = "-7";
  str_to_decimal(str, &dec);
  str_to_decimal(check_str, &check);
  ck_assert_int_eq(s21_truncate(dec, &result), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(s21_truncate_7) {
  s21_decimal dec = {0};
  s21_decimal result = {0};
  s21_decimal check = {0};
  char *str = "-0.000000021344231";
  char *check_str = "0";
  str_to_decimal(str, &dec);
  str_to_decimal(check_str, &check);
  ck_assert_int_eq(s21_truncate(dec, &result), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], check.bits[i]);
  }
}
END_TEST

Suite *truncate_suite(void) {
  Suite *suite = suite_create("s21_truncate");
  TCase *tc_core = tcase_create("s21_truncate");
  tcase_add_test(tc_core, s21_truncate_1);
  tcase_add_test(tc_core, s21_truncate_2);
  tcase_add_test(tc_core, s21_truncate_3);
  tcase_add_test(tc_core, s21_truncate_4);
  tcase_add_test(tc_core, s21_truncate_5);
  tcase_add_test(tc_core, s21_truncate_6);
  tcase_add_test(tc_core, s21_truncate_7);

  suite_add_tcase(suite, tc_core);
  return suite;
}
