#include "s21_math.h"

#include <stdio.h>

/**
 * Вычисляет синус
 * @param x угол в радианах
 * @param Владимир
 * @return синус угла
 */
long double s21_sin(double x) {
  long double y;
  int a = 1;
  if (x == x && x != s21_INF && x != -s21_INF) {
    int n = 1;
    if (s21_fabs(x) >= 2 * S21_PI) x = s21_fmod(x, (2 * S21_PI));
    if (x >= S21_PI) x -= S21_PI, a = -1;
    long double sn = x;
    y = x;
    while (s21_fabs(sn) > EPS20) {
      sn *= -1.0 * x * x / ((2 * n) * (2 * n + 1));
      y += sn;
      n++;
    }
  }
  if (x != x || x == s21_INF || x == -s21_INF) y = s21_NAN;
  return a * y;
}

/**
 * Вычисляет косинус
 * @param x угол в радианах
 * @param Андрей
 * @return косинус угла
 */
long double s21_cos(double x) { return s21_sin(S21_PI / 2 - x); }

/**
 * Вычисляет тангенс
 * @param x угол в радианах
 * @param Андрей
 * @return тангенс угла
 */
long double s21_tan(double x) {
  long double res = s21_cos(x);
  if (res != 0.0)
    res = s21_sin(x) / res;
  else
    res = s21_NAN;
  return res;
}

/**
 * Возвращает значение e, возведенное в заданную степень
 * @param x степень
 * @param Владимир
 * @return результат возведения в степень
 */
long double s21_exp(double x) {
  long double y = 1.0;
  if (x == x && x != s21_INF && x != -s21_INF) {
    int n = 1;
    long double a = x, sn = 1;
    if (x < 0.0) a = -x;
    while (sn > EPS20) {
      sn *= a / n++;
      y += sn;
    }
    if (x < 0.0) y = 1 / y;
  }

  if (x == s21_INF) y = s21_INF;
  if (x != x) y = s21_NAN;
  if (x == -s21_INF) y = 0;
  return y;
}

/**
 * Вычисляет логарифм числа
 * @param x число
 * @param Никита
 * @return логарифм числа
 */
long double s21_log(double x) {
  long double result = 0.0;
  if (x > 0 && x != s21_INF && x != -s21_INF && x == x) {
    long double a = x;
    int n = 2, ex = 1, st = 0;
    while (a < 0.1) a *= 10, st--;
    while (a > 1) a /= 10, st++;

    a -= 1;
    long double y = a, sn = a;
    while (ex) {
      sn *= -a;
      if (s21_fabs(sn / n) < EPS20) ex = 0;
      y += sn / n++;
    }
    result = y + st * S21_LN10;
  }
  if (x == s21_INF) result = s21_INF;
  if (x < 0 || x == -s21_INF || x != x) result = -s21_NAN;
  if (x == 0) result = -s21_INF;
  return result;
}

/**
 * Вычисляет корень числа
 * @param x число
 * @param Никита
 * @return корень числа
 */
long double s21_sqrt(double x) {
  int val = 1;
  while (x > 100 && x != s21_INF && x != -s21_INF && x == x)
    x /= 100, val *= 10;
  return val * s21_exp(s21_log(x) / 2);
}

/**
 * Вычисляет арктангенс
 * @param x угол в радианах
 * @param Владимир
 * @return арктангенс угла
 */
long double s21_atan(double x) {
  long double y;
  if (x == x && x != s21_INF && x != -s21_INF && s21_fabs(x) != 1) {
    long double a = x;
    if (s21_fabs(x) > 1) a = 1 / x;
    if (x < 0.0) a = -a;
    int n = 1, ex = 1;
    y = a;
    long double sn = a;
    while (ex) {
      sn *= (-1.0) * a * a;
      long double temp = sn / (2 * n++ + 1);
      if (s21_fabs(temp) < EPS20) ex = 0;
      y += temp;
    }
    if (s21_fabs(x) > 1) y = S21_PI / 2 - y;
    if (x < 0) y *= -1;
  }
  if (x == -1) y = -S21_PI / 4;
  if (x == 1) y = S21_PI / 4;
  if (x != x) y = -s21_NAN;
  if (x == s21_INF) y = S21_PI / 2;
  if (x == -s21_INF) y = -S21_PI / 2;
  return y;
}

/**
 * Вычисляет арксинус
 * @param x угол в радианах
 * @param Андрей
 * @return арксинус угла
 */
long double s21_asin(double x) {
  long double res = 0;
  if (x == x && x != s21_INF && x != -s21_INF) {
    if (x == -1.0) res = -0.5 * S21_PI;
    if (x == 1.0) res = 0.5 * S21_PI;
    if (x < 1 && x > -1) res = s21_atan(x / s21_sqrt(1.0 - (x * x)));
  }
  if (x > 1 || x < -1 || x != x) res = s21_NAN;

  return res;
}

