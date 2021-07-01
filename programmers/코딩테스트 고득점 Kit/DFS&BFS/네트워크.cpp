#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visited[200] = { 0, };
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            visited[i] = true;
            for (int j = 0; j < n; j++) {
                if (computers[i][j] == 1 && !visited[j]) {
                    q.push(j);
                    visited[j] = true;
                }
            }
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                
                for (int j = 0; j < n; j++) {
                    if (computers[now][j] == 1 && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
    return answer;
}
