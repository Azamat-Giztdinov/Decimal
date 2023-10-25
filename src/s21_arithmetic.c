#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_bigdecimal bigvalue_1 = {0}, bigvalue_2 = {0}, bigresult = {0};
  decimal_to_bigdecimal(value_1, &bigvalue_1);
  decimal_to_bigdecimal(value_2, &bigvalue_2);
  s21_one_scale(&bigvalue_1, &bigvalue_2);
  if (!isSetBit(value_1, 127) && !isSetBit(value_2, 127)) {
    s21_big_add(bigvalue_1, bigvalue_2, &bigresult);
  }
  if (isSetBit(value_1, 127) && isSetBit(value_2, 127)) {
    s21_big_add(bigvalue_1, bigvalue_2, &bigresult);
    bigresult.bits[6] = bigsetBit(bigresult, 223);

  } else if (isSetBit(value_1, 127) ^ isSetBit(value_2, 127)) {
    if (big_is_greater_dop(bigvalue_1, bigvalue_2) ==
        -1) {  // value_1 == value_2 (1 -1)
      s21_big_sub(bigvalue_2, bigvalue_1, &bigresult);
      bigresult.bits[6] = bigresetBit(bigvalue_2, 223);
    } else if (big_is_greater_dop(bigvalue_1,
                                  bigvalue_2)) {  // value_1 > value_2
      s21_big_sub(bigvalue_1, bigvalue_2, &bigresult);
      if (bigisSetBit(bigvalue_1, 223)) {
        bigresult.bits[6] = bigsetBit(bigvalue_1, 223);
      } else {
        bigresult.bits[6] = bigresetBit(bigvalue_1, 223);
      }
    } else if (!big_is_greater_dop(bigvalue_1,
                                   bigvalue_2)) {  // value_1 < value_2
      s21_big_sub(bigvalue_2, bigvalue_1, &bigresult);
      if (bigisSetBit(bigvalue_2, 223)) {
        bigresult.bits[6] = bigsetBit(bigvalue_2, 223);
      } else {
        bigresult.bits[6] = bigresetBit(bigvalue_2, 223);
      }
    }
  }
  int res = bigdecimal_to_decimal(result, bigresult);
  if (!result->bits[0] && !result->bits[1] && !result->bits[2]) {
    result->bits[3] = 0;
  }
  return res;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result) {  //вычитание
  s21_bigdecimal bigvalue_1 = {0}, bigvalue_2 = {0}, bigresult = {0};
  decimal_to_bigdecimal(value_1, &bigvalue_1);
  decimal_to_bigdecimal(value_2, &bigvalue_2);
  s21_one_scale(&bigvalue_1, &bigvalue_2);
  if (!isSetBit(value_1, 127) && !isSetBit(value_2, 127)) {  //+ +
    if (big_is_greater_dop(bigvalue_1, bigvalue_2)) {  // value_1 > value_2
      s21_big_sub(bigvalue_1, bigvalue_2, &bigresult);
    } else if (!big_is_greater_dop(bigvalue_1,
                                   bigvalue_2)) {  // value_1 < value_2
      s21_big_sub(bigvalue_2, bigvalue_1, &bigresult);
      bigresult.bits[6] = bigsetBit(bigvalue_1, 223);
    }
  } else if (isSetBit(value_1, 127) && isSetBit(value_2, 127)) {  //- -
    if (big_is_greater_dop(bigvalue_1, bigvalue_2)) {  // value_1 > value_2
      s21_big_sub(bigvalue_1, bigvalue_2, &bigresult);
      bigresult.bits[6] = bigsetBit(bigvalue_1, 223);
    } else if (!big_is_greater_dop(bigvalue_1,
                                   bigvalue_2)) {  // value_1 < value_2
      s21_big_sub(bigvalue_2, bigvalue_1, &bigresult);
      bigresult.bits[6] = bigresetBit(bigvalue_2, 223);
    }
  } else if (isSetBit(value_1, 127) ^ isSetBit(value_2, 127)) {  //+ -
    s21_big_add(bigvalue_1, bigvalue_2, &bigresult);
    if (bigisSetBit(bigvalue_1, 223)) {
      bigresult.bits[6] = bigsetBit(bigvalue_1, 223);
    } else {
      bigresult.bits[6] = bigresetBit(bigvalue_1, 223);
    }
  }
  int res = bigdecimal_to_decimal(result, bigresult);
  if (!result->bits[0] && !result->bits[1] && !result->bits[2]) {
    result->bits[3] = 0;
  }
  return res;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_bigdecimal bigvalue_1 = {0}, bigvalue_2 = {0}, bigresult = {0};
  decimal_to_bigdecimal(value_1, &bigvalue_1);
  decimal_to_bigdecimal(value_2, &bigvalue_2);
  s21_big_mul(bigvalue_1, bigvalue_2, &bigresult);
  int res = bigdecimal_to_decimal(result, bigresult);
  return res;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  memset(result, 0, sizeof(*result));
  int res = 0;
  if (!not_zerrodec(value_2)) {
    res = 3;  // 3 - деление на 0
  } else if (!not_zerrodec(value_1)) {
    memset(result, 0, sizeof(*result));
  } else {
    s21_bigdecimal big1, big2;
    decimal_to_bigdecimal(value_1, &big1);
    decimal_to_bigdecimal(value_2, &big2);
    s21_bigdecimal bigresult = {0};
    s21_big_div(big1, big2, &bigresult);
    res = bigdecimal_to_decimal(result, bigresult);
  }
  return res;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  memset(result, 0, sizeof(*result));
  int sign = isSetBit(value_1, 127);
  int res = 0;
  int degreeres = getDegree(value_1) > getDegree(value_2) ? getDegree(value_1)
                                                          : getDegree(value_2);
  s21_bigdecimal big1 = {0}, big2 = {0};
  s21_bigdecimal bigres = {0};
  decimal_to_bigdecimal(value_1, &big1);
  decimal_to_bigdecimal(value_2, &big2);
  s21_one_scale(&big1, &big2);

  if (!not_zerro(big2)) {
    res = 3;
    memset(result, 0, sizeof(*result));

  } else if (!not_zerro(big1)) {
    memset(result, 0, sizeof(*result));
  } else if (!big_is_greater_dop(big1, big2)) {
    decimal_copy_decimal(value_1, result);

  } else {
    s21_big_div(big1, big2, &bigres);
    int degreebig = big_getDegree(bigres);
    int count = degreebig;
    while (count > 0) {
      s21_divbig_10(&bigres);
      count--;
    }
    big_setDegree(&bigres, 0);
    s21_bigdecimal mulbig = {0};
    s21_big_mul(big2, bigres, &mulbig);
    s21_big_sub(big1, mulbig, &bigres);
    while (big_is_greater_dop(bigres, big2)) {
      s21_big_sub(bigres, big2, &bigres);
    }
    big_setDegree(&bigres, degreeres);
    res = bigdecimal_to_decimal(result, bigres);
    if (sign && !res && not_zerrodec(*result))
      result->bits[127 / 32] = setBit(*result, 127);
  }
  return res;
}

