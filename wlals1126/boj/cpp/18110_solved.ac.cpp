#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;
int main(){
    deque<int> q;
    int rep;
    cin >> rep;
    for(int i = 0; i < rep; i++){
        int tmp;
        cin >> tmp;
        q.push_back(tmp);
    }
    
    sort(q.begin(),q.end());

    int removeN = round(rep *0.15);

    for(int i = 0; i < removeN; i++){
        q.pop_front();
        q.pop_back();
    }

    int avg = 0;
    for(int i : q){
        avg += i;
    }

    if(rep == 0){
        cout << 0;
    } else {
        cout << round((double) avg/q.size());
    }
}
