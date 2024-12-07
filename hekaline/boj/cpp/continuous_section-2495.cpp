// implementation
// string

#include <bits/stdc++.h>

int main()
{
    for (int i = 1; i <= 3; i++)
    {
        std::string s;
        std::cin >> s;
        
        int max_streak = 1;
        int curr_streak = 1;
        char prev = s[0];
        
        for (int i = 1; i < s.length(); i++)
        {
            if (prev == s[i])
            {
                curr_streak++;
                max_streak = std::max(max_streak, curr_streak);
            } else
            {
                prev = s[i];
                curr_streak = 1;
            }
        }
        
        std::cout << max_streak << '\n';
    }
}
