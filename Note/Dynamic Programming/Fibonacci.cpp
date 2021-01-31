#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int memo[100];

int fibonacci_dp(int n) {
    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n];
    return memo[n] = fibonacci_dp(n - 1) + fibonacci_dp(n - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fibonacci_dp(30);

    return 0;
}
