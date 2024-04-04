#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int cn; // case number
    cin >> cn;
    
    while (cn--)
    {
        int scn; // sub case number
        cin >> scn;
        
        double sum = 0.0;
        while (scn--)
        {
            string ign;
            int amt; double price;
            cin >> ign >> amt >> price;
            
            sum += amt * price;
        }
        
        sum = round(sum * 100) / 100;
        printf("$%.2lf\n", sum);
    }
}
