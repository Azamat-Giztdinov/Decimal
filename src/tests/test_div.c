#include "unit_test.h"

START_TEST(s21_div_1) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res;
  s21_decimal res_check = {0};
  str_to_decimal("15.3", &dec_1);
  str_to_decimal("3", &dec_2);
  str_to_decimal("5.1", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}

END_TEST

START_TEST(s21_div_2) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("21324465765.675", &dec_1);
  str_to_decimal("3245987.8765", &dec_2);
  str_to_decimal("6569.484106843983155585270098", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_3) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("21324465765.675", &dec_1);
  str_to_decimal("3245987.8765", &dec_2);
  str_to_decimal("6569.484106843983155585270098", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_4) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1000000000000000", &dec_1);
  str_to_decimal("10", &dec_2);
  str_to_decimal("100000000000000", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_5) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1000000000000000", &dec_1);
  str_to_decimal("10", &dec_2);
  str_to_decimal("-100000000000000", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_6) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1000000000000000", &dec_1);
  str_to_decimal("1", &dec_2);
  str_to_decimal("1000000000000000", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_7) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1000000000000000", &dec_1);
  str_to_decimal("1", &dec_2);
  str_to_decimal("-1000000000000000", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_8) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1000000000000000", &dec_1);
  str_to_decimal("-1000000000000000", &dec_2);
  str_to_decimal("1", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_9) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1000000000000000", &dec_1);
  str_to_decimal("1000000000000000", &dec_2);
  str_to_decimal("1", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_10_1) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1000", &dec_1);
  str_to_decimal("10000", &dec_2);
  str_to_decimal("0.1", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_11) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1000", &dec_1);
  str_to_decimal("-10000", &dec_2);
  str_to_decimal("-0.1", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_12) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1000", &dec_1);
  str_to_decimal("10000", &dec_2);
  str_to_decimal("-0.1", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_13) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1000", &dec_1);
  str_to_decimal("-10000", &dec_2);
  str_to_decimal("0.1", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_14) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("371834289.234322", &dec_1);
  str_to_decimal("1.1", &dec_2);
  str_to_decimal("338031172.03120181818181818182",
                 &res_check);  // 3.3803117203120181818181818181818181818181
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_15) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("2.5", &dec_1);
  str_to_decimal("0.5", &dec_2);
  str_to_decimal("5", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_16) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-2.5", &dec_1);
  str_to_decimal("0.5", &dec_2);
  str_to_decimal("-5", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_17) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("2.5", &dec_1);
  str_to_decimal("-0.5", &dec_2);
  str_to_decimal("-5", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_18) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-2.5", &dec_1);
  str_to_decimal("-0.5", &dec_2);
  str_to_decimal("5", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_19) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0.5", &dec_1);
  str_to_decimal("0.25", &dec_2);
  str_to_decimal("2", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_20) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0.5", &dec_1);
  str_to_decimal("-0.25", &dec_2);
  str_to_decimal("-2", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_21) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0.5", &dec_1);
  str_to_decimal("0.25", &dec_2);
  str_to_decimal("-2", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_22) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0.5", &dec_1);
  str_to_decimal("-0.25", &dec_2);
  str_to_decimal("2", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_23) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0.5", &dec_1);
  str_to_decimal("-0.25", &dec_2);
  str_to_decimal("2", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_24) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("79228162514264337593543950335", &dec_1);
  str_to_decimal("5", &dec_2);
  str_to_decimal("15845632502852867518708790067", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_25) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("79228162514264337593543950335", &dec_1);
  str_to_decimal("-79228162514264337593543950335", &dec_2);
  str_to_decimal("-1", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_26) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-79228162514264337593543950335", &dec_1);
  str_to_decimal("1", &dec_2);
  str_to_decimal("-79228162514264337593543950335", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_27) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-79228162514264337593543950335", &dec_1);
  str_to_decimal("-1", &dec_2);
  str_to_decimal("79228162514264337593543950335", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_28) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-79228162514264337593543950335", &dec_1);
  str_to_decimal("1000000", &dec_2);
  str_to_decimal("-79228162514264337593543.950335", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_29) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("7.9228162514264337593543950335", &dec_1);
  str_to_decimal("0.25", &dec_2);
  str_to_decimal("31.691265005705735037417580134", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_30) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-7.9228162514264337593543950335", &dec_1);
  str_to_decimal("-25", &dec_2);
  str_to_decimal("0.3169126500570573503741758013", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_31) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("7", &dec_1);
  str_to_decimal("-6", &dec_2);
  str_to_decimal("-1.1666666666666666666666666667", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_32) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-20", &dec_1);
  str_to_decimal("7", &dec_2);
  str_to_decimal("-2.8571428571428571428571428571", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_33) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("0.00000", &dec_1);
  str_to_decimal("0", &dec_2);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_div_34) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("-0", &dec_1);
  str_to_decimal("-0.00000", &dec_2);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_div_35) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("0.00000", &dec_1);
  str_to_decimal("-0.00000", &dec_2);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_div_36) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("0", &dec_1);
  str_to_decimal("0", &dec_2);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_div_37) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("792281625142643375935439523", &dec_1);
  str_to_decimal("0", &dec_2);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_div_38) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("-792281625142643375935439523", &dec_1);
  str_to_decimal("-0", &dec_2);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_div_39) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("281625142643375935439523", &dec_1);
  str_to_decimal("-0", &dec_2);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_div_40) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("281625142643375935439523", &dec_1);
  str_to_decimal("0", &dec_2);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 3);
}
END_TEST

