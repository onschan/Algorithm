#include <string>
#include <vector>
#include <iostream>

using namespace std;

int memo[101][101];
bool filled[101][101];

void memoization(int row, int col) {
    // 초기화 조건
	if (row == 0 && col == 0) {
		memo[row][col] = 1;
		filled[row][col] = true;
		return;
	}
	if (row != 0 && !filled[row - 1][col]) {
		memoization(row -1, col);
	}
	if (col != 0 && !filled[row][col - 1]) {
		memoization(row, col-1);
	}
    
    if(row == 0) {
        memo[row][col] = memo[row][col - 1] % 1000000007; 
    }
    else if(col == 0) {
        memo[row][col] = memo[row - 1][col] % 1000000007; 
    }
    else {
        memo[row][col] = (memo[row - 1][col] + memo[row][col - 1])  % 1000000007;   
    }
	filled[row][col] = true;

	return;
}

int solution(int m, int n, vector<vector<int>> puddles) { // m x n 사각형 , 물이 잠긴 지역 puddles
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            memo[i][j] = 0;
        }
    }
    
    for(int i = 0; i < puddles.size(); i++) {
        if(puddles[i].size() != 0)
            filled[puddles[i][1] - 1][puddles[i][0] - 1] = true;
    }
       
    memoization(n-1,m-1);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << memo[i][j] << ' ';
        }
        cout << endl;
    }
    
    answer = memo[n-1][m-1];
    return answer;  // 최단 경로의 개수
}
