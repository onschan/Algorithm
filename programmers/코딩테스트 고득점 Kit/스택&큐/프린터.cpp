#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 1;
    int max = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(pair<int, int>(priorities[i], i));
    }

    sort(priorities.begin(), priorities.end());
    max = priorities.back();
    priorities.pop_back();

    while (!q.empty()) {
        if (q.front().first < max) {
            pair<int, int> p = q.front();
            q.pop();
            q.push(p);
        }
        else if(q.front().first == max) {
            if (q.front().second == location)
                return answer;
            q.pop();
            max = priorities.back();
            priorities.pop_back();
            answer++;

        }
    }
    return 0;
}
