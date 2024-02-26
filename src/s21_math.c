#include "s21_math.h"


int s21_abs(int x) {
    return (x < 0) ? x * (-1) : x;
}

long double s21_acos(double x) {
    return S21_PI / 2 - s21_asin(x);
}

long double s21_asin(double x) {
    long double term = x, res = S21_NAN;
    if (x > -1 && x < 1) {
        res = x;
        x *= x;
        for (int i = 1; s21_fabs(term) > S21_EPS_10; i +=2)
            res += (term *= x * i / (i + 1)) / (i + 2);
    } else if (x == 1 || x == -1) {
        res = S21_PI / 2 * x;
    }
    return res;
}

long double s21_atan(double x) {
    return s21_asin(x / s21_pow ((1 + x * x), 0.5));
}

long double s21_ceil(double x) {
    int z = (int)x;
    if (z < x) z++;
    return (long double)z;
}

long double s21_cos(double x) {
    x = s21_fmod(x, 2 * S21_PI);
    long double res = 0, temp = 1;
    for (int i = 1; s21_fabs(temp) > S21_EPS_10; ++i) {
        res += temp;
        temp *= -x * x / (2.0 * i - 1.0) / (2.0 * i);
    }
    res = (s21_fabs(res) < S21_EPS_10) ? 0.0 : res;
return res;
}

long double s21_exp(double x) {
    long double sum = 1.0, cur = 1.0;
    unsigned n = 1;
    if (x == S21_N_INF) {
    cur = 0.0;
  } else if (x == S21_P_INF || x != x) {
    cur = x;
  } else if (x < -30) {
    sum = 0;
    } else {
    while (s21_fabs(cur) > S21_EPS_10)
        sum += (cur *= (long double)x / n++);
    }
    return sum;
}

long double s21_fabs(double x) {
    long double abs_x = (x > 0) ? (long double)x : -(long double)x;
    return abs_x;
}

long double s21_floor(double x) {
    int z = (int)x;
    if (z > x && x != 0) z--;
    return (long double)z;
}
long double s21_fmod(double x, double y) {  // a = b * q + r
    long double res;
    if (x == S21_P_INF || x == S21_N_INF || x != x || y != y || y == 0) {
        res = S21_NAN;
    } else if (y == S21_P_INF || y == S21_N_INF) {
        res = x;
    } else {
        long double sign = 1.l;
        if (x < 0) {
            x = s21_fabs(x);
            sign = -1.l;  //  знак остатка зависит только от x
        }
        if (y < 0) {
            y = s21_fabs(y);
        }
        res = sign * (x - y * (long int)(x / y));
    }
    return (long double)res;
}

long double s21_log(double x) {
    unsigned a = 0;
    double b = 0;
    if (x > 0) {
        unsigned d;
        double e = b, c, f;
        for (c = ((x < 1.0) ? 1 / x : x); (c /= S21_E) > 1; ++a) {
        }
        c = 2 / (c * S21_E - 1) + 1;
        f = c * c;
        for (d = 1, c /= 2; b += 1 / (d * c), b - e;) {
            e = b;
            d += 2;
            c *= f;
        }
    } else {
        b = (x == 0) / 0.;  // логарифм отрицательного числа неопределен х / на 0
    }
    long double log_x = (x < 1) ? -(a + b) : a + b;
    return log_x;
}

long double s21_pow(double base, double exp) {
    long double pow_base;
    long div = (long)exp;
    if (base == 0.0 && exp != 0.0) {  // степень 0
        pow_base = 0.0;
    } else if (exp == 0.0) {  // 0 степень числа
        pow_base = 1.0;
    } else if (exp < 0) {  // отрицательная степень
        pow_base = 1 / s21_pow(base, -exp);
    } else if (base < 0.0 && exp_odd(exp - div)) {
        pow_base = S21_NAN;
    } else {
        long double flag = 1.0, integerPart = 1, t;
        if (base < 0 && div % 2)
            flag = -1.0;
        base = (base < 0) ? -base : base;
        t = s21_pow(base, div/2);
        if (div%2) integerPart = t * t * base;
        else
        integerPart = t * t;
        pow_base = integerPart * s21_exp((exp - (double)div) * s21_log(base)) * flag;
    }
    return pow_base;
}

long double s21_sin(double x) {
    x = s21_fmod(x, 2 * S21_PI);
    long double res = 0, temp = x;
    for (int i = 1; s21_fabs(temp) > S21_EPS_10; ++i) {
        res += temp;
        temp *= -x * x / (2.0 * i + 1.0) / (2.0 * i);
    }
    res = (s21_fabs(res) < S21_EPS_10) ? 0.0 : res;
return res;
}

long double s21_sqrt(double x) {
    return s21_pow(x, 0.5);
}

long double s21_tan(double x) {
    long double tan = x;
    if (x == S21_PI / 2) {
        tan = 16331239353195370L;
    } else if (x == -S21_PI / 2) {
        tan = -16331239353195370L;
    } else if (!x) {
        tan = 0.000000;
    } else {
        tan = s21_sin(x) / s21_cos(x);
    }
    return tan;
}

int exp_odd(double x) {
    int r = 0;
    long double cur = 1.0;
    unsigned n = 1;
    while (s21_fabs(cur) > S21_EPS_10)
        cur *= (long double)x / n++;
    while ((x - (long) x) > S21_EPS_6 && r < n) {
        x *=10;
        r++;
    }
    if (r == n || (long) x % 2) r = 1;
    else
    r = 0;
    return r;
}