int s21_big_div(s21_bigdecimal big1, s21_bigdecimal big2,
                s21_bigdecimal *bigresult) {
  int degree1 = big_getDegree(big1);
  int degree2 = big_getDegree(big2);
  int sign = (bigisSetBit(big1, 223) && !bigisSetBit(big2, 223)) ||
                     (!bigisSetBit(big1, 223) && bigisSetBit(big2, 223))
                 ? 1
                 : 0;
  big1.bits[6] = 0;
  big2.bits[6] = 0;
  s21_bigdecimal one = {0};
  s21_bigdecimal tmp = {0};
  s21_bigdecimal sum = {0};
  s21_bigdecimal diff = {0};
  tmp.bits[0] = 1;
  one.bits[0] = 1;
  while (!s21_mulbig_10(&big1)) {
    degree1++;
  }
  s21_divbig_10(&big1);
  degree1--;
  // printf("\tdegree1 = %d\n", degree1);
  while (big_is_greater_dop(big1, big2)) {
    big_lshift(&big2);
    big_lshift(&tmp);
  }
  while (big_is_greater_dop(tmp, one) == 1) {
    big_rshift(&big2);
    big_rshift(&tmp);
    if (big_is_greater_dop(big1, big2)) {
      s21_big_sub(big1, big2, &diff);
      bigdecimal_copy_bigdecimal(diff, &big1);
      s21_big_add(*bigresult, tmp, &sum);
      bigdecimal_copy_bigdecimal(sum, bigresult);
    }
  }
  degree1 = degree1 - degree2;
  while (degree1 < 0) {
    s21_mulbig_10(bigresult);
    degree1++;
  }
  bigresult->bits[6] = sign << 31;
  big_setDegree(bigresult, degree1);
  return 0;
}

