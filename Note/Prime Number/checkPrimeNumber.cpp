#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

bool isPrimeNumber(int x) {
    int end = (int)sqrt(x);
    for (int i = 2; i <= end; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << isPrimeNumber(n);

    return 0;
}
