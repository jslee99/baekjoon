#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
int number[8];//0 ~ N - 1
vector<vector<int>> sequences;
int idx_list[8];//0 ~ M - 1

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	sort(number, number + N);

	for (int i = 0; i < M; i++) {
		idx_list[i] = 0;
	}

	while (1) {
		bool flag = true;
		for (int i = 0; i < (int)sequences.size(); i++) {
			bool is_same = true;
			for (int j = 0; j < (int)sequences[i].size(); j++) {
				if (sequences[i][j] != number[idx_list[j]]) {
					is_same = false;
					break;
				}
			}
			if (is_same) {
				flag = false;
				break;
			}
		}

		if (flag) {//중복 없는 경우, 추가
			vector<int> v;
			for (int i = 0; i < M; i++) {
				v.push_back(number[idx_list[i]]);		
			}
			sequences.push_back(v);
		}
		else {//중복있는 경우

		}

		if (idx_list[0] == N - 1) break;

		flag = false;
		for (int i = M - 1; i >= 0; i--) {
			if (flag) break;
			if (idx_list[i] < N - 1) {
				if (i == M - 1) {
					idx_list[i]++;
					flag = true;
				}
				else {
					idx_list[i]++;
					for (int j = i + 1; j < M; j++) {
						idx_list[j] = idx_list[i];
					}
					flag = true;
				}
			}
		}
	}

	for (int i = 0; i < (int)sequences.size(); i++) {
		for (int j = 0; j < (int)sequences[i].size(); j++) {
			cout << sequences[i][j] << " ";
		}
		cout << endl;
	}
}
