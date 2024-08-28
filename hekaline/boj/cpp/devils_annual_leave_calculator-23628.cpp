// Bronze I
// Implementation

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

class Date
{
public:
    int year;
    int month;
    int day;

    Date(int year, int month, int day) :
    year(year), month(month), day(day) {}

    Date() : year(0), month(0), day(0) {}

    friend istream& operator>>(istream &is, Date &date)
    {
        is >> date.year >> date.month >> date.day;
        return is;
    }

    [[nodiscard]]
    int getDateToDay()
    {
        return year * 360 + month * 30 + day;
    }

    [[nodiscard]]
    int getAnnualLeave()
    {
        int val = 15 * year;
        int maxA = (year - 2) / 2;

        val += maxA * (maxA + 1);
        if (year % 2 && year >= 3)
        {
            val += maxA + 1;
        }

        return val;
    }

    [[nodiscard]]
    int getMonthlyLeave()
    {
        return min(year * 12 + month, 36);
    }

    void subtract(const Date& other)
    {
        year -= other.year;
        month -= other.month;
        day -= other.day;

        if (day < 0)
        {
            month--;
            day += 30;
        }
        if (month < 0)
        {
            year--;
            month += 12;
        }
    }


};

int main()
{
    FAST_IO;

    Date s, e;
    cin >> s >> e;

    e.subtract(s);

    cout << e.getAnnualLeave() << ' ';
    cout << e.getMonthlyLeave() << '\n';
    cout << e.getDateToDay() << "days";
}
