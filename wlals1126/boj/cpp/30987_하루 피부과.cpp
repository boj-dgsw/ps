#include <iostream>
#include <cmath>

using namespace std;

double f(double x, int a, int b, int c) {
    return a * x * x + b * x + c;
}

double g(double x, int d, int e) {
    return d * x + e;
}

double integral(double x1, double x2, int a, int b, int c, int d, int e) {
    // F(x) = ax^3 / 3 + bx^2 / 2 + cx - dx^2 / 2 - ex
    auto F = [=](double x) {
        return (a * x * x * x / 3.0) + (b * x * x / 2.0) + (c * x) - (d * x * x / 2.0) - (e * x);
    };

    return F(x2) - F(x1);
}

int main() {
    double x1, x2;
    int a, b, c, d, e;

    cin >> x1 >> x2;
    cin >> a >> b >> c >> d >> e;

    double result = integral(x1, x2, a, b, c, d, e);

    cout << static_cast<int>(round(result)) << endl;

    return 0;
}
