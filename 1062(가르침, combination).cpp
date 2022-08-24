#include<iostream>
using namespace std;

int N, K;
string words[50];
bool teached[26];
int teaching_word_idx_lst[27];// 0 ~ 25
//'b' - 'a' == 1
int ans = 0;

void counting() {
	for (int i = 0; i < 26; i++) teached[i] = false;

	for (int i = 1; i <= K - 5; i++) teached[teaching_word_idx_lst[i]] = true;

	teached['a' - 'a'] = true, teached['i' - 'a'] = true, teached['t' - 'a'] = true, teached['c' - 'a'] = true, teached['n' - 'a'] = true;

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < (int)words[i].size(); j++) {
			if (!teached[words[i][j] - 'a']) {
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
	}

	ans = max(ans, cnt);
}

void permutation(int depth) {
	if (depth == K - 4) {
		counting();
		return;
	}

	//	for (int i = teaching_word_idx_lst[depth - 1] + 1; i < 26 - (K + 1 - depth); i++) {
	for (int i = teaching_word_idx_lst[depth - 1] + 1; i < 26 - (K - 5 - depth); i++) {
		if (i == 'a' - 'a' || i == 'n' - 'a' || i == 't' - 'a' || i == 'i' - 'a' || i == 'c' - 'a') continue;
		teaching_word_idx_lst[depth] = i;
		permutation(depth + 1);
	}
}

int main(void) {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}

	if (K < 5) {
		cout << 0 << endl;
		exit(0);
	}

	teaching_word_idx_lst[0] = -1;
	permutation(1);

	cout << ans << endl;
}