/**
 * Вычисляет арккосинус
 * @param x угол в радианах
 * @param Никита
 * @return арккосинус угла
 */
long double s21_acos(double x) {
  long double res;
  if (x < -1 || x > 1)
    res = s21_NAN;
  else
    res = S21_PI / 2 - s21_asin(x);
  return res;
}

/**
 * возводит число в заданную степень
 *
 * @param base число с плавающей точкой - основание
 * @param exp число с плавающей точкой - степень
 * @param Андрей
 * @return long double число, возведенное в заданную степень
 */
long double s21_pow(double base, double exp) {
  double res = base;

  if (exp == exp && exp != s21_INF && exp != -s21_INF && base == base) {
    int is_negative = 0, is_int = 0;
    if ((int)exp == exp) is_int = 1;
    if (exp == 0) res = 1;
    if (exp < 0) {
      exp = s21_fabs(exp);
      is_negative = 1;
    }
    if (is_int == 1 && exp != 0) {
      while (exp > 1) {
        res = res * base;
        exp--;
      }
    }
    if (is_int == 0) {
      if (base > 0)
        res = s21_exp(exp * s21_log(base));
      else if (base == 0)
        res = 0;
      else
        res = -s21_NAN;
    }
    if (is_negative == 1) res = 1 / res;

    if (base == -s21_INF && exp > 1) res = s21_INF;
    if (base == -s21_INF && exp < 1) res = 0;
  }
  if (exp == -s21_INF) res = 0;
  if (exp == s21_INF) res = s21_INF;
  if (base != base || exp != exp) res = s21_NAN;
  if (base > 0 && base != s21_INF && (exp == -s21_INF || exp == s21_INF))
    res = 0;
  if (base == 1.0 || exp == 0.0) res = 1;
  if (base == -1.0 && (exp == -s21_INF || exp == s21_INF)) res = 1;
  return res;
}

/**
 * Вычисляет абсолютное значение целого числа
 * @param x целое число
 * @param Владимир
 * @return абсолютное значение целого числа
 */
int s21_abs(int x) {
  int y = x;
  if (x != s21_INF && x != -s21_INF)
    if (x < 0.0) y = -x;
  if (x == s21_INF || x == -s21_INF) y = s21_NAN;
  return y;
}

/**
 * Вычисляет модуль числа с плавающей запятой
 * @param x число с плавающей запятой
 * @param Никита
 * @return модуль числа
 */
long double s21_fabs(double x) {
  long double inum;
  if (x == x && x != s21_INF && x != -s21_INF) {
    if (x >= 0.0) {
      inum = x;
    } else {
      inum = x - x * 2;
    }
  }
  if (x != x) inum = s21_NAN;
  if (x == s21_INF) inum = s21_INF;
  if (x == -s21_INF) inum = -s21_INF;
  return inum;
}

/**
 * Остаток операции деления с плавающей точкой
 * @param x что делим
 * @param y на что делим
 * @param Владимир
 * @return остаток от деления с плавающей точкой
 */
long double s21_fmod(double x, double y) {
  if (x == x && x != s21_INF && x != -s21_INF && y != 0.0 && y != s21_INF &&
      y != -s21_INF) {
    int a = 1;
    if (x < 0) a = -1, x = s21_fabs(x);
    if (y < 0) y = s21_fabs(y);
    x -= y * (long long int)(x / y);
    x *= a;
  }
  if (x != x || x == s21_INF || x == -s21_INF || y == 0.0) x = -s21_NAN;
  return x;
}

/**
 * возвращает наибольшее целое число с плавающей точкой, не более заданного
 *
 * @param x число с плавающей точкой
 * @param Андрей
 * @return long double наибольшее целочисленное значение, не превышающее x
 */
long double s21_floor(double x) {
  long long int res = (long long int)x;
  if (x == x && x != s21_INF && x != -s21_INF) {
    if (x > 0 && x < 1)
      res = 0;
    else if (!(res > 0 || x == (float)res))
      res--;
  }

  if (x == s21_INF) res = s21_INF;
  if (x == -s21_INF) res = -s21_INF;
  if (x != x) res = s21_NAN;
  return res;
}

/**
 * Вычисляет ближайшее целое число
 * @param x изначальное число
 * @param Никита
 * @return ближайшее целое число к x
 */
long double s21_ceil(double x) {
  int inum = (int)x;
  if (x < 0 || x == (float)inum) {
    return inum;
  }
  return inum + 1;
}
