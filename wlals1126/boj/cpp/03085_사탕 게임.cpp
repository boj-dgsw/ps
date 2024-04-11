#include <iostream>
#include <cmath>
using namespace std;

char arr[51][51] = {0};
int n;
int ans=0;

int max(int a, int b) {
    return a > b ? a : b;
}

void swap(int x1, int y1, int x2, int y2) {
    int tmp = arr[x1][y1];
    arr[x1][y1] = arr[x2][y2];
    arr[x2][y2] = tmp;
}

int count() {
    int cnt, res=0;
    char str;
    
    for(int i = 0; i < n; i++){
        cnt = 1; str = arr[0][i];
        for(int j = 1; j <= n; j++){
            if(str == arr[j][i]) cnt++;
            else{
                str = arr[j][i];
                res = max(res, cnt);
                cnt = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cnt = 1; str = arr[i][0];
        for(int j = 1; j <= n; j++){
            if(str == arr[i][j]) cnt++;
            else{
                str = arr[i][j];
                res = max(res, cnt);
                cnt = 1;
            }
        }
    }
    return res;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < n; l++) {
                    if(abs(i - k) == 1 && abs(j - l) == 0) {
                        swap(i, j, k, l);
                        ans = max(ans, count());
                        swap(i, j, k, l);
                    }
                    if(abs(i - k) == 0 && abs(j - l) == 1) {
                        swap(i, j, k, l);
                        ans = max(ans, count());
                        swap(i, j, k, l);
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
