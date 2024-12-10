// implementation
// mathematics
// Silver V

#include <bits/stdc++.h>

int main()
{
    int x;
    std::cin >> x;

    int curr_len = 0, max_len = 1;
    bool is_going_up = true;
    int numerator = 2, denominator = 0;
    while (x--)
    {
        curr_len++;
        if (curr_len > max_len)
        {
            max_len++;
            curr_len = 1;

            numerator = is_going_up ? 1 : max_len;
            denominator = is_going_up ? max_len : 1;

            is_going_up = !is_going_up;
            continue;
        }

        numerator += is_going_up ? -1 : 1;
        denominator += is_going_up ? 1 : -1;
    }

    std::cout << numerator << '/' << denominator;
}
