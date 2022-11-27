#pragma once
#include <vector> // conteiners for network values
using std::vector;
double Simpson_rule(double a, double b, double f0, double f1, double f2)
{
    std::cout << "b = " << b << " a = " << a << " ";
    std::cout << "answer = "<<((b - a) / 6) * (f0 + 4 * f1 + f2) << "\n";
    return((b - a) / 6) * (f0 + 4 * f1 + f2);
}
double Simpson_3_8_rule(double a, double b, double f0, double f1, double f2, double f3)
{
    return (b - a) / 8 * (f0 + 3 * f1 + 3 * f2 + f3);
}
double Bool_rule(double a, double b, double f0, double f1, double f2, double f3, double f4)
{
    return (b - a) / 90 * (7 * f0 + 32 * f1 + 12 * f2 + 32 * f3 + 7 * f4);
}

double full_Simpson_rule(const vector<double>& x, const vector<double>& y, int point_num)
{
    double part_sum = 0;
    for (int i = 0; i < x.size() - 2; i += 2) {
        part_sum += (Simpson_rule(x[i], x[i + 2], y[i], y[i + 1], y[i + 2]));
    }
    return part_sum;
}
double full_Simpson_3_8_rule(const vector<double>& x, const vector<double>& y,int point_num)
{
    double part_sum = 0;
    for (int i = 0; i < x.size() - 3; i += 3) {
        part_sum += (Simpson_3_8_rule(x[i], x[i + 3], y[i], y[i + 1], y[i + 2], y[i + 3]));
    }
    return part_sum;
}
double full_Bool_rule(const vector<double>& x, const vector<double>& y,int point_num)
{
    double part_sum = 0;
    for (int i = 0; i < x.size() - 4; i += 4) {
        part_sum += (Bool_rule(x[i], x[i + 4], y[i], y[i + 1], y[i + 2], y[i + 3], y[i + 4]));
    }
    return part_sum;
}

//x8-8x7-15x5-32x4+6
double test_8_polinom(double x)
{
    double answer = 0.0;
    double tmp_x = x;
    for (int i = 0; i < 7; i++) {
        tmp_x *= x;
    }
    answer += tmp_x;
    tmp_x = x;
    for (int i = 0; i < 6; i++)
    {
        tmp_x *= x;
    }
    answer -= tmp_x * 8;
    tmp_x = x;
    for (int i = 0; i < 4; i++)
    {
        tmp_x *= x;
    }
    answer -= tmp_x * 15;
    tmp_x = x;
    for (int i = 0; i < 3; i++)
    {
        tmp_x *= x;
    }
    answer -= 32 * tmp_x;
    answer += 6;
    return answer;
}


double integral_sin(double a, double b)
{
    double xb = -cos(b);
    double xa = -cos(a);
    return xb - xa;
}
double integral_cos(double a, double b)
{
    double xb = sin(b);
    double xa = sin(a);
    return xb - xa;
}
double integral_x(double a, double b)
{
    return (b * b - a * a) / 2;
}

//1/9x9-x8-5/3x6-6.4x5+6x
double one_point_integral_test_8_polinom(double x)
{
    double answer = 0.0;
    double tmp_x = x;
    for (int i = 0; i < 8; i++) {
        tmp_x *= x;
    }
    answer += 1 / 9.0 * tmp_x;
    tmp_x = x;
    for (int i = 0; i < 7; i++)
    {
        tmp_x *= x;
    }
    answer -= tmp_x;
    tmp_x = x;
    for (int i = 0; i < 5; i++)
    {
        tmp_x *= x;
    }
    answer -= tmp_x * 5 / 3;
    tmp_x = x;
    for (int i = 0; i < 4; i++)
    {
        tmp_x *= x;
    }
    answer -= 6.4 * tmp_x;
    tmp_x = x;
    answer += 6 * tmp_x;
    return answer;
}
double integral_test_8_polinom(double a, double b)
{
    double answer_a = one_point_integral_test_8_polinom(a);
    double answer_b = one_point_integral_test_8_polinom(b);
    return answer_b - answer_a;
}