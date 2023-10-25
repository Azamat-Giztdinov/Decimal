#include "s21_decimal.h"

void reverse(char* str, int start, int end) {
  char tmp = '\0';
  for (int j = start, i = end; j < i; j++, i--) {
    tmp = str[j];
    str[j] = str[i];
    str[i] = tmp;
  }
}

void decimal_to_str(s21_decimal value, char* str) {
  for (int i = 0; i < 29; i++) {
    str[i] = '0';
    str[i + 1] = '\0';
  }
  for (int i = 0; i < 96; i++) {
    if (isSetBit(value, i)) {
      char strdop[30] = "10000000000000000000000000000";
      for (int j = 0; j < i; j++) {
        char strtmp[30] = "00000000000000000000000000000";
        for (int k = 0; k < 29; k++) {
          int tmp = ((int)strdop[k] - 48) * 2;
          strtmp[k] = (char)((int)strtmp[k] + tmp % 10);
          strtmp[k + 1] = (char)((int)strtmp[k + 1] + (int)(tmp / 10));
          if (strtmp[k] > 57) {
            strtmp[k] = (char)((int)strtmp[k] - 10);
            strtmp[k + 1] = (char)((int)strtmp[k + 1] + 1);
          }
        }
        for (int k = 0; k < 29; k++) {
          strdop[k] = strtmp[k];
        }
      }
      str_add_str(str, strdop);
    }
  }
  int end = 28;
  for (int i = 28; i > 0; i--) {
    if (str[i] == '0') {
      str[i] = '\0';
      end--;
    } else {
      i = 0;
    }
  }
  reverse(str, 0, end);
}

void bigdecimal_to_str(s21_bigdecimal value, char* str) {
  for (int i = 0; i < 58; i++) {
    str[i] = '0';
    str[i + 1] = '\0';
  }
  for (int i = 0; i < 192; i++) {
    if (bigisSetBit(value, i)) {
      char strdop[59] =
          "1000000000000000000000000000000000000000000000000000000000";
      for (int j = 0; j < i; j++) {
        char strtmp[59] =
            "0000000000000000000000000000000000000000000000000000000000";
        for (int k = 0; k < 58; k++) {
          int tmp = ((int)strdop[k] - 48) * 2;
          strtmp[k] = (char)((int)strtmp[k] + tmp % 10);
          strtmp[k + 1] = (char)((int)strtmp[k + 1] + (int)(tmp / 10));
          if (strtmp[k] > 57) {
            strtmp[k] = (char)((int)strtmp[k] - 10);
            strtmp[k + 1] = (char)((int)strtmp[k + 1] + 1);
          }
        }
        for (int k = 0; k < 58; k++) {
          strdop[k] = strtmp[k];
        }
      }
      big_str_add_str(str, strdop);
    }
  }
  int end = 57;
  for (int i = 57; i > 0; i--) {
    if (str[i] == '0') {
      str[i] = '\0';
      end--;
    } else {
      i = 0;
    }
  }
  reverse(str, 0, end);
}

void str_to_decimal(const char* str, s21_decimal* value) {
  memset(value, 0, sizeof(*value));
  // int res = 1;  // true
  int len = strlen(str);
  char strcop[len + 1];
  sprintf(strcop, "%s", str);
  reverse(strcop, 0, len - 1);
  if (strcop[len - 1] == '-') {
    value->bits[3] = setBit(*value, 127);
    len--;
    strcop[len] = '\0';
  }
  reverse(strcop, 0, len - 1);
  int degree = 0;
  int i = 0;
  while ((strcop[i] != '.' && strcop[i] != ',') && i < len) {
    i++;
  }
  if (strcop[i] == '.' || strcop[i] == ',') {
    degree = len - 1 - i;
    for (int j = i; j < len; j++) {
      strcop[j] = strcop[j + 1];
    }
    len--;
  }
  while (len > 29 && degree) {
    strcop[len - 1] = '\0';
    len--;
    degree--;
  }
  if (len > 29) {
    memset(value, 0, sizeof(*value));
    // res = 0;  // false
  } else {
    setDegree(value, degree);
    strnorm_to_decimal(value, strcop);
  }
  // return res;
}

void str_to_bigdecimal(s21_bigdecimal* value, const char* str) {
  memset(value, 0, sizeof(*value));
  // int res = 1;  // true
  int len = strlen(str);
  char strcop[len + 1];
  sprintf(strcop, "%s", str);
  reverse(strcop, 0, len - 1);
  if (strcop[len - 1] == '-') {
    value->bits[6] = bigisSetBit(*value, 223);
    len--;
    strcop[len] = '\0';
  }
  reverse(strcop, 0, len - 1);
  int degree = 0;
  int i = 0;
  while ((strcop[i] != '.' && strcop[i] != ',') && i < len) {
    i++;
  }
  if (strcop[i] == '.' || strcop[i] == ',') {
    degree = len - 1 - i;
    for (int j = i; j < len; j++) {
      strcop[j] = strcop[j + 1];
    }
    len--;
  }
  while (len > 58 && degree) {
    strcop[len - 1] = '\0';
    len--;
    degree--;
  }
  if (len > 58) {
    memset(value, 0, sizeof(*value));
    // res = 0;  // false
  } else {
    big_setDegree(value, degree);
    strnorm_to_bigdecimal(value, strcop);
  }
  // return res;
}

