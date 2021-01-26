vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> fst = { 1,2,3,4,5 };
    vector<int> snd = { 2,1,2,3,2,4,2,5 };
    vector<int> trd = { 3,3,1,1,2,2,4,4,5,5 };

    int cntF = 0, cntS = 0, cntT = 0;
    // 1번 수포자 [1,2,3,4,5]
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == fst[i - ((i / 5) * 5)]) ++cntF;
    }
    // 2번 수포자 [2.1.2.3.2.4.2.5]
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == snd[i - ((i / 8) * 8)]) ++cntS;
    }
    // 3번 수포자 [3,3,1,1,2,2,4,4,5,5]
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == trd[i - ((i / 10) * 10)]) ++cntT;
    }

    int max;
    if (cntF >= cntS && cntF >= cntT) max = cntF;
    else if (cntS >= cntF && cntS >= cntT) max = cntS;
    else if (cntT >= cntF && cntT >= cntS) max = cntT;

    if (cntF == max) {
        answer.push_back(1);
    }
    if (cntS == max) {
        answer.push_back(2);
    }
    if (cntT == max) {
        answer.push_back(3);
    }
    return answer;
}
