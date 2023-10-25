#include "unit_test.h"

START_TEST(s21_float_to_dec_1) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("123.1000", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(123.1, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_float_to_dec_2) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("123234200000000000000", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(123234234234234234234.1, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_float_to_dec_3) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("123234300000000000000", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(123234294234234234234.1, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_float_to_dec_4) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("100000.4", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(100000.423423412345, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_float_to_dec_5) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("100000.5", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(100000.493423412345, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_float_to_dec_6) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0.000000005640000", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(0.00000000564, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_float_to_dec_7) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  ck_assert_int_eq(s21_from_float_to_decimal(1.0 / 0.0, &res), 1);
}
END_TEST

START_TEST(s21_float_to_dec_8) {
  s21_decimal res = {0};
  ck_assert_int_eq(
      s21_from_float_to_decimal(89228162514264337593543950336.0F, &res), 1);
}
END_TEST

START_TEST(s21_float_to_dec_9) {
  s21_decimal res = {0};
  ck_assert_int_eq(
      s21_from_float_to_decimal(-89228162514264337593543950336.0F, &res), 1);
}
END_TEST

START_TEST(s21_float_to_dec_10) {
  s21_decimal res = {0};
  ck_assert_int_eq(s21_from_float_to_decimal(0.0 / 0.0, &res), 1);
}
END_TEST

START_TEST(s21_float_to_dec_11) {
  s21_decimal res = {0};
  s21_decimal check = {0};
  ck_assert_int_eq(s21_from_float_to_decimal(-123.1, &res), 0);
  str_to_decimal("-123.1000", &check);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[0], check.bits[0]);
  }
}
END_TEST

START_TEST(s21_float_to_dec_12) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-100000.5", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(-100000.493423412345, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_float_to_dec_13) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(
                       0.00000000000000000000000000001234567899F, &res),
                   1);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_14) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("79228160000000000000000000000", &res_check);
  ck_assert_int_eq(
      s21_from_float_to_decimal(79228162514264337593543950334.0F, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_15) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  ck_assert_int_eq(s21_from_float_to_decimal(-1.0 / 0.0, &res), 1);
}
END_TEST

START_TEST(s21_float_to_dec_16) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("27922820", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(27922816.0000, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_17) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-27922820", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(-27922816.0000, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_18) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1.234568", &res_check);
  float f = 1.234567899F;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_19) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1.234568", &res_check);
  float f = -1.234567899F;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_20) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0", &res_check);
  float f = 0.00000000000000000000000000001234567899F;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 1);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_21) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0", &res_check);
  float f = -0.00000000000000000000000000001234567899F;
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 1);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_22) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  float f = 0.0000000000000000000000000001234567899F;
  str_to_decimal("0.0000000000000000000000000001", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_23) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  float f = 0.000000000000000000000000001234567899F;
  str_to_decimal("0.0000000000000000000000000012", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_24) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  float f = 0.00000000000000000000000001234567899F;
  str_to_decimal("0.0000000000000000000000000123", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_25) {
  s21_decimal res;
  s21_decimal res_check = {0};
  float f = 0.0000000000000000000000001234567899F;
  str_to_decimal("0.0000000000000000000000001234", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_26) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  float f = 0.000000000000000000000001234567899F;
  str_to_decimal("0.0000000000000000000000012346", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_27) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  float f = 0.00000000000000000000001234567899F;
  str_to_decimal("0.0000000000000000000000123457", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_28) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  float f = 0.0000000000000000000001234567899F;
  str_to_decimal("0.0000000000000000000001234568", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

START_TEST(s21_float_to_dec_29) {
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  float f = 0.000000000000000000001234567899F;
  str_to_decimal("0.000000000000000000001234568", &res_check);
  ck_assert_int_eq(s21_from_float_to_decimal(f, &res), 0);
  for (int i = 0; i <= 3; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

END_TEST
Suite *float_to_dec_suite(void) {
  Suite *suite = suite_create("s21_float_to_dec");
  TCase *tc_core = tcase_create("s21_float_to_dec");
  tcase_add_test(tc_core, s21_float_to_dec_1);
  tcase_add_test(tc_core, s21_float_to_dec_2);
  tcase_add_test(tc_core, s21_float_to_dec_3);
  tcase_add_test(tc_core, s21_float_to_dec_4);
  tcase_add_test(tc_core, s21_float_to_dec_5);
  tcase_add_test(tc_core, s21_float_to_dec_6);
  tcase_add_test(tc_core, s21_float_to_dec_7);
  tcase_add_test(tc_core, s21_float_to_dec_8);
  tcase_add_test(tc_core, s21_float_to_dec_9);
  tcase_add_test(tc_core, s21_float_to_dec_10);
  tcase_add_test(tc_core, s21_float_to_dec_11);
  tcase_add_test(tc_core, s21_float_to_dec_12);
  tcase_add_test(tc_core, s21_float_to_dec_13);
  tcase_add_test(tc_core, s21_float_to_dec_14);
  tcase_add_test(tc_core, s21_float_to_dec_15);
  tcase_add_test(tc_core, s21_float_to_dec_16);
  tcase_add_test(tc_core, s21_float_to_dec_17);
  tcase_add_test(tc_core, s21_float_to_dec_18);
  tcase_add_test(tc_core, s21_float_to_dec_19);
  tcase_add_test(tc_core, s21_float_to_dec_20);
  tcase_add_test(tc_core, s21_float_to_dec_21);
  tcase_add_test(tc_core, s21_float_to_dec_22);
  tcase_add_test(tc_core, s21_float_to_dec_23);
  tcase_add_test(tc_core, s21_float_to_dec_24);
  tcase_add_test(tc_core, s21_float_to_dec_25);
  tcase_add_test(tc_core, s21_float_to_dec_26);
  tcase_add_test(tc_core, s21_float_to_dec_27);
  tcase_add_test(tc_core, s21_float_to_dec_28);
  tcase_add_test(tc_core, s21_float_to_dec_29);

  suite_add_tcase(suite, tc_core);
  return suite;
}