int s21_mul_10(s21_decimal *value) {
  int ret = 0;  // TRUE
  s21_decimal start = {0};
  decimal_copy_decimal(*value, &start);
  for (int i = 1; i < 10 && ret == 0; i++) {
    int sum = 0;
    int tmp = 0;
    int bit_v = 0;
    int bit_s = 0;
    for (int j = 0; j < 96; j++) {
      bit_v = isSetBit(*value, j);
      bit_s = isSetBit(start, j);
      sum = bit_v + bit_s + tmp;
      if (sum == 0) {
        value->bits[j / 32] = resetBit(*value, j);
        tmp = 0;
      } else if (sum == 1) {
        value->bits[j / 32] = setBit(*value, j);
        tmp = 0;
      } else if (sum == 2) {
        value->bits[j / 32] = resetBit(*value, j);
        tmp = 1;

      } else if (sum == 3) {
        value->bits[j / 32] = setBit(*value, j);
        tmp = 1;
      }
      if (j == 95 && sum > 1) {
        decimal_copy_decimal(start, value);
        ret = 1;  // FALSE
      }
    }
  }
  return ret;
}

int s21_mulbig_10(s21_bigdecimal *value) {
  int ret = 0;  // TRUE
  s21_bigdecimal start;
  bigdecimal_copy_bigdecimal(*value, &start);
  for (int i = 1; i < 10 && ret == 0; i++) {
    int sum = 0;
    int tmp = 0;
    int bit_v = 0;
    int bit_s = 0;
    for (int j = 0; j < 192; j++) {
      bit_v = bigisSetBit(*value, j);
      bit_s = bigisSetBit(start, j);
      sum = bit_v + bit_s + tmp;
      if (sum == 0) {
        value->bits[j / 32] = bigresetBit(*value, j);
        tmp = 0;
      } else if (sum == 1) {
        value->bits[j / 32] = bigsetBit(*value, j);
        tmp = 0;
      } else if (sum == 2) {
        value->bits[j / 32] = bigresetBit(*value, j);
        tmp = 1;

      } else if (sum == 3) {
        value->bits[j / 32] = bigsetBit(*value, j);
        tmp = 1;
      }
      if (j == 191 && sum > 1) {
        bigdecimal_copy_bigdecimal(start, value);
        ret = 1;  // FALSE
      }
    }
  }
  return ret;
}

int s21_divbig_10(s21_bigdecimal *value) {
  char str[60] = "\0";
  bigdecimal_to_str(*value, str);
  int res = str[strlen(str) - 1] - '0';
  str[strlen(str) - 1] = '\0';
  str_to_bigdecimal(value, str);
  return res;
}

int s21_div_10(s21_decimal *value) {
  char str[30] = "\0";
  decimal_to_str(*value, str);
  int res = str[strlen(str) - 1] - '0';
  str[strlen(str) - 1] = '\0';
  if (strlen(str) == 0) str[0] = '0';
  str_to_decimal(str, value);
  return res;
}

int s21_big_mul(s21_bigdecimal bigvalue_1, s21_bigdecimal bigvalue_2,
                s21_bigdecimal *bigresult) {
  s21_bigdecimal tmp_bigvalue_1 = {0}, tmp_bigvalue_2 = {0}, tmp = {0};
  bigdecimal_copy_bigdecimal(bigvalue_1,
                             &tmp_bigvalue_1);  //из bigvalue_1 в tmp_bigvalue_1
  bigdecimal_copy_bigdecimal(bigvalue_2, &tmp_bigvalue_2);
  for (int i = 0; i < 192; i++) {
    if (bigisSetBit(tmp_bigvalue_2, i)) {
      bigdecimal_copy_bigdecimal(bigvalue_1, &tmp);
      big_lshift_number(&tmp, i);
      s21_big_add(*bigresult, tmp, bigresult);
    }
  }
  int sign =
      (bigisSetBit(bigvalue_1, 223) && !bigisSetBit(bigvalue_2, 223)) ||
              (!bigisSetBit(bigvalue_1, 223) && bigisSetBit(bigvalue_2, 223))
          ? 1
          : 0;
  if (not_zerro(*bigresult)) {
    int degree = big_getDegree(bigvalue_1) + big_getDegree(bigvalue_2);
    big_setDegree(bigresult, degree);
  } else {
    sign = 0;
  }

  if (sign) {
    bigresult->bits[6] = bigsetBit(*bigresult, 223);
  }
  return 0;
}

