#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_abs) {
  int a = 5;
  int b = 5;
  ck_assert_int_eq(abs(a), s21_abs(b));
  a = -5555;
  b = -5555;
  ck_assert_int_eq(abs(a), s21_abs(b));
  a = -0;
  b = -0;
  ck_assert_int_eq(abs(a), s21_abs(b));
  ck_assert_int_eq(abs(s21_NAN), s21_abs(s21_NAN));
  ck_assert_int_eq(abs(-s21_NAN), s21_abs(-s21_NAN));
  ck_assert_int_eq(abs(s21_INF), s21_abs(s21_INF));
  ck_assert_int_eq(abs(-s21_INF), s21_abs(-s21_INF));
}
END_TEST

START_TEST(test_s21_sin) {
  double a = 0;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 1 Fail");
  a = 90 * S21_PI / 180;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 2 Fail");
  a = S21_PI;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 3 Fail");
  a = 270 * S21_PI / 180;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 4 Fail");
  a = 2 * S21_PI;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 5 Fail");
  a = 400 * S21_PI / 180;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 6 Fail");
  a = 3000 * S21_PI;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 7 Fail");
  a = S21_PI / 6;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 8 Fail");
  a = S21_PI / 4;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 9 Fail");
  a = S21_PI / 2;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 10 Fail");
  a = 3 * S21_PI / 2;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 11 Fail");
  a = -300;
  ck_assert_msg(fabsl(sin(a) - s21_sin(a)) < EPS, "test_s21_sin 11 Fail");
  ck_assert_int_eq(sin(s21_NAN), s21_sin(s21_NAN));
  ck_assert_int_eq(sin(-s21_NAN), s21_sin(-s21_NAN));
  ck_assert_int_eq(sin(s21_INF), s21_sin(s21_INF));
  ck_assert_int_eq(sin(-s21_INF), s21_sin(-s21_INF));
}
END_TEST

