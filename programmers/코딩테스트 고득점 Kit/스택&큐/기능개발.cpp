#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {  // progresses: [93, 30, 55]  speeds : [1, 30, 5]
    vector<int> answer;
    int day = 0, done = 0;

    while (progresses[0] < 100) {
        progresses[0] += speeds[0];
        day++;
    }
    done++;

    for (int i = 1; i < progresses.size(); i++) {
        progresses[i] += speeds[i] * day;
        if (progresses[i] >= 100) {
            done++;
        }
        else {
            answer.push_back(done);
            done = 0;

            while (progresses[i] < 100) {
                progresses[i] += speeds[i];
                day++;
            }
            done++;

        }
    }

    answer.push_back(done);

    return answer;  // [2, 1]
}
