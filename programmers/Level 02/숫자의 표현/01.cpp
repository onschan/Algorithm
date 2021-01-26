#include <string>
#include <vector>

using namespace std;


int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        int add = i;
        while (true) {
            sum += add;
            ++add;
            if (sum == n) {
                ++answer;
                break;
            }
            else if (sum > n) {
                break;
            }
        }
    }

    return answer;
}
