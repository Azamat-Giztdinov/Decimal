#include "s21_decimal.h"

// проверка бита
int isSetBit(s21_decimal value, int bit) {
  return (value.bits[bit / 32] & (1 << (bit % 32))) != 0 ? 1 : 0;
}
int bigisSetBit(s21_bigdecimal value, int bit) {
  return (value.bits[bit / 32] & (1 << (bit % 32))) != 0 ? 1 : 0;
}

// установка бита в 1
int setBit(s21_decimal value, int bit) {
  return value.bits[bit / 32] | (1 << (bit % 32));
}
int bigsetBit(s21_bigdecimal value, int bit) {
  return value.bits[bit / 32] | (1 << (bit % 32));
}

// инверсия бита
int inverseBit(s21_decimal value, int bit) {
  return value.bits[bit / 32] ^ (1 << (bit % 32));
}
int biginverseBit(s21_bigdecimal value, int bit) {
  return value.bits[bit / 32] ^ (1 << (bit % 32));
}

// установка бита в 0
int resetBit(s21_decimal value, int bit) {
  return value.bits[bit / 32] & ~(1 << (bit % 32));
}
int bigresetBit(s21_bigdecimal value, int bit) {
  return value.bits[bit / 32] & ~(1 << (bit % 32));
}

// нахождение степени
int getDegree(s21_decimal value) { return resetBit(value, 127) >> 16; }
int big_getDegree(s21_bigdecimal value) {
  return bigresetBit(value, 223) >> 16;
}
// установка степени
void setDegree(s21_decimal* value, int degree) {
  int sign = isSetBit(*value, 127);
  value->bits[3] = (sign << 31) | (degree << 16);
}
void big_setDegree(s21_bigdecimal* value, int degree) {
  int sign = bigisSetBit(*value, 223);
  value->bits[6] = (sign << 31) | (degree << 16);
}

// копирование decimal
void decimal_copy_decimal(s21_decimal value, s21_decimal* result) {
  for (int i = 0; i < 4; i++) {
    result->bits[i] = value.bits[i];
  }
}
void bigdecimal_copy_bigdecimal(s21_bigdecimal value, s21_bigdecimal* result) {
  for (int i = 0; i < 7; i++) {
    result->bits[i] = value.bits[i];
  }
}

int is_greater_dop(s21_decimal value_1, s21_decimal value_2) {
  int res = -1;  // числа равны
  int bit1 = 0;
  int bit2 = 0;
  for (int i = 95; i >= 0 && res == -1; i--) {
    bit1 = isSetBit(value_1, i);
    bit2 = isSetBit(value_2, i);
    if (bit1 > bit2) {
      res = 1;  // value_1 > value_2 TRUE
    } else if (bit1 < bit2) {
      res = 0;  // value_1 < value_2 FALSE
    }
  }
  return res;
}

int big_is_greater_dop(s21_bigdecimal value_1, s21_bigdecimal value_2) {
  int res = -1;  // числа равны
  int bit1 = 0;
  int bit2 = 0;
  for (int i = 191; i >= 0 && res == -1; i--) {
    bit1 = bigisSetBit(value_1, i);
    bit2 = bigisSetBit(value_2, i);
    if (bit1 > bit2) {
      res = 1;  // value_1 > value_2 TRUE
    } else if (bit1 < bit2) {
      res = 0;  // value_1 < value_2 FALSE
    }
  }
  return res;
}

// смещение на один бит влево
int lshift(s21_decimal* value) {
  int res = 0;
  int low = isSetBit(*value, 31);
  int mid = isSetBit(*value, 63);
  int high = isSetBit(*value, 95);
  if (high) {
    res = 1;
  } else {
    value->bits[0] = (value->bits[0] << 1);
    value->bits[1] = (value->bits[1] << 1) | low;
    value->bits[2] = (value->bits[2] << 1) | mid;
  }
  return res;
}
int big_lshift(s21_bigdecimal* value) {
  int res = 0;
  int num1 = bigisSetBit(*value, 31);
  int num2 = bigisSetBit(*value, 63);
  int num3 = bigisSetBit(*value, 95);
  int num4 = bigisSetBit(*value, 127);
  int num5 = bigisSetBit(*value, 159);
  int num6 = bigisSetBit(*value, 191);
  if (num6) {
    res = 1;
  } else {
    value->bits[0] = (value->bits[0] << 1);
    value->bits[1] = (value->bits[1] << 1) | num1;
    value->bits[2] = (value->bits[2] << 1) | num2;
    value->bits[3] = (value->bits[3] << 1) | num3;
    value->bits[4] = (value->bits[4] << 1) | num4;
    value->bits[5] = (value->bits[5] << 1) | num5;
  }
  return res;
}

void big_rshift(s21_bigdecimal* value) {
  int num1 = bigisSetBit(*value, 32);
  int num2 = bigisSetBit(*value, 64);
  int num3 = bigisSetBit(*value, 96);
  int num4 = bigisSetBit(*value, 128);
  int num5 = bigisSetBit(*value, 160);
  value->bits[0] = (value->bits[0] >> 1) | (num1 << 31);
  value->bits[1] = (value->bits[1] >> 1) | (num2 << 31);
  value->bits[2] = (value->bits[2] >> 1) | (num3 << 31);
  value->bits[3] = (value->bits[3] >> 1) | (num4 << 31);
  value->bits[4] = (value->bits[4] >> 1) | (num5 << 31);
  value->bits[5] = (value->bits[5] >> 1);
}

int big_lshift_number(s21_bigdecimal* value, int number) {
  int flag = 0;
  int res = 0;
  while (number > 0 && flag == 0) {
    flag = big_lshift(value);
    number--;
    res++;
  }
  return res;
}