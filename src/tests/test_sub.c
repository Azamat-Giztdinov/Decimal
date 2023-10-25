#include "unit_test.h"

// #define size 36
START_TEST(s21_sub_1) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-0";
  char *b = "0";
  char *sumRes = "0";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_2) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "0";
  char *b = "-0";
  char *sumRes = "0";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_3) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-0";
  char *b = "-0";
  char *sumRes = "0";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_4) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "0";
  char *b = "0";
  char *sumRes = "0";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_5) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "79228162514264337593543950335";
  char *b = "-0.6";
  char *sumRes = "79228162514264337593543950334";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_6) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "7.9228162514264337593543950335";
  char *b = "-0.6";
  char *sumRes = "8.522816251426433759354395034";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_7) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "79228162514264337593543950335";
  char *b = "0";
  char *sumRes = "79228162514264337593543950335";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_8) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res;
  s21_decimal resCheck = {0};
  char *a = "-7.9228162514264337593543950335";
  char *b = "-2544543534465.1";
  char *sumRes = "2544543534457.1771837485735662";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_9) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-7.9228162514264337593543950335";
  char *b = "2544543534465.1";
  char *sumRes = "-2544543534473.0228162514264338";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_10) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  char *a = "79228162514264337593543950335";
  char *b = "79228162514264337593543950335";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  int result = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_sub_11) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  char *a = "-79228162514264337593543950335";
  char *b = "-79228162514264337593543950335";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  int result = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(s21_sub_12) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-79228162514264337593";
  char *b = "2544543534465";
  char *sumRes = "-79228165058807872058";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_13) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "79228162514264337593";
  char *b = "-2544543534465";
  char *sumRes = "79228165058807872058";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_14) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-79228162514264337593";
  char *b = "-2544543534465";
  char *sumRes = "-79228159969720803128";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_15) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "7922816251.4264337593";
  char *b = "-25445.43534465";
  char *sumRes = "7922841696.8617784093";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_16) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "25445.43534465";
  char *b = "7922816251.4264337593";
  char *sumRes = "-7922790805.9910891093";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_17) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  char *a = "-79228162514264337593543950335";
  char *b = "7922816";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(s21_sub_18) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  char *a = "79228162514264337593543950335";
  char *b = "-7922816";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_sub_19) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-79228162514.0324424";
  char *b = "7.3423492482389420394";
  char *sumRes = "-79228162521.37479164823894204";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_20) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-7.3423492482389420394";
  char *b = "-73423492482389420394";
  char *sumRes = "73423492482389420386.657650752";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_21) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "7.3423492482389420394";
  char *b = "73423492482389420394";
  char *sumRes = "-73423492482389420386.657650752";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_22) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-7.3423492482389420394";
  char *b = "0";
  char *sumRes = "-7.3423492482389420394";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_23) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-0";
  char *b = "-7.3423492482389420394";
  char *sumRes = "7.3423492482389420394";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_24) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "7.3423492482389420394";
  char *b = "-0";
  char *sumRes = "7.3423492482389420394";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_25) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-792";
  char *b = "2544543534465";
  char *sumRes = "-2544543535257";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_sub_26) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "792";
  char *b = "-2544543534465";
  char *sumRes = "2544543535257";
  str_to_decimal(a, &dec1);
  str_to_decimal(b, &dec2);
  str_to_decimal(sumRes, &resCheck);
  int result = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

Suite *sub_suite(void) {
  Suite *suite = suite_create("s21_sub");
  TCase *tc_core = tcase_create("s21_sub");
  tcase_add_test(tc_core, s21_sub_1);
  tcase_add_test(tc_core, s21_sub_2);
  tcase_add_test(tc_core, s21_sub_3);
  tcase_add_test(tc_core, s21_sub_4);
  tcase_add_test(tc_core, s21_sub_5);
  tcase_add_test(tc_core, s21_sub_6);
  tcase_add_test(tc_core, s21_sub_7);
  tcase_add_test(tc_core, s21_sub_8);
  tcase_add_test(tc_core, s21_sub_9);
  tcase_add_test(tc_core, s21_sub_10);
  tcase_add_test(tc_core, s21_sub_11);
  tcase_add_test(tc_core, s21_sub_12);
  tcase_add_test(tc_core, s21_sub_13);
  tcase_add_test(tc_core, s21_sub_13);
  tcase_add_test(tc_core, s21_sub_14);
  tcase_add_test(tc_core, s21_sub_15);
  tcase_add_test(tc_core, s21_sub_16);
  tcase_add_test(tc_core, s21_sub_17);
  tcase_add_test(tc_core, s21_sub_18);
  tcase_add_test(tc_core, s21_sub_19);
  tcase_add_test(tc_core, s21_sub_20);
  tcase_add_test(tc_core, s21_sub_21);
  tcase_add_test(tc_core, s21_sub_22);
  tcase_add_test(tc_core, s21_sub_23);
  tcase_add_test(tc_core, s21_sub_24);
  tcase_add_test(tc_core, s21_sub_25);
  tcase_add_test(tc_core, s21_sub_26);

  suite_add_tcase(suite, tc_core);
  return suite;
}