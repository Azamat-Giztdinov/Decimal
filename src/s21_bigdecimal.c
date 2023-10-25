#include "s21_decimal.h"

void decimal_to_bigdecimal(s21_decimal dec, s21_bigdecimal* bigdec) {
  memset(bigdec, 0, sizeof(*bigdec));
  for (int i = 0; i < 6; i++) {
    if (i == 3) {
      bigdec->bits[i + 3] = dec.bits[i];
      bigdec->bits[i] = 0;
    } else if (i > 3) {
      bigdec->bits[i] = 0;
    } else {
      bigdec->bits[i] = dec.bits[i];
    }
  }
}

int bigdecimal_to_decimal(s21_decimal* dec, s21_bigdecimal bigdec) {
  memset(dec, 0, sizeof(*dec));
  int res = 0;
  char strbig[59] = "\0";
  bigdecimal_to_str(bigdec, strbig);
  int degree = big_getDegree(bigdec);
  int lenstr = strlen(strbig);
  int sign = bigisSetBit(bigdec, 223);
  int sum_float = 0;
  int number = 0;
  while (degree > 28 && lenstr) {
    degree--;
    sum_float += strbig[lenstr - 1] - '0';
    number = strbig[lenstr - 1] - '0';
    strbig[lenstr - 1] = '\0';
    lenstr--;
  }

  while (lenstr > 29) {
    degree--;
    sum_float += strbig[lenstr - 1] - '0';
    number = strbig[lenstr - 1] - '0';
    strbig[lenstr - 1] = '\0';
    lenstr--;
  }
  if (lenstr == 29) {
    s21_bigdecimal dop = {0};
    str_to_bigdecimal(&dop, strbig);
    int big = bigisSetBit(dop, 96);
    if (big && degree <= 0) {
      res = 1;
      if (sign) res = 2;
    } else if (big) {
      degree--;
      sum_float += strbig[lenstr - 1] - '0';
      number = strbig[lenstr - 1] - '0';
      strbig[lenstr - 1] = '\0';
      lenstr--;
    }
  }
  if (degree < 0) {
    memset(dec, 0, sizeof(*dec));
    res = 1;  // 1 - число слишком велико или равно бесконечности
    if (sign) res = 2;
  } else if (res == 0) {
    sum_float -= number;
    if (not_str_is_equalbig(strbig)) {
      if (number > 5 || (number == 5 && sum_float > 0)) {
        str_add_one(strbig);
      } else if (number == 5 && strbig[lenstr - 1] % 2) {
        str_add_one(strbig);
      }
    }
    while (degree > 0 && strbig[lenstr - 1] == '0' && lenstr > 1) {
      strbig[lenstr - 1] = '\0';
      degree--;
      lenstr--;
    }
    str_to_decimal(strbig, dec);
    setDegree(dec, degree);
    if (sign) dec->bits[127 / 32] = setBit(*dec, 127);
  }

  return res;
}
