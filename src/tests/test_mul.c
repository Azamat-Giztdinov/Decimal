#include "unit_test.h"

START_TEST(s21_mul_1) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0", &dec_1);
  str_to_decimal("0", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }

  str_to_decimal("0", &dec_1);
  str_to_decimal("-0", &dec_2);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }

  str_to_decimal("-0.000000", &dec_1);
  str_to_decimal("-0.0", &dec_2);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }

  str_to_decimal("-0.00", &dec_1);
  str_to_decimal("0.000", &dec_2);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_2) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("214124524", &dec_1);
  str_to_decimal("5", &dec_2);
  str_to_decimal("1070622620", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_3) {  // test for 2 byte mul
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("4294967295", &dec_1);
  str_to_decimal("-100000", &dec_2);
  str_to_decimal("-429496729500000", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }

  str_to_decimal("4294967295", &dec_1);
  str_to_decimal("2", &dec_2);
  str_to_decimal("8589934590", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }

  str_to_decimal("4294967295", &dec_1);
  str_to_decimal("1", &dec_2);
  str_to_decimal("4294967295", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }

  str_to_decimal("-4294967295", &dec_1);
  str_to_decimal("-4294967295", &dec_2);
  str_to_decimal("18446744065119617025", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }

  str_to_decimal("18446744073709551615", &dec_1);
  str_to_decimal("1", &dec_2);
  str_to_decimal("18446744073709551615", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_4) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0.2348791274271341249124971238", &dec_1);
  str_to_decimal("2544543534465.1", &dec_2);
  str_to_decimal("597660165075.51847586320295366", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }

  //  doZero(&dec_1);
  //  doZero(&dec_2);
  //  doZero(&res);
  //  doZero(&res_check);
  //  str_to_decimal("36893488130239234050", &dec_1);
  //  str_to_decimal("-1324", &dec_2);
  //  str_to_decimal("-48846978284436745882200", &res_check);
  //  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  //  for (int i = 0; i < 4; i++) {
  //    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  //  }
  //
  //  doZero(&dec_1);
  //  doZero(&dec_2);
  //  doZero(&res);
  //  doZero(&res_check);
  //  str_to_decimal("79228162514264337593543950335", &dec_1);
  //  str_to_decimal("1", &dec_2);
  //  str_to_decimal("79228162514264337593543950335", &res_check);
  //  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  //  for (int i = 0; i < 4; i++) {
  //    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  //  }
  //
  //  doZero(&dec_1);
  //  doZero(&dec_2);
  //  doZero(&res);
  //  doZero(&res_check);
  //  str_to_decimal("-4294967295", &dec_1);
  //  str_to_decimal("-4294967295", &dec_2);
  //  str_to_decimal("18446744065119617025", &res_check);
  //  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  //  for (int i = 0; i < 4; i++) {
  //    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  //  }
}
END_TEST

START_TEST(s21_mul_5) {  // test for other
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("18446744065119617025", &dec_1);
  str_to_decimal("2", &dec_2);
  str_to_decimal("36893488130239234050", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }

  str_to_decimal("36893488130239234050", &dec_1);
  str_to_decimal("-1324", &dec_2);
  str_to_decimal("-48846978284436745882200", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_6) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0.23487", &dec_1);
  str_to_decimal("2544543534465", &dec_2);
  str_to_decimal("597636939939.79455", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_7) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1.2345", &dec_1);
  str_to_decimal("35445435.1", &dec_2);
  str_to_decimal("43757389.63095", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_8) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("345.321", &dec_1);
  str_to_decimal("10", &dec_2);
  str_to_decimal("3453.21", &res_check);  // 3453.210
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_9) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("79228162514264337593543950335", &dec_1);
  str_to_decimal("0.6", &dec_2);
  str_to_decimal("47536897508558602556126370201", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_10_1) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("7.9228162514264337593543950335", &dec_1);
  str_to_decimal("2544543534465.1", &dec_2);
  str_to_decimal("20159950867322.152137582972238", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_11) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("79228162514264337593543950335", &dec_1);
  str_to_decimal("2544543534465.1", &dec_2);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 1);
}
END_TEST

START_TEST(s21_mul_12) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1124453449", &dec_1);
  str_to_decimal("46512346", &dec_2);
  str_to_decimal("-52300967880781354", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_13) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-112", &dec_1);
  str_to_decimal("46523312346", &dec_2);
  str_to_decimal("-5210610982752", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_14) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("112", &dec_1);
  str_to_decimal("-46523312346", &dec_2);
  str_to_decimal("-5210610982752", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_15) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1124453449", &dec_1);
  str_to_decimal("-46512346", &dec_2);
  str_to_decimal("-52300967880781354", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_16) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-1124453449", &dec_1);
  str_to_decimal("-46512346", &dec_2);
  str_to_decimal("52300967880781354", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_17) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-46512346", &dec_1);
  str_to_decimal("-1124453449", &dec_2);
  str_to_decimal("52300967880781354", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_18) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("46512346", &dec_1);
  str_to_decimal("1124453449", &dec_2);
  str_to_decimal("52300967880781354", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_19) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1124453449", &dec_1);
  str_to_decimal("46512346", &dec_2);
  str_to_decimal("52300967880781354", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_20) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-11244.53449", &dec_1);
  str_to_decimal("4.6512346", &dec_2);
  str_to_decimal("-52300.967880781354", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_21) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("11244.53449", &dec_1);
  str_to_decimal("-4.6512346", &dec_2);
  str_to_decimal("-52300.967880781354", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_22) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("1124453449", &dec_1);
  str_to_decimal("4.6512346", &dec_2);
  str_to_decimal("5230096788.0781354", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_23) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-7.9228162514264337593543950335", &dec_1);
  str_to_decimal("2544543534465.1", &dec_2);
  str_to_decimal("-20159950867322.152137582972238", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_24) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("2544543534465.1", &dec_1);
  str_to_decimal("-7.9228162514264337593543950335", &dec_2);
  str_to_decimal("-20159950867322.152137582972238", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_25) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-2544543534465.1", &dec_1);
  str_to_decimal("-7.9228162514264337593543950335", &dec_2);
  str_to_decimal("20159950867322.152137582972238", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_26) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-2544543534465.1", &dec_1);
  str_to_decimal("0", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_27) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("2544543534465.1", &dec_1);
  str_to_decimal("-0", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_28) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-0", &dec_1);
  str_to_decimal("-2544543534465.1", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_29) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("0", &dec_1);
  str_to_decimal("2544543534465.1", &dec_2);
  str_to_decimal("0", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_30) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("-79228162514264337593543950335", &dec_1);
  str_to_decimal("-2544543534465.1", &dec_2);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 1);
}
END_TEST

