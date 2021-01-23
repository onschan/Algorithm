#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> bag;

    int index = 0;
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i] - 1] == 0) {
                continue;
            }
            else {
                bag.push_back(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;
                index++;
                break;
            }
        }
        if (index > 1) {
            if (bag[index - 1] == bag[index - 2]) {
                bag.pop_back();
                bag.pop_back();
                --index;
                --index;
                ++answer;
                ++answer;
            }
        }
    }
    return answer;
}
