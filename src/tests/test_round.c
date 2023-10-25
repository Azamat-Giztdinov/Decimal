#include "unit_test.h"

START_TEST(s21_round_1) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1234567892134412", &dec_1);
  str_to_decimal("1234567892134412", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1234567892134412", &dec_1);
  str_to_decimal("-1234567892134412", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal dec_1 = {0};
  s21_decimal res;
  s21_decimal res_check = {0};
  str_to_decimal("123456.7892134412", &dec_1);
  str_to_decimal("123457", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-123456.7892134412", &dec_1);
  str_to_decimal("-123457", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("79228162514264337593543950335", &dec_1);
  str_to_decimal("79228162514264337593543950335", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-79228162514264337593543950335", &dec_1);
  str_to_decimal("-79228162514264337593543950335", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-7.9228162514264337593543950335", &dec_1);
  str_to_decimal("-8", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("7.9228162514264337593543950335", &dec_1);
  str_to_decimal("8", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_9) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0", &dec_1);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_10) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0", &dec_1);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_11) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0.000000", &dec_1);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0.000000", &dec_1);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_13) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0.0000001", &dec_1);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_14) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0.500000", &dec_1);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_15) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0.500000", &dec_1);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_16) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0.500001", &dec_1);
  str_to_decimal("1", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_17) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0.500001", &dec_1);
  str_to_decimal("-1", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_18) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("7922816251426433759354395033.5", &dec_1);
  str_to_decimal("7922816251426433759354395034", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_19) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("7922816251426433759354395032.5", &dec_1);
  str_to_decimal("7922816251426433759354395032", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_20) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-7922816251426433759354395032.5", &dec_1);
  str_to_decimal("-7922816251426433759354395032", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_21) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-7922816251426433759354395033.5", &dec_1);
  str_to_decimal("-7922816251426433759354395034", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_22) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-79228162514.5000001", &dec_1);
  str_to_decimal("-79228162515", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_round_23) {
  s21_decimal dec_1 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("79228162514.5000001", &dec_1);
  str_to_decimal("79228162515", &res_check);
  ck_assert_int_eq(s21_round(dec_1, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

Suite *round_suite(void) {
  Suite *suite = suite_create("s21_round");
  TCase *tc_core = tcase_create("s21_round");
  tcase_add_test(tc_core, s21_round_1);
  tcase_add_test(tc_core, s21_round_2);
  tcase_add_test(tc_core, s21_round_3);
  tcase_add_test(tc_core, s21_round_4);
  tcase_add_test(tc_core, s21_round_5);
  tcase_add_test(tc_core, s21_round_6);
  tcase_add_test(tc_core, s21_round_7);
  tcase_add_test(tc_core, s21_round_8);
  tcase_add_test(tc_core, s21_round_9);
  tcase_add_test(tc_core, s21_round_10);
  tcase_add_test(tc_core, s21_round_11);
  tcase_add_test(tc_core, s21_round_12);
  tcase_add_test(tc_core, s21_round_13);
  tcase_add_test(tc_core, s21_round_14);
  tcase_add_test(tc_core, s21_round_15);
  tcase_add_test(tc_core, s21_round_16);
  tcase_add_test(tc_core, s21_round_17);
  tcase_add_test(tc_core, s21_round_18);
  tcase_add_test(tc_core, s21_round_19);
  tcase_add_test(tc_core, s21_round_20);
  tcase_add_test(tc_core, s21_round_21);
  tcase_add_test(tc_core, s21_round_22);
  tcase_add_test(tc_core, s21_round_23);
  // tcase_add_test(tc_core, s21_round_14);

  suite_add_tcase(suite, tc_core);
  return suite;
}
