// implementation
// simulation
// Silver IV

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

enum BallType
{
    BALL = 1,
    HIT_BY_PITCH,
    WILD_PITCH,
};

int score = 0;
bool bases[4];
int ball_count = 0;

void ball();
void base_on_balls();
void hit_by_pitch();
void wild_pitch();

int main()
{
    FAST_IO

    int n;
    cin >> n;

    while (n--)
    {
        int ball_type;
        cin >> ball_type;

        switch (ball_type)
        {
            case BALL:
                ball();
                break;
            case HIT_BY_PITCH:
                hit_by_pitch();
                break;
            case WILD_PITCH:
                wild_pitch();
                break;

            default: break;
        }
    }

    cout << score;
}

void ball()
{
    ball_count += 1;

    if (ball_count == 4)
    {
        base_on_balls();
    }
}

void base_on_balls()
{
    ball_count = 0;

    if (int sum = bases[1] + bases[2] + bases[3]; sum == 3)
    {
        score++;
    }
    else if (sum == 2)
    {
        bases[1] = bases[2] = bases[3] = true;
    }
    else if (sum == 1)
    {
        if (bases[1])
            bases[1] = bases[2] = true;

        else
            bases[1] = true;
    }
    else
    {
        bases[1] = true;
    }
}


void hit_by_pitch()
{
    base_on_balls();
}

void wild_pitch()
{
    if (bases[3])
    {
        bases[3] = false;
        score++;
    }

    bases[3] = bases[2];
    bases[2] = false;

    bases[2] = bases[1];
    bases[1] = false;

    ball();
}
