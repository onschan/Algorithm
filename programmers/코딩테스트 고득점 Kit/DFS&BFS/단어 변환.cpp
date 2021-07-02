#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> numAns;
string G_begin;
void DFS(string begin, string target, vector<string> words, int cur_pos, int answer, vector<bool> visited) {
    cout << visited[cur_pos]; 
    if(visited[cur_pos]) return;   // 인덱스 범위 벗어나면 종료
        
    //cout << begin << '\n' << cur_pos << '\n' << answer << '\n';
    
    if(begin != G_begin)
    visited[cur_pos] = true;
    
    if(words[cur_pos] == target && answer > 0) {
        numAns.push_back(answer);
        return;   // 타겟 찾으면 종료, answer 반환
    }    
    
    for(int i = 0; i < words.size(); i++) {
        // 알파벳 하나만 다른지 확인
        int numDiff = 0;
        for(int j = 0; j < begin.length(); j++) {
            if(begin[j] != words[i][j]) numDiff++;
        }

        // 알파벳 하나만 다른 경우 재귀 호출
        if(numDiff == 1) {
            DFS(words[i],target,words,i,answer+1,visited);
        }
    }
}

int solution(string begin, string target, vector<string> words) {   // 시작단어, 타겟단어, 단어집합
    vector<bool> visited (words.size(),false);
    G_begin = begin;
    
    DFS(begin,target,words,0,0,visited);
    
    if(numAns.size() == 0) return 0;
    
    int min = numAns.front();
    for(auto k : numAns) {
        if(k < min) min = k;
    }

    return min;  // 최소 몇 단계의 과정이 소요되는 지
}