START_TEST(test_s21_fmod) {
  double a = 10;
  double b = 3;
  ck_assert_msg(fabsl(fmod(a, b) - s21_fmod(a, b)) < EPS,
                "test_s21_fmod 1 Fail");
  a = -10;
  b = 3;
  ck_assert_msg(fabsl(fmod(a, b) - s21_fmod(a, b)) < EPS,
                "test_s21_fmod 2 Fail");
  a = 7.3;
  b = 2.9;
  ck_assert_msg(fabsl(fmod(a, b) - s21_fmod(a, b)) < EPS,
                "test_s21_fmod 3 Fail");
  a = 15.5;
  b = 2.2;
  ck_assert_msg(fabsl(fmod(a, b) - s21_fmod(a, b)) < EPS,
                "test_s21_fmod 4 Fail");
  a = s21_NAN;
  b = 2.21;
  ck_assert_int_eq(fmod(a, b), s21_fmod(a, b));
  a = -s21_NAN;
  b = 2.22;
  ck_assert_int_eq(fmod(a, b), s21_fmod(a, b));
  a = 15.51;
  b = s21_NAN;
  ck_assert_int_eq(fmod(a, b), s21_fmod(a, b));
  a = s21_INF;
  b = 2.23;
  ck_assert_int_eq(fmod(a, b), s21_fmod(a, b));
  a = 15.52;
  b = s21_INF;
  ck_assert_int_eq(fmod(a, b), s21_fmod(a, b));
  a = 15.52;
  b = -s21_INF;
  ck_assert_int_eq(fmod(a, b), s21_fmod(a, b));
  a = 15.52;
  b = 0.0;
  ck_assert_int_eq(fmod(a, b), s21_fmod(a, b));
  a = 0.0;
  b = 15.1;
  ck_assert_int_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(test_s21_exp) {
  ck_assert_msg(fabsl(exp(0.5) - s21_exp(0.5)) < EPS, "test_s21_exp 1 Fail");
  ck_assert_msg(fabsl(exp(-0.5) - s21_exp(-0.5)) < EPS, "test_s21_exp 2 Fail");
  ck_assert_msg(fabsl(exp(-1) - s21_exp(-1)) < EPS, "test_s21_exp 3 Fail");
  ck_assert_msg(fabsl(exp(1) - s21_exp(1)) < EPS, "test_s21_exp 4 Fail");
  ck_assert_msg(fabsl(exp(1.1) - s21_exp(1.1)) < EPS, "test_s21_exp 5 Fail");
  ck_assert_msg(fabsl(exp(-2.1) - s21_exp(-2.1)) < EPS, "test_s21_exp 6 Fail");
  ck_assert_msg(fabsl(exp(0) - s21_exp(0)) < EPS, "test_s21_exp 7 Fail");
  ck_assert_msg(fabsl(exp(-0) - s21_exp(-0)) < EPS, "test_s21_exp 8 Fail");
  ck_assert_msg(fabsl(exp(5.123456789123) - s21_exp(5.123456789123)) < EPS,
                "test_s21_exp 9 Fail");
  ck_assert_msg(fabsl(exp(0.00000004564897) - s21_exp(0.00000004564897)) < EPS,
                "test_s21_exp 10 Fail");
  ck_assert_msg(fabsl(exp(20.1) - s21_exp(20.1)) < EPS, "test_s21_exp 11 Fail");
  ck_assert_msg(fabsl(exp(-20.1) - s21_exp(-20.1)) < EPS,
                "test_s21_exp 12 Fail");

  int x = sqrt(2);
  ck_assert_msg(fabsl(exp(x) - s21_exp(x)) < EPS, "test_s21_exp 13 Fail");
  x = S21_PI;
  ck_assert_msg(fabsl(exp(x) - s21_exp(x)) < EPS, "test_s21_exp 14 Fail");
  x = 2;
  ck_assert_msg(fabsl(exp(x) - s21_exp(x)) < EPS, "test_s21_exp 15 Fail");
  x = 3;
  ck_assert_msg(fabsl(exp(x) - s21_exp(x)) < EPS, "test_s21_exp 16 Fail");
  x = 20;
  ck_assert_msg(fabsl(exp(x) - s21_exp(x)) < EPS, "test_s21_exp 17 Fail");
  x = -1;
  ck_assert_msg(fabsl(exp(x) - s21_exp(x)) < EPS, "test_s21_exp 18 Fail");
  x = -2;
  ck_assert_msg(fabsl(exp(x) - s21_exp(x)) < EPS, "test_s21_exp 19 Fail");
  x = -6.8888;
  ck_assert_msg(fabsl(exp(x) - s21_exp(x)) < EPS, "test_s21_exp 20 Fail");
  x = -300;
  ck_assert_msg(fabsl(exp(x) - s21_exp(x)) < EPS, "test_s21_exp 21 Fail");
  ck_assert_int_eq(exp(s21_NAN), s21_exp(s21_NAN));
  ck_assert_int_eq(exp(-s21_NAN), s21_exp(-s21_NAN));
  ck_assert_int_eq(exp(s21_INF), s21_exp(s21_INF));
  ck_assert_int_eq(exp(-s21_INF), s21_exp(-s21_INF));
}
END_TEST

START_TEST(test_s21_atan) {
  double a = 0;
  ck_assert_msg(fabsl(atan(a) - s21_atan(a)) < EPS, "test_s21_atan 1 Fail");
  a = 90 * S21_PI / 180;
  ck_assert_msg(fabsl(atan(a) - s21_atan(a)) < EPS, "test_s21_atan 2 Fail");
  a = S21_PI;
  ck_assert_msg(fabsl(atan(a) - s21_atan(a)) < EPS, "test_s21_atan 3 Fail");
  a = 270 * S21_PI / 180;
  ck_assert_msg(fabsl(atan(a) - s21_atan(a)) < EPS, "test_s21_atan 4 Fail");
  a = 2 * S21_PI;
  ck_assert_msg(fabsl(atan(a) - s21_atan(a)) < EPS, "test_s21_atan 5 Fail");
  a = 400 * S21_PI / 180;
  ck_assert_msg(fabsl(atan(a) - s21_atan(a)) < EPS, "test_s21_atan 6 Fail");
  a = 300 * S21_PI;
  ck_assert_msg(fabsl(atan(a) - s21_atan(a)) < EPS, "test_s21_atan 7 Fail");
  a = S21_PI / 6;
  ck_assert_msg(fabsl(atan(a) - s21_atan(a)) < EPS, "test_s21_atan 8 Fail");
  a = S21_PI / 4;
  ck_assert_msg(fabsl(atan(a) - s21_atan(a)) < EPS, "test_s21_atan 9 Fail");
  a = S21_PI / 2;
  ck_assert_msg(fabsl(atan(a) - s21_atan(a)) < EPS, "test_s21_atan 10 Fail");
  a = -2.1;
  ck_assert_msg(fabsl(atan(a) - s21_atan(a)) < EPS, "test_s21_atan 11 Fail");
  ck_assert_int_eq(atan(s21_NAN), s21_atan(s21_NAN));
  ck_assert_int_eq(atan(-s21_NAN), s21_atan(-s21_NAN));
  ck_assert_int_eq(atan(s21_INF), s21_atan(s21_INF));
  ck_assert_int_eq(atan(-s21_INF), s21_atan(-s21_INF));
}
END_TEST

START_TEST(test_s21_acos) {
  double test_1 = 1;
  double test_2 = 0;
  double test_3 = 0.5;
  double test_4 = -0.5;
  double test_5 = -1;
  ck_assert_msg(fabsl(acos(test_1) - s21_acos(test_1)) < EPS,
                "test_s21_acos 1 Fail");
  ck_assert_msg(fabsl(acos(test_2) - s21_acos(test_2)) < EPS,
                "test_s21_acos 2 Fail");
  ck_assert_msg(fabsl(acos(test_3) - s21_acos(test_3)) < EPS,
                "test_s21_acos 3 Fail");
  ck_assert_msg(fabsl(acos(test_4) - s21_acos(test_4)) < EPS,
                "test_s21_acos 4 Fail");
  ck_assert_msg(fabsl(acos(test_5) - s21_acos(test_5)) < EPS,
                "test_s21_acos 5 Fail");
}
END_TEST

START_TEST(test_s21_ceil) {
  double test_1 = 1;
  double test_2 = 0;
  double test_3 = -0.5;
  double test_4 = -14;
  double test_5 = -1.6;
  double test_6 = 1.6;
  ck_assert_msg(fabsl(ceil(test_1) - s21_ceil(test_1)) < EPS,
                "test_s21_ceil 1 Fail");
  ck_assert_msg(fabsl(ceil(test_2) - s21_ceil(test_2)) < EPS,
                "test_s21_ceil 2 Fail");
  ck_assert_msg(fabsl(ceil(test_3) - s21_ceil(test_3)) < EPS,
                "test_s21_ceil 3 Fail");
  ck_assert_msg(fabsl(ceil(test_4) - s21_ceil(test_4)) < EPS,
                "test_s21_ceil 4 Fail");
  ck_assert_msg(fabsl(ceil(test_5) - s21_ceil(test_5)) < EPS,
                "test_s21_ceil 5 Fail");
  ck_assert_msg(fabsl(ceil(test_6) - s21_ceil(test_6)) < EPS,
                "test_s21_ceil 6 Fail");
}
END_TEST

START_TEST(test_s21_fabs) {
  double test_1 = -1.5;
  double test_2 = -2.1;
  double test_3 = -0.5;
  double test_4 = -12.15;
  double test_5 = 1.25;
  ck_assert_msg(fabsl(fabs(test_1) - s21_fabs(test_1)) < EPS,
                "test_s21_fabs 1 Fail");
  ck_assert_msg(fabsl(fabs(test_2) - s21_fabs(test_2)) < EPS,
                "test_s21_fabs 2 Fail");
  ck_assert_msg(fabsl(fabs(test_3) - s21_fabs(test_3)) < EPS,
                "test_s21_fabs 3 Fail");
  ck_assert_msg(fabsl(fabs(test_4) - s21_fabs(test_4)) < EPS,
                "test_s21_fabs 4 Fail");
  ck_assert_msg(fabsl(fabs(test_5) - s21_fabs(test_5)) < EPS,
                "test_s21_fabs 5 Fail");
}
END_TEST

START_TEST(test_s21_sqrt) {
  double test_1 = 25;
  double test_2 = 1024;
  double test_3 = 12.5;
  double test_4 = 0;
  ck_assert_msg(fabsl(sqrt(test_1) - s21_sqrt(test_1)) < EPS,
                "test_s21_sqrt 1 Fail");
  ck_assert_msg(fabsl(sqrt(test_2) - s21_sqrt(test_2)) < EPS,
                "test_s21_sqrt 2 Fail");
  ck_assert_msg(fabsl(sqrt(test_3) - s21_sqrt(test_3)) < EPS,
                "test_s21_sqrt 3 Fail");
  ck_assert_msg(fabsl(sqrt(test_4) - s21_sqrt(test_4)) < EPS,
                "test_s21_sqrt 4 Fail");
}
END_TEST

START_TEST(test_s21_log) {
  double test_1 = 25;
  double test_2 = 1024;
  double test_3 = 12.5;
  double test_4 = 100;
  ck_assert_msg(fabsl(log(test_1) - s21_log(test_1)) < EPS,
                "test_s21_log 1 Fail");
  ck_assert_msg(fabsl(log(test_2) - s21_log(test_2)) < EPS,
                "test_s21_log 2 Fail");
  ck_assert_msg(fabsl(log(test_3) - s21_log(test_3)) < EPS,
                "test_s21_log 3 Fail");
  ck_assert_msg(fabsl(log(test_4) - s21_log(test_4)) < EPS,
                "test_s21_log 4 Fail");
}
END_TEST

START_TEST(test_s21_cos) {
  double a = 112;
  double b = -59;
  double c = 3.564335;
  ck_assert_msg(fabsl(cos(a) - s21_cos(a)) < EPS, "test_s21_cos 1 Fail");
  ck_assert_msg(fabsl(cos(b) - s21_cos(b)) < EPS, "test_s21_cos 2 Fail");
  ck_assert_msg(fabsl(cos(c) - s21_cos(c)) < EPS, "test_s21_cos 3 Fail");
}
END_TEST

START_TEST(test_s21_tan) {
  double a = 112;
  double b = -59;
  double c = 3.564335;
  ck_assert_msg(fabsl(tan(a) - s21_tan(a)) < EPS, "test_s21_tan 1 Fail");
  ck_assert_msg(fabsl(tan(b) - s21_tan(b)) < EPS, "test_s21_tan 2 Fail");
  ck_assert_msg(fabsl(tan(c) - s21_tan(c)) < EPS, "test_s21_tan 3 Fail");
}
END_TEST

START_TEST(test_s21_floor) {
  double test_1 = 2;
  double test_2 = 0;
  double test_3 = -0.5;
  double test_4 = -16;
  double test_5 = -1.6;
  double test_6 = 1.7;
  double test_7 = 0.7433;
  ck_assert_msg(fabsl(floor(test_1) - s21_floor(test_1)) < EPS,
                "test_s21_floor 1 Fail");
  ck_assert_msg(fabsl(floor(test_2) - s21_floor(test_2)) < EPS,
                "test_s21_floor 2 Fail");
  ck_assert_msg(fabsl(floor(test_3) - s21_floor(test_3)) < EPS,
                "test_s21_floor 3 Fail");
  ck_assert_msg(fabsl(floor(test_4) - s21_floor(test_4)) < EPS,
                "test_s21_floor 4 Fail");
  ck_assert_msg(fabsl(floor(test_5) - s21_floor(test_5)) < EPS,
                "test_s21_floor 5 Fail");
  ck_assert_msg(fabsl(floor(test_6) - s21_floor(test_6)) < EPS,
                "test_s21_floor 6 Fail");
  ck_assert_msg(fabsl(floor(test_7) - s21_floor(test_7)) < EPS,
                "test_s21_floor 7 Fail");
}
END_TEST

START_TEST(test_s21_pow) {
  double test_1 = 2;
  double test_2 = 0;
  double test_3 = -0.523;
  double test_4 = 9.837;
  double test_5 = -1.68;
  double test_6 = 1.107;
  double test_7 = 32.1908;

  double test_8 = -2.4;
  ck_assert_msg(fabsl(pow(test_1, test_2) - s21_pow(test_1, test_2)) < EPS,
                "test_s21_pow 1 Fail");
  ck_assert_msg(fabsl(pow(test_2, test_6) - s21_pow(test_2, test_6)) < EPS,
                "test_s21_pow 2 Fail");
  ck_assert_msg(fabsl(pow(test_6, test_3) - s21_pow(test_6, test_3)) < EPS,
                "test_s21_pow 3 Fail");
  ck_assert_msg(fabsl(pow(test_4, test_6) - s21_pow(test_4, test_6)) < EPS,
                "test_s21_pow 4 Fail");
  ck_assert_msg(fabsl(pow(test_5, test_2) - s21_pow(test_5, test_2)) < EPS,
                "test_s21_pow 5 Fail");
  ck_assert_msg(fabsl(pow(test_6, test_7) - s21_pow(test_6, test_7)) < EPS,
                "test_s21_pow 6 Fail");
  ck_assert_msg(fabsl(pow(test_7, test_6) - s21_pow(test_7, test_6)) < EPS,
                "test_s21_pow 7 Fail");
  ck_assert_msg(fabsl(pow(test_6, test_2) - s21_pow(test_6, test_2)) < EPS,
                "test_s21_pow 8 Fail");
  ck_assert_msg(fabsl(pow(test_8, test_1) - s21_pow(test_8, test_1)) < EPS,
                "test_s21_pow 9 Fail");
}
END_TEST

START_TEST(test_s21_asin) {
  double test_1 = 1;
  double test_2 = -0.3;
  double test_3 = 0.5;
  double test_4 = -0.5;
  double test_5 = 0;
  double test_6 = -0.9313;
  ck_assert_msg(fabsl(asin(test_1) - s21_asin(test_1)) < EPS,
                "test_s21_asin 1 Fail");
  ck_assert_msg(fabsl(asin(test_2) - s21_asin(test_2)) < EPS,
                "test_s21_asin 2 Fail");
  ck_assert_msg(fabsl(asin(test_3) - s21_asin(test_3)) < EPS,
                "test_s21_asin 3 Fail");
  ck_assert_msg(fabsl(asin(test_4) - s21_asin(test_4)) < EPS,
                "test_s21_asin 4 Fail");
  ck_assert_msg(fabsl(asin(test_5) - s21_asin(test_5)) < EPS,
                "test_s21_asin 5 Fail");
  ck_assert_msg(fabsl(asin(test_6) - s21_asin(test_6)) < EPS,
                "test_s21_asin 6 Fail");
}
END_TEST

int main(void) {
  Suite *suite = suite_create("TheTest");
  TCase *tc = tcase_create("TheTest");
  SRunner *sr = srunner_create(suite);
  int nf;
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, test_s21_abs);
  tcase_add_test(tc, test_s21_sin);
  tcase_add_test(tc, test_s21_fmod);
  tcase_add_test(tc, test_s21_exp);
  tcase_add_test(tc, test_s21_atan);
  tcase_add_test(tc, test_s21_acos);
  tcase_add_test(tc, test_s21_ceil);
  tcase_add_test(tc, test_s21_fabs);
  tcase_add_test(tc, test_s21_sqrt);
  tcase_add_test(tc, test_s21_log);
  tcase_add_test(tc, test_s21_cos);
  tcase_add_test(tc, test_s21_tan);
  tcase_add_test(tc, test_s21_floor);
  tcase_add_test(tc, test_s21_pow);
  tcase_add_test(tc, test_s21_asin);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
