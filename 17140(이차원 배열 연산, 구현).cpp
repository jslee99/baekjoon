#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int r, c, k;
int map[100][100];
int R = 3, C = 3;
int T;

bool cmp(const pair<int, int>& a,const pair<int, int>& b) {
	if (a.second < b.second) {
		return true;
	}
	else if (a.second > b.second) {
		return false;
	}
	else {
		return a.first < b.first;
	}
}

int main(void) {
	cin >> r >> c >> k;
	r--, c--;
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> map[i][j];

	for (T = 0; T <= 100; T++) {
		if (map[r][c] == k) break;


		vector<vector<pair<int, int>>> v;

		if (R >= C) {//행연산
			for (int i = 0; i < R; i++) v.push_back(vector<pair<int,int>> ());

			for (int i = 0; i < R; i++) {
				int cnt[101];
				for (int j = 1; j < 101; j++) cnt[j] = 0;

				for (int j = 0; j < C; j++) {
					if (map[i][j] == 0) continue;

					cnt[map[i][j]]++;
				}

				for (int j = 1; j < 101; j++) {
					if (cnt[j] == 0) continue;

					v[i].push_back(make_pair(j, cnt[j]));
				}

				sort(v[i].begin(), v[i].end(), cmp);
			}

			C = 0;
			for (int i = 0; i < R; i++) {
				C = max(C, (int)v[i].size() * 2);
			}
			if (C > 100) C = 100;

			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (j / 2 >= (int)v[i].size()) {
						map[i][j] = 0;
					}else if (j % 2 == 0) {
						map[i][j] = v[i][j / 2].first;
					}
					else {
						map[i][j] = v[i][j / 2].second;
					}
				}
			}
		}
		else {//열연산
			for (int j = 0; j < C; j++) v.push_back(vector<pair<int, int>>());

			for (int j = 0; j < C; j++) {
				int cnt[101];
				for (int i = 1; i < 101; i++) cnt[i] = 0;

				for (int i = 0; i < R; i++) {
					if (map[i][j] == 0) continue;

					cnt[map[i][j]]++;
				}

				for (int i = 1; i < 101; i++) {
					if (cnt[i] == 0) continue;

					v[j].push_back(make_pair(i, cnt[i]));
				}

				sort(v[j].begin(), v[j].end(), cmp);
			}

			R = 0;
			for (int j = 0; j < C; j++) R = max(R, (int)v[j].size() * 2);
			if (R > 100) R = 100;

			for (int j = 0; j < C; j++) {
				for (int i = 0; i < R; i++) {
					if (i / 2 >= (int)v[j].size()) {
						map[i][j] = 0;
					}
					else if (i % 2 == 0) {
						map[i][j] = v[j][i / 2].first;
					}
					else {
						map[i][j] = v[j][i / 2].second;
					}
				}
			}
		}
	}
	
	if (T == 101) T = -1;
	cout << T << endl;
}