START_TEST(s21_div_41) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("79228162514264337593543950335", &dec_1);
  str_to_decimal("0.5", &dec_2);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 1);
}
END_TEST

START_TEST(s21_div_42) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("79228162514264337593543950335", &dec_1);
  str_to_decimal("-0.5", &dec_2);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 2);
}
END_TEST

START_TEST(s21_div_43) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0", &dec_1);
  str_to_decimal("7", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_44) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0.000", &dec_1);
  str_to_decimal("71234342.123", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_45) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0", &dec_1);
  str_to_decimal("-71234342.123", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_div_46) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0", &dec_1);
  str_to_decimal("-712343421234", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_div(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

Suite *div_suite(void) {
  Suite *suite = suite_create("s21_div");
  TCase *tc_core = tcase_create("s21_div");
  tcase_add_test(tc_core, s21_div_1);
  tcase_add_test(tc_core, s21_div_2);
  tcase_add_test(tc_core, s21_div_3);
  tcase_add_test(tc_core, s21_div_3);
  tcase_add_test(tc_core, s21_div_4);
  tcase_add_test(tc_core, s21_div_5);
  tcase_add_test(tc_core, s21_div_6);
  tcase_add_test(tc_core, s21_div_7);
  tcase_add_test(tc_core, s21_div_8);
  tcase_add_test(tc_core, s21_div_9);
  tcase_add_test(tc_core, s21_div_10_1);
  tcase_add_test(tc_core, s21_div_11);
  tcase_add_test(tc_core, s21_div_12);
  tcase_add_test(tc_core, s21_div_13);
  tcase_add_test(tc_core, s21_div_14);
  tcase_add_test(tc_core, s21_div_15);
  tcase_add_test(tc_core, s21_div_16);
  tcase_add_test(tc_core, s21_div_17);
  tcase_add_test(tc_core, s21_div_18);
  tcase_add_test(tc_core, s21_div_19);
  tcase_add_test(tc_core, s21_div_20);
  tcase_add_test(tc_core, s21_div_21);
  tcase_add_test(tc_core, s21_div_22);
  tcase_add_test(tc_core, s21_div_23);
  tcase_add_test(tc_core, s21_div_24);
  tcase_add_test(tc_core, s21_div_25);
  tcase_add_test(tc_core, s21_div_26);
  tcase_add_test(tc_core, s21_div_27);
  tcase_add_test(tc_core, s21_div_28);
  tcase_add_test(tc_core, s21_div_29);
  tcase_add_test(tc_core, s21_div_30);
  tcase_add_test(tc_core, s21_div_31);
  tcase_add_test(tc_core, s21_div_32);
  tcase_add_test(tc_core, s21_div_33);
  tcase_add_test(tc_core, s21_div_34);
  tcase_add_test(tc_core, s21_div_35);
  tcase_add_test(tc_core, s21_div_36);
  tcase_add_test(tc_core, s21_div_37);
  tcase_add_test(tc_core, s21_div_38);
  tcase_add_test(tc_core, s21_div_39);
  tcase_add_test(tc_core, s21_div_40);
  tcase_add_test(tc_core, s21_div_41);
  tcase_add_test(tc_core, s21_div_42);
  tcase_add_test(tc_core, s21_div_43);
  tcase_add_test(tc_core, s21_div_44);
  tcase_add_test(tc_core, s21_div_45);
  tcase_add_test(tc_core, s21_div_46);

  suite_add_tcase(suite, tc_core);
  return suite;
}
