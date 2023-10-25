#include "unit_test.h"

START_TEST(s21_add_1) {
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
  int result = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_add_2) {
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
  int result = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_add_3) {
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
  int result = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], resCheck.bits[i]);
  }
}
END_TEST

START_TEST(s21_add_4) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res;
  s21_decimal resCheck = {0};
  char *a = "0";
  char *b = "0";
  char *sumRes = "0";
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

START_TEST(s21_add_5) {
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

START_TEST(s21_add_6) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "7.9228162514264337593543950335";
  char *b = "-0.6";
  char *sumRes = "7.3228162514264337593543950335";
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

START_TEST(s21_add_7) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res;
  s21_decimal resCheck = {0};
  char *a = "7.9228162514264337593543950335";
  char *b = "2544543534465.1";
  char *sumRes = "2544543534473.0228162514264338";
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

START_TEST(s21_add_8) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-7.9228162514264337593543950335";
  char *b = "-2544543534465.1";
  char *sumRes = "-2544543534473.0228162514264338";
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

START_TEST(s21_add_9) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-7.9228162514264337593543950335";
  char *b = "2544543534465.1";
  char *sumRes = "2544543534457.1771837485735662";
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

START_TEST(s21_add_10) {
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

START_TEST(s21_add_11) {
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

START_TEST(s21_add_12) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-7.9228162";
  char *b = "-2544543534465.1";
  char *sumRes = "-2544543534473.0228162";
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

START_TEST(s21_add_13) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-3.1415926";
  char *b = "3.1415926";
  char *sumRes = "0";
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

START_TEST(s21_add_14) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "234234.124";
  char *b = "324234.1234";
  char *sumRes = "558468.2474";
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

START_TEST(s21_add_15) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "234234124";
  char *b = "3242341234";
  char *sumRes = "3476575358";
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

START_TEST(s21_add_16) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-234212434124";
  char *b = "-3242341124234";
  char *sumRes = "-3476553558358";
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

START_TEST(s21_add_17) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "2341234";
  char *b = "-3242341124234";
  char *sumRes = "-3242338783000";
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

START_TEST(s21_add_18) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "23412323234234234234";
  char *b = "-3242341124234";
  char *sumRes = "23412319991893110000";
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

START_TEST(s21_add_19) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-23412323234234234234";
  char *b = "3242341124234";
  char *sumRes = "-23412319991893110000";
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

START_TEST(s21_add_20) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-23412";
  char *b = "3242341124234";
  char *sumRes = "3242341100822";
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

START_TEST(s21_add_21) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-23412";
  char *b = "0";
  char *sumRes = "-23412";
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

START_TEST(s21_add_22) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "23412";
  char *b = "-0";
  char *sumRes = "23412";
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

START_TEST(s21_add_23) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "-2314144.432323423412";
  char *b = "-0";
  char *sumRes = "-2314144.432323423412";
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

START_TEST(s21_add_24) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal res = {0};
  s21_decimal resCheck = {0};
  char *a = "0";
  char *b = "2314144.432323423412";
  char *sumRes = "2314144.432323423412";
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

Suite *add_suite(void) {
  Suite *suite = suite_create("s21_add");
  TCase *tc_core = tcase_create("s21_add");
  tcase_add_test(tc_core, s21_add_1);
  tcase_add_test(tc_core, s21_add_2);
  tcase_add_test(tc_core, s21_add_3);
  tcase_add_test(tc_core, s21_add_4);
  tcase_add_test(tc_core, s21_add_5);
  tcase_add_test(tc_core, s21_add_6);
  tcase_add_test(tc_core, s21_add_7);
  tcase_add_test(tc_core, s21_add_8);
  tcase_add_test(tc_core, s21_add_9);
  tcase_add_test(tc_core, s21_add_10);
  tcase_add_test(tc_core, s21_add_11);
  tcase_add_test(tc_core, s21_add_12);
  tcase_add_test(tc_core, s21_add_13);
  tcase_add_test(tc_core, s21_add_14);
  tcase_add_test(tc_core, s21_add_15);
  tcase_add_test(tc_core, s21_add_16);
  tcase_add_test(tc_core, s21_add_17);
  tcase_add_test(tc_core, s21_add_18);
  tcase_add_test(tc_core, s21_add_19);
  tcase_add_test(tc_core, s21_add_20);
  tcase_add_test(tc_core, s21_add_21);
  tcase_add_test(tc_core, s21_add_22);
  tcase_add_test(tc_core, s21_add_23);
  tcase_add_test(tc_core, s21_add_24);

  suite_add_tcase(suite, tc_core);
  return suite;
}
