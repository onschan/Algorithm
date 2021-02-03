// BOJ 10610 문제

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;
    cin >> N;

    sort(N.begin(), N.end());

    int num = 0;
    if (N[0] == '0') {
        for (int i = 1; i < N.length(); i++) {
            num += ((int)N[i] - 48);
        }
        if (num % 3 == 0) {
            for (int j = N.length() - 1; j >= 0; j--) {
                cout << N[j];
            }
        }
        else
            cout << -1;
    }
    else
        cout << -1;
    
    return 0;
}