START_TEST(s21_mul_31) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("-79228162514264337593543950", &dec_1);
  str_to_decimal("254454353446234235", &dec_2);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 2);
}
END_TEST

START_TEST(s21_mul_32) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  str_to_decimal("79228162514264337593543950", &dec_1);
  str_to_decimal("-254454353446234235", &dec_2);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 2);
}
END_TEST

START_TEST(s21_mul_33) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("7922816251426433759354395033.5", &dec_1);
  str_to_decimal("7.9228162514264337593543950335", &dec_2);
  str_to_decimal("62771017353866807638357894230", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_34) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res;
  s21_decimal res_check = {0};
  str_to_decimal("-7922816251426433759354395033.5", &dec_1);
  str_to_decimal("-7.9228162514264337593543950335", &dec_2);
  str_to_decimal("62771017353866807638357894230", &res_check);
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_35) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("7.0000000000000000000000000000", &dec_1);
  str_to_decimal("7.00", &dec_2);
  str_to_decimal("49", &res_check);  // 49.000000000000000000000000000
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_36) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res = {0};
  s21_decimal res_check = {0};
  str_to_decimal("-7.0000000000000000000000000000", &dec_1);
  str_to_decimal("-7.00", &dec_2);
  str_to_decimal("49", &res_check);  // 49.000000000000000000000000000
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

START_TEST(s21_mul_37) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal res;
  s21_decimal res_check = {0};
  str_to_decimal("7.9228162514264337593543950335", &dec_1);
  str_to_decimal("7.9228162514264337593543950335", &dec_2);
  str_to_decimal("62.77101735386680763835789423",
                 &res_check);  // 62.771017353866807638357894230
  ck_assert_int_eq(s21_mul(dec_1, dec_2, &res), 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(res.bits[i], res_check.bits[i]);
  }
}
END_TEST

Suite *mul_suite(void) {
  Suite *suite = suite_create("s21_mul");
  TCase *tc_core = tcase_create("s21_mul");
  tcase_add_test(tc_core, s21_mul_1);
  tcase_add_test(tc_core, s21_mul_2);
  tcase_add_test(tc_core, s21_mul_3);
  tcase_add_test(tc_core, s21_mul_4);
  tcase_add_test(tc_core, s21_mul_5);
  tcase_add_test(tc_core, s21_mul_6);
  tcase_add_test(tc_core, s21_mul_7);
  tcase_add_test(tc_core, s21_mul_8);
  tcase_add_test(tc_core, s21_mul_9);
  tcase_add_test(tc_core, s21_mul_10_1);
  tcase_add_test(tc_core, s21_mul_11);
  tcase_add_test(tc_core, s21_mul_12);
  tcase_add_test(tc_core, s21_mul_13);
  tcase_add_test(tc_core, s21_mul_14);
  tcase_add_test(tc_core, s21_mul_15);
  tcase_add_test(tc_core, s21_mul_16);
  tcase_add_test(tc_core, s21_mul_17);
  tcase_add_test(tc_core, s21_mul_18);
  tcase_add_test(tc_core, s21_mul_19);
  tcase_add_test(tc_core, s21_mul_20);
  tcase_add_test(tc_core, s21_mul_21);
  tcase_add_test(tc_core, s21_mul_22);
  tcase_add_test(tc_core, s21_mul_23);
  tcase_add_test(tc_core, s21_mul_24);
  tcase_add_test(tc_core, s21_mul_25);
  tcase_add_test(tc_core, s21_mul_26);
  tcase_add_test(tc_core, s21_mul_27);
  tcase_add_test(tc_core, s21_mul_28);
  tcase_add_test(tc_core, s21_mul_29);
  tcase_add_test(tc_core, s21_mul_30);
  tcase_add_test(tc_core, s21_mul_31);
  tcase_add_test(tc_core, s21_mul_32);
  tcase_add_test(tc_core, s21_mul_33);
  tcase_add_test(tc_core, s21_mul_34);
  tcase_add_test(tc_core, s21_mul_35);
  tcase_add_test(tc_core, s21_mul_36);
  tcase_add_test(tc_core, s21_mul_37);

  suite_add_tcase(suite, tc_core);
  return suite;
}
