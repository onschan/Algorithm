#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string,pair<int,int>> a, pair<string, pair<int, int>> b) {
    if (a.second.first == b.second.first)
        return a.second.second < b.second.second;
    return a.second.first > b.second.first;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<string, pair<int,int>> > v;

    v.push_back(pair<string, pair<int, int>>("A", pair<int, int>(10, 150)));
    v.push_back(pair<string, pair<int, int>>("B", pair<int, int>(1, 120)));
    v.push_back(pair<string, pair<int, int>>("C", pair<int, int>(3, 140)));
    v.push_back(pair<string, pair<int, int>>("D", pair<int, int>(7, 190)));
    v.push_back(pair<string, pair<int, int>>("E", pair<int, int>(3, 1)));

    sort(v.begin(), v.end(),compare);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << ' ';
    }
    return 0;
}
