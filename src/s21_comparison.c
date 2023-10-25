#include "s21_decimal.h"

int check_degree(s21_decimal *a,
                 s21_decimal *b) {  // приводит к одинаковой степени
  int res = 1;
  if (getDegree(*a) < getDegree(*b)) {
    while (getDegree(*a) != getDegree(*b) && res == 1) {
      res = !s21_mul_10(a);  // вот здесь 10 представить в виде децимала
                             //   a * 10; // это арифметическая операция
      setDegree(a, getDegree(*a) + 1);
    }
  } else if (getDegree(*a) > getDegree(*b)) {
    while (getDegree(*a) != getDegree(*b) && res == 1) {
      res = !s21_mul_10(b);
      // b * 10; // это арифметическая операция
      setDegree(b, getDegree(*b) + 1);
    }
  }
  return res;
}

int s21_is_equal(s21_decimal a, s21_decimal b) {
  int res = TRUE;
  res = check_degree(&a, &b);
  if (not_zerrodec(a) == 0 && not_zerrodec(b) == 0) {
    res = TRUE;
  } else if (isSetBit(a, 127) != isSetBit(b, 127))
    res = FALSE;
  else if (res) {
    for (int i = 0; i < 96; i++) {
      if (isSetBit(a, i) != isSetBit(b, i)) {
        res = FALSE;
        i = 96;
      }
    }
  }
  return res;
}

int s21_is_less(s21_decimal a, s21_decimal b) {  // если первое меньше - TRUE
  int res = TRUE;
  if (s21_is_not_equal(a, b)) {
    if ((isSetBit(a, 127) != isSetBit(b, 127) && isSetBit(a, 127) == 0)) {
      res = FALSE;
    } else if (isSetBit(a, 127) == isSetBit(b, 127)) {
      res = check_degree(&a, &b);
      if (res == FALSE) {
        if (getDegree(a) > getDegree(b) && isSetBit(a, 127) == 0) {
          res = TRUE;
        } else if (getDegree(a) < getDegree(b) && isSetBit(a, 127)) {
          res = TRUE;
        }
      } else {
        if (isSetBit(a, 127)) {
          res = is_greater_dop(a, b);
        } else {
          res = is_greater_dop(b, a);
        }
      }
    }
  } else {
    res = FALSE;
  }
  return res;
}

int s21_is_greater_or_equal(s21_decimal a, s21_decimal b) {
  check_degree(&a, &b);
  int res = FALSE;
  if (s21_is_equal(a, b) || s21_is_greater(a, b)) {
    res = TRUE;
  }
  return res;
}

int s21_is_less_or_equal(s21_decimal a,
                         s21_decimal b)  // если первое меньше или равно - TRUE
{
  check_degree(&a, &b);

  int res = FALSE;
  if (s21_is_equal(a, b) || s21_is_less(a, b)) {
    res = TRUE;
  }
  return res;
}

int s21_is_greater(s21_decimal a, s21_decimal b) {  // если первое больше - TRUE
  int res = FALSE;
  check_degree(&a, &b);
  if (s21_is_less(a, b) == FALSE && s21_is_not_equal(a, b) == TRUE) {
    res = TRUE;
  }
  return res;
}

int s21_is_not_equal(s21_decimal a, s21_decimal b) {
  int res = FALSE;
  check_degree(&a, &b);
  if (s21_is_equal(a, b) == FALSE) {
    res = TRUE;
  }
  return res;
}
