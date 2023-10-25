#include "s21_decimal.h"
// Возвращает результат умножения указанного Decimal на -1.
int s21_negate(s21_decimal value, s21_decimal *result) {
  decimal_copy_decimal(value, result);
  result->bits[3] = inverseBit(*result, 127);
  return 0;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  memset(result, 0, sizeof(*result));
  int degr = getDegree(value);
  int sign = isSetBit(value, 127);

  if (degr && !not_zerrodec(value)) {
    result->bits[3] = 0;
  } else {
    for (int i = 0; i < degr; i++) {
      s21_div_10(&value);
    }
    setDegree(&value, 0);
    if (sign) value.bits[3] = setBit(value, 127);
    decimal_copy_decimal(value, result);
    if (isSetBit(*result, 127) == 1 && degr != 0) {
      s21_decimal one;
      s21_from_int_to_decimal(1, &one);

      s21_sub(*result, one, result);
    }
    if (!not_zerrodec(*result)) {
      result->bits[3] = 0;
    }
  }
  return 0;
}

int s21_round(s21_decimal value,
              s21_decimal *result)  // тут еще проверить -0, +0
{
  memset(result, 0, sizeof(*result));
  int sign = isSetBit(value, 127);
  int degree = getDegree(value);
  value.bits[3] = 0;
  int sum = 0;
  int number = 0;
  while (degree > 1) {
    sum += s21_div_10(&value);
    degree--;
  }
  if (degree == 1) {
    number = s21_div_10(&value);
  }
  decimal_copy_decimal(value, result);
  s21_decimal mod = {0};
  s21_from_int_to_decimal(10, &mod);
  s21_mod(value, mod, &mod);
  if (number > 5 || (number == 5 && sum > 0) ||
      (number == 5 && mod.bits[0] % 2)) {
    s21_from_int_to_decimal(1, &mod);
    s21_add(value, mod, result);
  }
  if (sign && not_zerrodec(*result)) result->bits[3] = setBit(*result, 127);
  return 0;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int sign = isSetBit(value, 127);
  int degr = getDegree(value);
  for (int i = 0; i < degr; i++) {
    s21_div_10(&value);
  }
  decimal_copy_decimal(value, result);
  setDegree(result, 0);
  if (sign == 1 && not_zerrodec(*result))
    result->bits[3] = setBit(*result, 127);
  return 0;
}
