// implementation
// string
// bruteforcing
// Silver III

#include <bits/stdc++.h>
#define FAST_IO \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr);

std::array arr1 { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
std::array arr2 { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
std::array arr3 { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

std::string get_numstr(int len)
{
    if (len == 0)
    {
        return "four";
    }

    int i = len;

    do
    {
        int i_copy = i;
        std::string numstr = "";

        if (i_copy >= 100)
        {
            int mul = i_copy / 100;

            numstr += arr1[mul - 1] + std::string("hundred");
            i_copy -= mul * 100;
        }
        if (i_copy >= 20)
        {
            int mul = i_copy / 10;

            numstr += arr3[mul - 2];
            i_copy -= mul * 10;
        }
        if (i_copy > 10)
        {
            numstr += arr2[i_copy - 11];
            i_copy = 0;
        }
        if (i_copy > 0)
        {
            numstr += arr1[i_copy - 1];
            i_copy = 0;
        }

        if (numstr.length() + len == i)
        {
            return numstr;
        }

        // std::cout << numstr << '\n';
    } while (++i < 1000);

    return "";
}

int main()
{
    int n;
    std::cin >> n;

    int len = 0;
    std::vector<std::string> arr(n);
    for (std::string &val : arr)
    {
        std::cin >> val;

        if (val != "$")
            len += val.length();
    }

    // std::cout << len << '\n';

    for (const std::string &val : arr)
    {
        if (val != "$")
        {
            std::cout << val << ' ';
        } else
        {
            std::cout << get_numstr(len) << ' ';
        }
    }
}
