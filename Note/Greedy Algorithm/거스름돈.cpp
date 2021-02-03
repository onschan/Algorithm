// BOJ 5585번 문제

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int 지불한_돈, 잔돈의_수 = 0;;
    cin >> 지불한_돈;

    int 거스름돈 = 1000 - 지불한_돈;
    
    잔돈의_수 += 거스름돈 / 500;
    거스름돈 %= 500;
    
    잔돈의_수 += 거스름돈 / 100;
    거스름돈 %= 100;
    
    잔돈의_수 += 거스름돈 / 50;
    거스름돈 %= 50;
    
    잔돈의_수 += 거스름돈 / 10;
    거스름돈 %= 10;
    
    잔돈의_수 += 거스름돈 / 5;
    거스름돈 %= 5;
    
    잔돈의_수 += 거스름돈;

    cout << 잔돈의_수;

    return 0;
}
