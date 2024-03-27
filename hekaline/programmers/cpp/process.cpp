#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Process
{
public:
    int priority;
    int location;
    
public:
    Process(int _priority, int _location) : 
        priority(_priority), location(_location){}
};

int solution(vector<int> priorities, int location) 
{
    int answer = 1;
    
    // priorities를 옮길 큐
    queue<Process> q;
    
    // 우선순위를 오름차순으로 정렬할 벡터
    vector<int> priorityStack = priorities;
    sort(priorityStack.begin(), priorityStack.end()); // 곧바로 정렬
    
    
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(Process(priorities[i], i));
    } 
    
    while(q.empty() == false)
    {
        // 현재 프로세스를 큐에서 꺼내온다.
        Process currProcess = q.front(); q.pop();
        
        // 현재 남은 프로세스들의 가장 높은 우선순위와 현재 프로세스 우선순위가 같은가?
        if (currProcess.priority == priorityStack.back())
        {
            if (currProcess.location == location)
            {
                // 우선순위를 찾고자 하는 위치와 같다면 정답 반환 및 종료
                return answer;
            } else
            {
                // 우선순위가 가장 높은 걸 찾았지만 위치가 다른 경우
                answer += 1;
                priorityStack.pop_back();
            }
        } else
        {
            q.push(currProcess);
        }
    }
    
    return answer;
}

