#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_




#include <stdio.h>

#define S21_E 2.7182818284590452353602874713526625
#define S21_PI 3.1415926535897932384626433832795
#define S21_INFINITY 1.0 / 0.0
#define S21_NAN -(0.0/0.0)
#define S21_EPS_10 1e-10
#define S21_EPS_6 1e-06
#define S21_P_INF (1.0L / 0.0L)   // положительная бесконечность
#define S21_N_INF (-1.0L / 0.0L)  // отрицательная бесконечность

int s21_abs(int);
long double s21_acos(double);
long double s21_asin(double);
long double s21_atan(double);
long double s21_ceil(double);
long double s21_cos(double);
long double s21_exp(double);
long double s21_fabs(double);
long double s21_floor(double);
long double s21_fmod(double, double);
long double s21_log(double);
long double s21_pow(double, double);
long double s21_sin(double);
long double s21_sqrt(double);
long double s21_tan(double);
int exp_odd(double);

#endif  // SRC_S21_MATH_H_
