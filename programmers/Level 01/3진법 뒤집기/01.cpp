#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> tmp;

    while (n != 0) {
        tmp.push_back(n % 3);
        n /= 3;
    }
    int x = 1;
    for (int i = tmp.size() - 1; i >= 0; i--) {
        answer += tmp[i] * x;
        x *= 3;
    }
    return answer;
}
