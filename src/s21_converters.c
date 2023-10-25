#include "s21_decimal.h"

//  Преобразователи

//Из int
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  memset(dst, 0, sizeof(*dst));
  int res = 0;
  if (src < s21_INF && src > -s21_INF) {
    if (src < 0) {
      dst->bits[3] = 1 << 31;
      src = -src;
    }
    dst->bits[0] = src;
  } else {
    res = 1;
  }
  return res;
}

//Из float
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  memset(dst, 0, sizeof(*dst));
  int res = 0;
  int sign = src < 0.0 ? 1 : 0;
  if (src < 0.0) {
    src = -src;
  }
  if (src < MAX_DECIMAL) {
    int step = 0;
    for (; !(int)src && step < MAX_POW;) {
      step++;
      src *= 10;
    }
    for (int i = 0; step < MAX_POW && i < FLOAT; i++) {
      src *= 10;
      step++;
    }
    int remains1 = (int)((src - floorl(src)) * 10);
    if (!(int)src || src > MAX_DECIMAL) {
      res = 1;
    } else {
      for (int i = 0; i < MAX_BIT && src > ACCURACY; i++) {
        src = floorl(src) / 2;
        if (src - floorl(src) > ACCURACY) {
          dst->bits[i / 32] = setBit(*dst, i);
        }
      }
      if (remains1 > 5) {
        s21_decimal one = {0};
        one.bits[0] = 1;
        s21_add(*dst, one, dst);
      }
      char strfloat[50] = "\0";
      decimal_to_str(*dst, strfloat);
      int len = strlen(strfloat);
      int remains2 = 0;
      while (len > 7) {
        len--;
        step--;
        remains2 = strfloat[len] - '0';
        strfloat[len] = '\0';
      }
      if (remains2 >= 5 && strfloat[len - 1] < '9') {
        str_add_one(strfloat);
      }
      str_to_decimal(strfloat, dst);
      while (step < 0) {
        step++;
        s21_mul_10(dst);
      }
      setDegree(dst, step);
      if (sign) dst->bits[127 / 32] = setBit(*dst, 127);
    }
    if (!not_zerrodec(*dst)) {
      memset(dst, 0, sizeof(*dst));
    }
  } else if (src == MAX_DECIMAL || src == -MAX_DECIMAL) {
    dst->bits[0] = 7922816;
    while (!s21_mul_10(dst)) {
    }
    if (sign) dst->bits[127 / 32] = setBit(*dst, 127);
  } else {
    res = 1;
  }
  return res;
}

//В int
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  *dst = 0;
  int res = 0;
  int degree = getDegree(src);
  while (degree > 0) {
    s21_div_10(&src);
    degree--;
  }
  s21_decimal max = {0};
  max.bits[0] = 2147483648u;
  if (is_greater_dop(max, src) == 1) {
    *dst = src.bits[0];
    if (isSetBit(src, 127)) {
      *dst = -*dst;
    }
  } else if (is_greater_dop(max, src) == -1 && isSetBit(src, 127)) {
    *dst = src.bits[0];
  } else {
    res = 1;
    if (isSetBit(src, 127)) {
      *dst = -2147483647;
    } else {
      *dst = 2147483647;
    }
  }
  return res;
}

//В float
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = 0;
  int degree = getDegree(src);
  *dst = 0;
  s21_decimal max = {0};
  max.bits[0] = 10000000;
  while (is_greater_dop(max, src) != 1) {
    s21_div_10(&src);
    degree--;
  }
  for (int i = 0; i < 96; i++) {
    if (isSetBit(src, i)) {
      *dst += powl(2.0, i);
    }
  }
  if (degree > 0) {
    for (; degree > 0; degree--) {
      *dst /= 10;
    }
  } else {
    while (degree < 0) {
      degree++;
      *dst *= 10;
    }
  }
  if (isSetBit(src, 127)) *dst = -*dst;
  return res;
}
