#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int,string> a, pair<int,string> b) {
    return a.first < b.first;   //오름차순
    //return a.first > b.first  //내림차순
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, string> > v;

    v.push_back(pair<int, string>(9, "A"));
    v.push_back(pair<int, string>(1, "B"));
    v.push_back(pair<int, string>(2, "C"));
    v.push_back(pair<int, string>(5, "D"));
    v.push_back(pair<int, string>(2, "E"));
    v.push_back(pair<int, string>(4, "F"));

    sort(v.begin(), v.end(),compare);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].second << ' ';
    }
    return 0;
}
