#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool lostNum[32] = { 0, };
    bool reserveNum[32] = { 0, };
    for (int i = 0; i < lost.size(); i++) {
        lostNum[lost[i]] = true;
    }
    for (int i = 0; i < reserve.size(); i++) {
        reserveNum[reserve[i]] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (lostNum[i] == false) {
            ++answer;
        }
        else {
            if (reserveNum[i] == true) {
                reserveNum[i] = false;
                lostNum[i] = false;
                ++answer;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (lostNum[i] == true) {
            if (reserveNum[i - 1] == true) {
                reserveNum[i - 1] = false;
                ++answer;
            }
            else if (reserveNum[i + 1] == true) {
                reserveNum[i + 1] = false;
                ++answer;
            }
        }
    }

    return answer;
}