int s21_one_scale(s21_bigdecimal *bigvalue_1, s21_bigdecimal *bigvalue_2) {
  s21_bigdecimal big_tmp_value_1 = {0};
  s21_bigdecimal big_tmp_value_2 = {0};
  bigdecimal_copy_bigdecimal(*bigvalue_1, &big_tmp_value_1);
  bigdecimal_copy_bigdecimal(*bigvalue_2, &big_tmp_value_2);
  int d1 = big_getDegree(big_tmp_value_1);
  int d2 = big_getDegree(big_tmp_value_2);
  int i = 0;
  while (d1 != d2) {
    if (d1 > d2) {
      i = d2;
      s21_mulbig_10(&big_tmp_value_2);
      big_setDegree(&big_tmp_value_2, ++i);
    } else if (d1 < d2) {
      i = d1;
      s21_mulbig_10(&big_tmp_value_1);
      big_setDegree(&big_tmp_value_1, ++i);
    }
    d1 = big_getDegree(big_tmp_value_1);
    d2 = big_getDegree(big_tmp_value_2);
  }
  bigdecimal_copy_bigdecimal(big_tmp_value_1,
                             bigvalue_1);  //из big_tmp_value_1 в bigvalue_1
  bigdecimal_copy_bigdecimal(big_tmp_value_2, bigvalue_2);
  return 0;
}

int s21_big_add(s21_bigdecimal bigvalue_1, s21_bigdecimal bigvalue_2,
                s21_bigdecimal *bigresult) {
  int tmp = 0, bit_of_first = 0, bit_of_second = 0;
  for (int i = 0; i < 192; i++) {
    bit_of_first = bigisSetBit(bigvalue_1, i);
    bit_of_second = bigisSetBit(bigvalue_2, i);

    if ((bit_of_first && bit_of_second)) {
      if (!tmp) {
        bigresult->bits[i / 32] = bigresetBit(*bigresult, i);
        tmp = 1;
      } else {
        bigresult->bits[i / 32] = bigsetBit(*bigresult, i);
        tmp = 1;
      }
    }
    if ((bit_of_first ^ bit_of_second)) {
      if (!tmp) {
        bigresult->bits[i / 32] = bigsetBit(*bigresult, i);
      } else {
        bigresult->bits[i / 32] = bigresetBit(*bigresult, i);
      }
    }
    if ((!bit_of_first && !bit_of_second && tmp)) {
      bigresult->bits[i / 32] = bigsetBit(*bigresult, i);
      tmp = 0;
    } else if (!bit_of_first && !bit_of_second && !tmp) {
      bigresult->bits[i / 32] = bigresetBit(*bigresult, i);
    }
  }
  int degree = big_getDegree(bigvalue_1);
  if (degree == big_getDegree(bigvalue_2)) {
    big_setDegree(bigresult, degree);
  }
  return 0;
}

int s21_big_sub(s21_bigdecimal bigvalue_1, s21_bigdecimal bigvalue_2,
                s21_bigdecimal *bigresult) {
  for (int i = 0; i < 192; i++) {
    bigvalue_2.bits[i / 32] = biginverseBit(bigvalue_2, i);
  }
  s21_bigdecimal bigadded = s21_plus_1(bigvalue_2);
  s21_big_add(bigvalue_1, bigadded, bigresult);
  return 0;
}

s21_bigdecimal s21_plus_1(s21_bigdecimal bigvalue_1) {
  s21_bigdecimal bigvalue_2 = {0}, bigresult = {0};
  bigvalue_2.bits[0] = 1u;
  for (int i = 1; i < 4; i++) bigvalue_2.bits[i] = 0u;
  int res = s21_big_add(bigvalue_1, bigvalue_2, &bigresult);
  if (res == 1) {
    for (int i = 0; i < 3; i++) bigresult.bits[i] = 0u;
  }
  return bigresult;
}

int not_zerro(s21_bigdecimal dec) {
  int res = 0;
  for (int i = 0; i < 6 && !res; i++) {
    if (dec.bits[i]) {
      res = 1;
    }
  }
  return res;
}

int not_zerrodec(s21_decimal dec) {
  int res = 0;
  for (int i = 0; i < 3 && !res; i++) {
    if (dec.bits[i]) {
      res = 1;
    }
  }
  return res;
}