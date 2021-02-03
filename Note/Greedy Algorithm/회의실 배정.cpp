// BOJ 1931번 문제

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)	// 끝나는 시간이 같으면 늦게 시작한 것이 뒤로
		return a.first < b.first;
    return a.second < b.second;	// 늦게 끝나는 것이 뒤로
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int 회의의_수;
	vector< pair<int, int> > 시간표;

	cin >> 회의의_수;

	for (int i = 0; i < 회의의_수; i++) {
		int 시작시각,종료시각;
		cin >> 시작시각 >> 종료시각;
		시간표.push_back({ 시작시각, 종료시각 });
	}

	sort(시간표.begin(), 시간표.end(), compare);

	int 기준시각 = 시간표[0].second;	// 가장 먼저 끝나는 첫번째 회의가 끝나는 시각
	int 가능한_회의수 = 1;
	for (int i = 1; i < 회의의_수; i++)
	{
		// 다음으로 먼저 끝나는 회의의 시작시간이 기준시각보다 늦다면
		// 기준 시각을 해당 회의의 종료시간으로 변경 후 카운팅
		if (기준시각 <= 시간표[i].first)		
		{
			기준시각 = 시간표[i].second;
			가능한_회의수++;
		}
	}

	cout << 가능한_회의수 << '\n';

    return 0;
}
