#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}
int solution(vector<vector<int>> triangle) {
    int memo[500][500];
    int answer = 0;   

    memo[0][0] = triangle[0][0];

    // 메모이제이션
    // 두가지의 경우에서 들어오는 경우, (외곽지역) 한가지의 경우만 들어오는 경우에 따라 나눠서 메모
    for(int depth = 1; depth < triangle.size(); depth++){
        for(int i = 0; i <= depth; i++) {
            if(i == 0) {
                memo[depth][i] = triangle[depth][i] + memo[depth-1][i];
            }
            else if(i == depth) {
                memo[depth][i] = triangle[depth][i] + memo[depth-1][i-1];
            }
            else {
                memo[depth][i] = triangle[depth][i] + max(memo[depth-1][i-1],memo[depth-1][i]);
            }
         }
    }
    
    int max = memo[triangle.size() - 1][0];
    for(int i = 0; i <= triangle.size(); i++) {
        if(max < memo[triangle.size() -1][i]) max = memo[triangle.size() -1][i];
    }
   
    return max;
}