void strnorm_to_decimal(s21_decimal* value, char* str) {
  int len = strlen(str);
  char strbit[97] = "\0";
  reverse(str, 0, len - 1);
  while (str[len - 1] == '0') {
    len--;
    str[len] = '\0';
  }
  reverse(str, 0, len - 1);
  while (len > 1) {
    int tmp = 0;
    char strdop[30] = "\0";
    if ((int)str[len - 1] % 2) {
      strcat(strbit, "1");
    } else {
      strcat(strbit, "0");
    }
    for (int i = 0; i < len; i++) {
      tmp = tmp * 10 + (int)str[i] - (int)'0';
      if (tmp > 1) {
        int number = tmp / 2;
        if (tmp % 2 == 0) {
          tmp = 0;
        } else {
          tmp = 1;
        }
        char strnum[2];
        sprintf(strnum, "%d", number);
        strcat(strdop, strnum);
      } else {
        if (strlen(strdop)) {
          strcat(strdop, "0");
        }
      }
    }
    sprintf(str, "%s", strdop);
    len = strlen(str);
  }
  int number = 0;
  if (len) number = (int)str[0] - (int)'0';
  while (number) {
    if (number % 2) {
      strcat(strbit, "1");
    } else {
      strcat(strbit, "0");
    }
    number /= 2;
  }
  for (int i = strlen(strbit) - 1; i >= 0; i--) {
    lshift(value);
    if (strbit[i] == '1') {
      value->bits[0] = setBit(*value, 0);
    }
  }
}

void strnorm_to_bigdecimal(s21_bigdecimal* value, char* str) {
  int len = strlen(str);
  char strbit[193] = "\0";
  reverse(str, 0, len - 1);
  while (str[len - 1] == '0') {
    len--;
    str[len] = '\0';
  }
  reverse(str, 0, len - 1);
  while (len > 1) {
    int tmp = 0;
    char strdop[59] = "\0";
    if ((int)str[len - 1] % 2) {
      strcat(strbit, "1");
    } else {
      strcat(strbit, "0");
    }
    for (int i = 0; i < len; i++) {
      tmp = tmp * 10 + (int)str[i] - (int)'0';
      if (tmp > 1) {
        int number = tmp / 2;
        if (tmp % 2 == 0) {
          tmp = 0;
        } else {
          tmp = 1;
        }
        char strnum[2];
        sprintf(strnum, "%d", number);
        strcat(strdop, strnum);
      } else {
        if (strlen(strdop)) {
          strcat(strdop, "0");
        }
      }
    }
    sprintf(str, "%s", strdop);
    len = strlen(str);
  }
  int number = 0;
  if (len) number = (int)str[0] - (int)'0';
  while (number) {
    if (number % 2) {
      strcat(strbit, "1");
    } else {
      strcat(strbit, "0");
    }
    number /= 2;
  }
  for (int i = strlen(strbit) - 1; i >= 0; i--) {
    big_lshift(value);
    if (strbit[i] == '1') {
      value->bits[0] = bigsetBit(*value, 0);
    }
  }
}

void big_str_add_str(char* str, char* value) {
  for (int i = 0; i < 58; i++) {
    str[i] = (char)((int)str[i] + (int)value[i] - (int)'0');
    if ((int)str[i] > 57) {
      str[i] = (char)((int)str[i] - 10);
      str[i + 1] = (char)((int)str[i + 1] + 1);
    }
  }
}

void str_add_str(char* str, char* value) {
  for (int i = 0; i < 29; i++) {
    str[i] = (char)((int)str[i] + (int)value[i] - (int)'0');
    if ((int)str[i] > 57) {
      str[i] = (char)((int)str[i] - 10);
      str[i + 1] = (char)((int)str[i + 1] + 1);
    }
  }
}

int not_str_is_equalbig(char* str) {
  int res = 0;
  char bigdec[30] = "79228162514264337593543950335";
  for (int i = 0; i < 30 && !res; i++) {
    if (str[i] != bigdec[i]) res = 1;
  }
  return res;
}
void str_add_one(char* str) {
  int len = strlen(str);
  str[len - 1] = str[len - 1] + 1;
  for (int i = len - 1; i > 0; i--) {
    if (str[i] > '9') {
      str[i] = str[i] - 10;
      str[i - 1] += 1;
    }
  }
}