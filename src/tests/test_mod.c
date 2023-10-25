#include "unit_test.h"

START_TEST(s21_mod_1) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res;
  s21_decimal res_check = {0};
  str_to_decimal("12345678907654321", &dec_1);
  str_to_decimal("123312", &dec_2);
  str_to_decimal("60625", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_2) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1232434567890765432123", &dec_1);
  str_to_decimal("-123423312", &dec_2);
  str_to_decimal("-62167035", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_3) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1232434567890765432123", &dec_1);
  str_to_decimal("123423312", &dec_2);
  str_to_decimal("-62167035", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_4) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1232434567890765432123", &dec_1);
  str_to_decimal("-123423312", &dec_2);
  str_to_decimal("62167035", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_5) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("123423312", &dec_1);
  str_to_decimal("1232434567890765432123", &dec_2);
  str_to_decimal("123423312", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_6) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-123423312", &dec_1);
  str_to_decimal("-1232434567890765432123", &dec_2);
  str_to_decimal("-123423312", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_7) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("123423312", &dec_1);
  str_to_decimal("-1232434567890765432123", &dec_2);
  str_to_decimal("123423312", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_8) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-123423312", &dec_1);
  str_to_decimal("1232434567890765432123", &dec_2);
  str_to_decimal("-123423312", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_9) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("12342331234.22342341241343", &dec_1);
  str_to_decimal("1232434.56789765432123", &dec_2);
  str_to_decimal("731471.29631303961621", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_10) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-12342331234.22342341241343", &dec_1);
  str_to_decimal("-1232434.56789765432123", &dec_2);
  str_to_decimal("-731471.29631303961621", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_11) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-12342331234.22342341241343", &dec_1);
  str_to_decimal("1232434.56789765432123", &dec_2);
  str_to_decimal("-731471.29631303961621", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_12) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("12342331234.22342341241343", &dec_1);
  str_to_decimal("-1232434.56789765432123", &dec_2);
  str_to_decimal("731471.29631303961621", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_13) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1.234233123422342341241343", &dec_1);
  str_to_decimal("1232434.56789765432123", &dec_2);
  str_to_decimal("1.234233123422342341241343", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_14) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1.234233123422342341241343", &dec_1);
  str_to_decimal("-1232434.56789765432123", &dec_2);
  str_to_decimal("-1.234233123422342341241343", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_15) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1.234233123422342341241343", &dec_1);
  str_to_decimal("1232434.56789765432123", &dec_2);
  str_to_decimal("-1.234233123422342341241343", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_16) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1.234233123422342341241343", &dec_1);
  str_to_decimal("-1232434.56789765432123", &dec_2);
  str_to_decimal("1.234233123422342341241343", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_17) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1.234233123422342341241343", &dec_1);
  str_to_decimal("1.234233123422342341241343", &dec_2);
  str_to_decimal("0.000000000000000000000000", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_18) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1234233123422342341241343", &dec_1);
  str_to_decimal("1234233123422342341241343", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_19) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("123423312342234234124134", &dec_1);
  str_to_decimal("123423312342.2342341241343", &dec_2);
  str_to_decimal("123423312341.9342341241343", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_20) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-123423312342234234124134", &dec_1);
  str_to_decimal("-123423312342.2342341241343", &dec_2);
  str_to_decimal("-123423312341.9342341241343", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_21) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("123423312342234234124134", &dec_1);
  str_to_decimal("-123423312342.2342341241343", &dec_2);
  str_to_decimal("123423312341.9342341241343", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_22) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-123423312342234234124134", &dec_1);
  str_to_decimal("123423312342.2342341241343", &dec_2);
  str_to_decimal("-123423312341.9342341241343", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_23) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("79228162514264337593543950335", &dec_1);
  str_to_decimal("1", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_24) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-79228162514264337593543950335", &dec_1);
  str_to_decimal("79228162514264337593543950335", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_25) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("7.9228162514264337593543950335", &dec_1);
  str_to_decimal("1.9228162514264337593543950335", &dec_2);
  str_to_decimal("0.2315512457206987219368148995", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_26) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("79228162514264337593543950335", &dec_1);
  str_to_decimal("1.9228162514264337593543950335", &dec_2);
  str_to_decimal("1.6460229711307536040313116995", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_27) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0", &dec_1);
  str_to_decimal("1.9228162514264337593543950335", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_28) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0", &dec_1);
  str_to_decimal("1.9228162514264337593543950335", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mod_29) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("32423", &dec_1);
  str_to_decimal("0", &dec_2);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_mod_30) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("-32432442323423", &dec_1);
  str_to_decimal("0", &dec_2);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_mod_31) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("-32432442323423", &dec_1);
  str_to_decimal("-0.000", &dec_2);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_mod_32) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("32432442323423", &dec_1);
  str_to_decimal("-0", &dec_2);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_mod_33) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("0", &dec_1);
  str_to_decimal("-0.00", &dec_2);
  ck_assert_int_eq(s21_mod(dec_1, dec_2, &res), 3);
}
END_TEST

Suite *mod_suite(void) {
  Suite *suite = suite_create("s21_mod");
  TCase *tc_core = tcase_create("s21_mod");
  tcase_add_test(tc_core, s21_mod_1);
  tcase_add_test(tc_core, s21_mod_2);
  tcase_add_test(tc_core, s21_mod_3);
  tcase_add_test(tc_core, s21_mod_4);
  tcase_add_test(tc_core, s21_mod_5);
  tcase_add_test(tc_core, s21_mod_6);
  tcase_add_test(tc_core, s21_mod_7);
  tcase_add_test(tc_core, s21_mod_8);
  tcase_add_test(tc_core, s21_mod_9);
  tcase_add_test(tc_core, s21_mod_10);
  tcase_add_test(tc_core, s21_mod_11);
  tcase_add_test(tc_core, s21_mod_12);
  tcase_add_test(tc_core, s21_mod_13);
  tcase_add_test(tc_core, s21_mod_14);
  tcase_add_test(tc_core, s21_mod_15);
  tcase_add_test(tc_core, s21_mod_16);
  tcase_add_test(tc_core, s21_mod_17);
  tcase_add_test(tc_core, s21_mod_18);
  tcase_add_test(tc_core, s21_mod_19);
  tcase_add_test(tc_core, s21_mod_20);
  tcase_add_test(tc_core, s21_mod_21);
  tcase_add_test(tc_core, s21_mod_22);
  tcase_add_test(tc_core, s21_mod_23);
  tcase_add_test(tc_core, s21_mod_24);
  tcase_add_test(tc_core, s21_mod_25);
  tcase_add_test(tc_core, s21_mod_26);
  tcase_add_test(tc_core, s21_mod_27);
  tcase_add_test(tc_core, s21_mod_28);
  tcase_add_test(tc_core, s21_mod_29);
  tcase_add_test(tc_core, s21_mod_30);
  tcase_add_test(tc_core, s21_mod_31);
  tcase_add_test(tc_core, s21_mod_32);
  tcase_add_test(tc_core, s21_mod_33);

  suite_add_tcase(suite, tc_core);
  return suite;
}
