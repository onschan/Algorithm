#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;

    for (auto k : completion) {
        m[k] += 1;
    }

    for (auto k : participant) {
        m[k] -= 1;
        if (m[k] < 0)
            return k;
    }
}
