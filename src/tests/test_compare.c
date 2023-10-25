#include "unit_test.h"

START_TEST(s21_comparing_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "0";
  char *str_2 = "0";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_comparing_2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "123";
  char *str_2 = "1";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "1231234";
  char *str_2 = "1231234.0001";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "1231234123412";
  char *str_2 = "-1231234123412.0001";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_5) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "-1231234";
  char *str_2 = "-1231234.0001";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "-0.00000";
  char *str_2 = "0";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_comparing_7) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "-12134.142";
  char *str_2 = "4531";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_8) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "1231234.0001";
  char *str_2 = "1231234";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_9) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "1231234";
  char *str_2 = "123123.4";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_10) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "7922816251426433759354395033.5";
  char *str_2 = "7.9228162514264337593543950335";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_11) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "7.0000000000000000000000000000";
  char *str_2 = "7";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_comparing_12) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "7.0000000000000000000000000000";
  char *str_2 = "0.0000000000000000000000000007";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_13) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "7.0000000000000000000000000000";
  char *str_2 = "7.00";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_comparing_14) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "0.0000000000000000000000000000";
  char *str_2 = "0.00";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_comparing_15) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "-7922816251426433759354395033.5";
  char *str_2 = "-7.9228162514264337593543950335";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_16) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "-7922816251426433759354395033.5";
  char *str_2 = "7.9228162514264337593543950335";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_17) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "-7.9228162514264337593543950335";
  char *str_2 = "-7922816251426433759354395033.5";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_18) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "7.9228162514264337593540335";
  char *str_2 = "-792281625142643375935439.5";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_comparing_19) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "-79228.162514264337593540335";
  char *str_2 = "-79228.162514264337593540335";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_comparing_20) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  char *str_1 = "79228.162514264337593540335";
  char *str_2 = "79228.162514264337593540335";
  str_to_decimal(str_1, &value_1);
  str_to_decimal(str_2, &value_2);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

Suite *comparing_suite(void) {
  Suite *suite = suite_create("s21_comparing");
  TCase *tc_core = tcase_create("s21_comparing");
  tcase_add_test(tc_core, s21_comparing_1);
  tcase_add_test(tc_core, s21_comparing_2);
  tcase_add_test(tc_core, s21_comparing_3);
  tcase_add_test(tc_core, s21_comparing_4);
  tcase_add_test(tc_core, s21_comparing_5);
  tcase_add_test(tc_core, s21_comparing_6);
  tcase_add_test(tc_core, s21_comparing_7);
  tcase_add_test(tc_core, s21_comparing_8);
  tcase_add_test(tc_core, s21_comparing_9);
  tcase_add_test(tc_core, s21_comparing_10);
  tcase_add_test(tc_core, s21_comparing_11);
  tcase_add_test(tc_core, s21_comparing_12);
  tcase_add_test(tc_core, s21_comparing_13);
  tcase_add_test(tc_core, s21_comparing_14);
  tcase_add_test(tc_core, s21_comparing_15);
  tcase_add_test(tc_core, s21_comparing_16);
  tcase_add_test(tc_core, s21_comparing_17);
  tcase_add_test(tc_core, s21_comparing_18);
  tcase_add_test(tc_core, s21_comparing_19);
  tcase_add_test(tc_core, s21_comparing_20);

  suite_add_tcase(suite, tc_core);
  return suite;
}
