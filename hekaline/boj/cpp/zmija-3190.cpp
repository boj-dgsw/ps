// implementation
// data structures
// simulation
// deque / queue
// Gold IV

#include <bits/stdc++.h>
#define OUT
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;
using pii = pair<int, int>;

constexpr char ROT_LEFT = 'L';
constexpr char ROT_RIGHT = 'D';

enum Dir
{
    RIGHT = 0,
    DOWN,
    LEFT,
    UP
};

struct pair_hash
{
    size_t operator()(const pii& v) const
    {
        return v.first * 31 + v.second;
    }
};

int board_size;
int apple_count;
int move_count;
unordered_set<pii, pair_hash> apple_coords;
unordered_map<int, char> move_infos;

void input();
int play_game();
void set_dir(OUT int& curr_dir, char rot);
bool is_valid(int i, int j)
{ return 0 < i && i <= board_size && 0 < j && j <= board_size; }

int main()
{
    FAST_IO
    input();

    int survived_time = play_game();
    cout << survived_time;
}

int play_game()
{
    // [i][j]에 뱀이 있으면 true, 초기 맨 위 맨 좌측에 뱀이 위치함
    vector has_body(board_size + 1, vector<bool>(board_size + 1));
    has_body[1][1] = true;
    // 뱀을 대신하는 덱
    deque<pii> snail_deq;
    snail_deq.emplace_front(1, 1);

    // 생존 시간
    int second = 0;
    // 현재 뱀의 방향
    int dir = RIGHT;

    while (++second || true)
    {
        // head's coord
        pii next = snail_deq.front();
        switch (dir)
        {
            case RIGHT:
                next.second += 1;
                break;
            case DOWN:
                next.first += 1;
                break;
            case LEFT:
                next.second -= 1;
                break;
            case UP:
                next.first -= 1;
                break;
            default:
                cout << "error!";
                exit(0);
                break;
        }

        if (!is_valid(next.first, next.second) || has_body[next.first][next.second])
        {
            return second;
        }
        has_body[next.first][next.second] = true;

        // else
        snail_deq.emplace_front(next);
        if (!apple_coords.contains(next))
        {
            // 머리 쪽에 사과가 없으면 맨 뒤 꼬리 자르기
            auto [fst, snd] = snail_deq.back();
            has_body[fst][snd] = false;
            snail_deq.pop_back();
        }
        else
        {
            apple_coords.erase(next);
        }

        if (move_infos.contains(second))
        {
            // 방향 전환 필요
            set_dir(dir, move_infos[second]);
        }
    }

    return second;
}

void set_dir(OUT int &curr_dir, char rot)
{
    if (rot == ROT_LEFT)
    {
        if (curr_dir != RIGHT)
            curr_dir -= 1;
        else
            curr_dir = UP;
    }
    else // if (rot == ROT_RIGHT)
    {
        if (curr_dir != UP)
            curr_dir += 1;
        else
            curr_dir = RIGHT;
    }
}


void input()
{
    cin >> board_size;
    cin >> apple_count;

    for (int i = 0; i < apple_count; i++)
    {
        int x, y;
        cin >> x >> y;

        apple_coords.emplace(x, y);
    }

    cin >> move_count;
    for (int i = 0; i < move_count; i++)
    {
        int second;
        char rot;
        cin >> second >> rot;

        move_infos[second] = rot;
    }
}
