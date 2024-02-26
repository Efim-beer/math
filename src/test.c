#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <math.h>

#include "s21_math.h"

// 1

START_TEST(s21_absTest) {
for (double i = -10; i < 2;) {
int x = i;
ck_assert_int_eq(s21_abs(x), abs(x));
i = i+0.1;
}
}
END_TEST

START_TEST(s21_acosTest) {
for (double i = -1; i < 1;) {
ck_assert_double_eq_tol(s21_acos(i), acos(i), 1e-6);
i = i+0.000005;
}
}
END_TEST

START_TEST(s21_asinTest) {
for (double i = -1; i < 1;) {
ck_assert_ldouble_eq_tol(s21_asin(i), asin(i), 1e-6);
i = i+0.3;
}
}
END_TEST


START_TEST(s21_atanTest) {
for (double i = -100; i < 2;) {
ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), 1e-6);
i = i+0.1;
}
}
END_TEST


START_TEST(s21_ceilTest) {
for (double i = -50; i < 50;) {
ck_assert_ldouble_eq(s21_ceil(i), ceil(i));
i = i+0.0005;
}
}
END_TEST


START_TEST(s21_cosTest) {
for (double i = -5; i < 2;) {
ck_assert_ldouble_eq_tol(s21_cos(i), cos(i), 1e-6);
i = i+0.001;
}
}
END_TEST


START_TEST(s21_expTest) {
for (double i = -20; i < 15;) {
ck_assert_ldouble_eq_tol(s21_exp(i), exp(i), 1e-6);
i = i+0.001;
}
}
END_TEST


START_TEST(s21_fabsTest) {
for (double i = -2*S21_PI; i < 2;) {
ck_assert_ldouble_eq(s21_fabs(i), fabs(i));
i = i+0.1;
}
}
END_TEST


START_TEST(s21_floorTest) {
for (double i = -10; i < 5;) {
int x = i;
ck_assert_ldouble_eq(s21_floor(x), floor(x));
i = i+0.5;
}
}
END_TEST


START_TEST(s21_fmodTest) {
double i = -S21_PI;  {
for (double x = -3.123; x < 10; x++) {
ck_assert_double_eq_tol(s21_fmod(x, i), fmod(x, i), 1e-06);
x = x+0.054;
}
}
}
END_TEST


START_TEST(s21_logTest) {
for (double i = 1; i < 25;) {
ck_assert_ldouble_eq_tol(s21_log(i), log(i), 1e-6);
i = i+0.1111111111;
}
}
END_TEST


START_TEST(s21_powTest) {
for (double i = -1.16113123; i < 11;) {
for (int x = 0; x < 10; x++) {
ck_assert_ldouble_eq_tol(s21_pow(i, x), pow(i, x), 1e-6);
i = i+0.11111111111;
}
}
}
END_TEST


START_TEST(s21_sinTest) {
for (double i = -50; i < 6;) {
ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), 1e-6);
i = i+0.0005;
}
}
END_TEST


START_TEST(s21_sqrtTest) {
for (double i = 0; i < 3;) {
ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrt(i), 1e-6);
i = i+0.2314511;
}
}
END_TEST


START_TEST(s21_tanTest) {
for (double i = -5; i < 10;) {
// ck_assert_ldouble_eq_tol(s21_tan(i),tan(i), 1e-6);
ck_assert(fabsl(s21_tan(i)-tan(i)< 1e-6));
i = i+1;
}
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int qs;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, s21_absTest);
    tcase_add_test(tc1_1, s21_acosTest);
    tcase_add_test(tc1_1, s21_asinTest);
    tcase_add_test(tc1_1, s21_atanTest);
    tcase_add_test(tc1_1, s21_ceilTest);
    tcase_add_test(tc1_1, s21_cosTest);
    tcase_add_test(tc1_1, s21_expTest);
    tcase_add_test(tc1_1, s21_fabsTest);
    tcase_add_test(tc1_1, s21_floorTest);
    tcase_add_test(tc1_1, s21_fmodTest);
    tcase_add_test(tc1_1, s21_logTest);
    tcase_add_test(tc1_1, s21_powTest);
    tcase_add_test(tc1_1, s21_sinTest);
    tcase_add_test(tc1_1, s21_sqrtTest);
    tcase_add_test(tc1_1, s21_tanTest);

    srunner_run_all(sr, CK_ENV);
    qs = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (qs == 0) ? 0 : 1;
}
