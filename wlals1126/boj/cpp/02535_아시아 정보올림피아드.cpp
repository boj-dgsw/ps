#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int country;
    int studentId;
    int score;
};

bool compareScore(const Student &a, const Student &b) {
    return a.score > b.score;
}

int main() {
    int n;
    cin >> n;

    vector<Student> stu(n);
    for (int i = 0; i < n; ++i) {
        cin >> stu[i].country >> stu[i].studentId >> stu[i].score;
    }

    sort(stu.begin(), stu.end(), compareScore);

    int list[101] = {0};
    int res[3][2];
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (i < 2) {
            res[count][0] = stu[i].country;
            res[count][1] = stu[i].studentId;
            count++;
            list[stu[i].country]++;
        } else if (list[stu[i].country] >= 2) {
            continue;
        } else {
            res[count][0] = stu[i].country;
            res[count][1] = stu[i].studentId;
            break;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
