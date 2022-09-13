#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_PI 3.1415926535897932384626433832795
#define S21_E 2.7182818284590452353602874713527
#define S21_LN10 2.3025850929940456840179914546844
#define s21_NAN 0.0 / 0.0
#define s21_INF 1.0 / 0.0
#define EPS 1E-6
#define EPS16 1E-16
#define EPS20 1E-20
#define EPS016 9E+17

int s21_abs(int x);
long double s21_atan(double x);
long double s21_exp(double x);
long double s21_fmod(double x, double y);
long double s21_sin(double x);
long double s21_acos(double x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_cos(double x);
long double s21_asin(double x);
long double s21_floor(double x);
long double s21_pow(double base, double exp);
long double s21_tan(double x);

#endif  // SRC_S21_MATH_H_
