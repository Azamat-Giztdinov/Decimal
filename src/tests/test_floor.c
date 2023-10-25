#include "unit_test.h"

START_TEST(s21_floor_1) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1234567892134412", &dec_1);
  str_to_decimal("1234567892134412", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1234567892134412", &dec_1);
  str_to_decimal("-1234567892134412", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("123456.7892134412", &dec_1);
  str_to_decimal("123456", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal dec_1 = {0};
  s21_decimal res;
  s21_decimal res_check = {0};
  str_to_decimal("-123456.7892134412", &dec_1);
  str_to_decimal("-123457", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_5) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("79228162514264337593543950335", &dec_1);
  str_to_decimal("79228162514264337593543950335", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_6) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-79228162514264337593543950335", &dec_1);
  str_to_decimal("-79228162514264337593543950335", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_7) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-7.9228162514264337593543950335", &dec_1);
  str_to_decimal("-8", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_8) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("7.9228162514264337593543950335", &dec_1);
  str_to_decimal("7", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_9) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0", &dec_1);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_10) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0", &dec_1);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_11) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0.000000", &dec_1);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_12) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0.000000", &dec_1);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_floor_13) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0.0000001", &dec_1);
  str_to_decimal("-1", &res_check);
  ck_assert_int_eq(s21_floor(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

Suite *floor_suite(void) {
  Suite *suite = suite_create("s21_floor");
  TCase *tc_core = tcase_create("s21_floor");
  tcase_add_test(tc_core, s21_floor_1);
  tcase_add_test(tc_core, s21_floor_2);
  tcase_add_test(tc_core, s21_floor_3);
  tcase_add_test(tc_core, s21_floor_4);
  tcase_add_test(tc_core, s21_floor_5);
  tcase_add_test(tc_core, s21_floor_6);
  tcase_add_test(tc_core, s21_floor_7);
  tcase_add_test(tc_core, s21_floor_8);
  tcase_add_test(tc_core, s21_floor_9);
  tcase_add_test(tc_core, s21_floor_10);
  tcase_add_test(tc_core, s21_floor_11);
  tcase_add_test(tc_core, s21_floor_12);
  tcase_add_test(tc_core, s21_floor_13);

  suite_add_tcase(suite, tc_core);
  return suite;
}
