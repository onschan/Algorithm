#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int target, int sum, int index) {
    // 종료조건
    if(index == numbers.size())
    {
        if(sum == target) answer++;
        return;
    }    
    // 재귀 호출
    DFS(numbers, target, sum+numbers[index], index+1);
    DFS(numbers, target, sum-numbers[index], index+1);
}

int solution(vector<int> numbers, int target) { // 사용할 수 있는 숫자 , 타겟 넘버
    
    DFS(numbers,target, 0, 0);
    
    return answer;  // 타겟 넘버 만드는 방법의 수 
}
