#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {  // [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]
    int answer = 1;

    unordered_map<string, int> um;

    for (int i = 0; i < clothes.size(); i++) {
        um[clothes[i][1]]++;
    }
    for (auto elem : um) {
        answer *= (elem.second + 1);
    }
    answer--;

    return answer;
}
