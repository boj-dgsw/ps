// data structures
// hash
// Silver III

#include <bits/stdc++.h>

int main()
{
    int n, p, w, l, g;
    std::cin >> n >> p >> w >> l >> g;

    std::unordered_map<std::string, char> list;
    int score = 0;

    for (int i = 0; i < p; i++)
    {
        std::string name;
        char result;

        std::cin >> name >> result;

        list[name] = result;
    }

    for (int i = 0; i < n; i++)
    {
        std::string name;
        std::cin >> name;

        if (!list.contains(name) || list[name] == 'L')
        {
            score = std::max(0, score - l);
            continue;
        }

        score += w;
        if (score >= g)
        {
            std::cout << "I AM NOT IRONMAN!!";
            return 0;
        }
    }

    std::cout << "I AM IRONMAN!!";
}
