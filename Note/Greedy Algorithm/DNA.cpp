// BOJ 1969번 문제

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int DNA수, 이름길이, 합 = 0;
    vector<string> DNA벡터;
    int 뉴클레오티드[4] = { 0, }; // A,C,G,T 순

    cin >> DNA수 >> 이름길이;

    for (int i = 0; i < DNA수; i++) {
        string 입력;
        cin >> 입력;
        DNA벡터.push_back(입력);
    }

    // 가장 많이 겹치는거 출력
    for (int i = 0; i < 이름길이; i++) {
        for (int j = 0; j < DNA수; j++) {
            if (DNA벡터[j][i] == 'A') 뉴클레오티드[0]++;
            else if (DNA벡터[j][i] == 'C') 뉴클레오티드[1]++;
            else if (DNA벡터[j][i] == 'G') 뉴클레오티드[2]++;
            else if (DNA벡터[j][i] == 'T') 뉴클레오티드[3]++;
        }
        int 최빈인덱스 = 0;
        for (int j = 0; j < 4; j++) {
            if (뉴클레오티드[최빈인덱스] < 뉴클레오티드[j]) {
                최빈인덱스 = j;
            }
        }
        if (최빈인덱스 == 0) cout << 'A';
        else if (최빈인덱스 == 1) cout << 'C';
        else if (최빈인덱스 == 2) cout << 'G';
        else if (최빈인덱스 == 3) cout << 'T';

        합 += DNA수 - 뉴클레오티드[최빈인덱스];
        for (int j = 0; j < 4; j++) {
            뉴클레오티드[j] = 0;
        }
    }

    cout << '\n' << 합;

    return 0;
}
