int solution(int n) {
    int answer = 0;
    int cnt = 0;
    bool check = true;
    vector<int> v;

    while (n != 0) {
        v.push_back(n % 2);
        n /= 2;
    }

    for (auto k : v) {
        if (k == 1)
            ++cnt;
    }

    int oneCnt = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] == 1 && v[i+1] == 1) {
            ++oneCnt;
        }
        else if (v[i] == 1 && v[i + 1] == 0) {
            v[i + 1] = 1;
            for (int j = 0; j <= i; j++) {
                v[j] = 0;
            }
            for (int k = 0; k < oneCnt; k++) {
                v[k] = 1;
            }
            check = false;
            break;
        }
    }

    if (!check) {
        int x = 1;
        for (int i = 0; i < v.size(); i++) {
            answer += v[i] * x;
            x *= 2;
        }
    }
    else {
        for (int i = 0; i < v.size(); i++) {
            v[i] = 0;
        }
        v.push_back(1);
        for (int i = 0; i < cnt - 1; i++) {
            v[i] = 1;
        }
        int x = 1;
        for (int i = 0; i < v.size(); i++) {
            answer += v[i] * x;
            x *= 2;
        }
    }

    return answer;
}
