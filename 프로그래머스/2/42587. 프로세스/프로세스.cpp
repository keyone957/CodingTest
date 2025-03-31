#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q; // (우선순위, 원래 위치)
    priority_queue<int> pq; // 우선순위 큐 (최대 힙)
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    int answer = 0;
    while (!q.empty()) {
        int cur_priority = q.front().first;
        int cur_index = q.front().second;
        q.pop();
        
        // 현재 프로세스가 가장 높은 우선순위인지 확인
        if (cur_priority == pq.top()) {
            pq.pop();
            answer++;
            if (cur_index == location) {
                return answer;
            }
        } else {
            q.push({cur_priority, cur_index});
        }
    }
    
    return answer;
}