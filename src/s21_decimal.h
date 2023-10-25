#ifndef S21_DECIMAL_H_
#define S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <string.h>

#define s21_INF 1.0 / 0.0
#define MAX_POW 28
#define MAX_DECIMAL powl(2.0, 96)
#define LOW_DECIMAL powl(2.0, 32)
#define FLOAT 6
#define MAX_BIT 96
#define ACCURACY powl(10.0, -FLOAT - 1)
#define TRUE 1
#define FALSE 0

typedef struct {
  unsigned int bits[4u];
} s21_decimal;

typedef struct {
  unsigned int bits[7u];
} s21_bigdecimal;

//      Арифметические операторы

//Сложение
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
//Вычитание
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
//Умножение
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
//Деление
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
//Остаток от деления
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

// Функции возвращают код ошибки:
// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0

//      Операторы сравнение

//Меньше
int s21_is_less(s21_decimal, s21_decimal);
//Меньше или равно
int s21_is_less_or_equal(s21_decimal, s21_decimal);
//Больше
int s21_is_greater(s21_decimal, s21_decimal);
//Больше или равно
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
//Равно
int s21_is_equal(s21_decimal, s21_decimal);
//Не равно
int s21_is_not_equal(s21_decimal, s21_decimal);

// Возвращаемое значение:
// 0 - FALSE
// 1 - TRUE

//       Преобразователи

// +++ Из int
int s21_from_int_to_decimal(int src, s21_decimal* dst);
//Из float
int s21_from_float_to_decimal(float src, s21_decimal* dst);
// +++ В int
int s21_from_decimal_to_int(s21_decimal src, int* dst);
// +++ В float
int s21_from_decimal_to_float(s21_decimal src, float* dst);

// Возвращаемое значение - код ошибки:
// 0 - OK
// 1 - ошибка конвертации

//      Другие функции

//Округляет указанное Decimal число до ближайшего целого числа в сторону
//отрицательной бесконечности.
int s21_floor(s21_decimal value, s21_decimal* result);
//Округляет Decimal до ближайшего целого числа.
int s21_round(s21_decimal value, s21_decimal* result);
//Возвращает целые цифры указанного Decimal числа; любые дробные цифры
//отбрасываются, включая конечные нули.
int s21_truncate(s21_decimal value, s21_decimal* result);
// +++ Возвращает результат умножения указанного Decimal на -1.
int s21_negate(s21_decimal value, s21_decimal* result);

// Возвращаемое значение - код ошибки:
// 0 - OK
// 1 - ошибка вычисления

//      Дополнительные функции
// проверка бита
int isSetBit(s21_decimal value, int bit);
// установка бита в 1
int setBit(s21_decimal value, int bit);
// инверсия бита
int inverseBit(s21_decimal value, int bit);
// установка бита в 0
int resetBit(s21_decimal value, int bit);

int bigisSetBit(s21_bigdecimal value, int bit);
int bigsetBit(s21_bigdecimal value, int bit);
int biginverseBit(s21_bigdecimal value, int bit);
int bigresetBit(s21_bigdecimal value, int bit);

// смещение на один бит влево
int lshift(s21_decimal* value);
int big_lshift(s21_bigdecimal* value);
// смещение на number бит влево
int big_lshift_number(s21_bigdecimal* value, int number);

// смещение на один бит вправо
void big_rshift(s21_bigdecimal* value);

// нахождение степени
int getDegree(s21_decimal value);
int big_getDegree(s21_bigdecimal value);
// установка степени
void setDegree(s21_decimal* value, int degree);
void big_setDegree(s21_bigdecimal* value, int degree);

// умножение decimal на  10
int s21_mul_10(s21_decimal* value);
int s21_mulbig_10(s21_bigdecimal* value);
// деление decimal на 10
int s21_divbig_10(s21_bigdecimal* value);
int s21_div_10(s21_decimal* value);

//сравнение децимал без учета знака и степени
int is_greater_dop(s21_decimal value_1, s21_decimal value_2);
int big_is_greater_dop(s21_bigdecimal value_1, s21_bigdecimal value_2);

// копирование decimal
void decimal_copy_decimal(s21_decimal value, s21_decimal* result);
void bigdecimal_copy_bigdecimal(s21_bigdecimal value, s21_bigdecimal* result);

// разворот строки
void reverse(char* str, int start, int end);

// преобразование десимал в строку без точко=и
void decimal_to_str(s21_decimal value, char* str);
void bigdecimal_to_str(s21_bigdecimal value, char* str);

void str_add_str(char* str, char* value);
void big_str_add_str(char* str, char* value);
void str_add_one(char* str);

// преобразование строки в децимал
void str_to_decimal(const char* str, s21_decimal* value);

void str_to_bigdecimal(s21_bigdecimal* value, const char* str);

// преобразование строки в децимал без точки, используется функцией str to
// decimal
void strnorm_to_decimal(s21_decimal* value, char* str);
void strnorm_to_bigdecimal(s21_bigdecimal* value, char* str);

// преобразование децимал в бигдецимал
void decimal_to_bigdecimal(s21_decimal dec, s21_bigdecimal* bigdec);
// преобразование бигдецимал в децимал
int bigdecimal_to_decimal(s21_decimal* dec, s21_bigdecimal bigdec);

int s21_big_div(s21_bigdecimal big1, s21_bigdecimal big2,
                s21_bigdecimal* bigresult);
// сложение бигдецималов
int s21_big_add(s21_bigdecimal bigvalue_1, s21_bigdecimal bigvalue_2,
                s21_bigdecimal* bigresult);
s21_bigdecimal s21_plus_1(s21_bigdecimal bigvalue_1);
// вычетание бигдецималов
int s21_big_sub(s21_bigdecimal bigvalue_1, s21_bigdecimal bigvalue_2,
                s21_bigdecimal* bigresult);
int s21_big_mul(s21_bigdecimal value_1, s21_bigdecimal value_2,
                s21_bigdecimal* result);
int s21_one_scale(s21_bigdecimal* bigvalue_1, s21_bigdecimal* bigvalue_2);

// проверка децимала на 0
int not_zerro(s21_bigdecimal dec);
int not_zerrodec(s21_decimal dec);
// проверка на о что децимал в строковом виде меньше максимального значения
int not_str_is_equalbig(char* str);

// приводит к одинаковой степени
int check_degree(s21_decimal* a, s21_decimal* b);

#endif  // S21_DECIMAL_H_
