//에라토스테네스의 체 : 다수의 소수 판별 알고리즘

#define _CRT_SECURE_NO_WARNINGS
#define number 100000

#include <iostream>
#include <math.h>

using namespace std;

int a[number + 1];

void seivePrimeNumber() {
    for (int i = 2; i <= number; i++) {
        a[i] = i;
    }
    for (int i = 2; i <= number; i++) {
        if (a[i] == 0) continue;
        for (int j = i + i; j <= number; j += i) {
            a[j] = 0;
        }
    }
    for (int i = 2; i <= number; i++) {
        if (a[i] != 0) cout << a[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    seivePrimeNumber();

    return 0;
}
