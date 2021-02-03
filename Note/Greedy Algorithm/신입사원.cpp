// BOJ 1946번 문제

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        pair<int, int> p[100000];
        bool fall[100000] = { 0, };

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> p[i].first >> p[i].second;
        }
        sort(p, p + N);

        // 최솟값을 지금 당장의 최적의 해를 구하기 위해 바꿔줌 (그리디 핵심)
        int cnt = 1;
        int min = p[0].second;
        for (int i = 1; i < N; i++) {
            if (min > p[i].second) {
                min = p[i].second;
                cnt++;
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}
