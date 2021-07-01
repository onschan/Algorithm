#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> lpq;
    priority_queue<int, vector<int>, greater<int> > gpq;
    int size = 0;

    for (int i = 0; i < operations.size(); i++) {
        if (size == 0) {
            while (!lpq.empty())
                lpq.pop();
            while (!gpq.empty())
                gpq.pop();
        }
        if (operations[i][0] == 'I') {
            int num2 = stoi(operations[i].substr(2));
            lpq.push(num2);
            gpq.push(num2);
            size++;
        }
        else if (operations[i] == "D 1") {
            // 최대값 제거
            if (size != 0) {
                lpq.pop();
                size--;
            }
        }
        else {  // D -1
            // 최솟값 제거
            if (size != 0) {
                gpq.pop();
                size--;
            }
        }
    }
    if (size == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(lpq.top());
        answer.push_back(gpq.top());
    }
    return answer;
}
