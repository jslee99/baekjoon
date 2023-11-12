#include<iostream>

using namespace std;
bool isSelected[15];
int queen[15];
int T,n ;

int ans;

bool can() {
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;

			if (abs(i - j) == abs(queen[i] - queen[j])) flag = false;

			if (flag == false) break;
		}
		if (flag == false) break;
	}
	return flag;
}

void select(int selectR) {
	if (selectR > n) {
		if (can()) ans++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!isSelected[i]) {
			isSelected[i] = true;
			queen[selectR] = i;
			select(selectR + 1);
			isSelected[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		ans = 0;
		select(1);

		cout << '#' << t << ' ' << ans << '\n';
	}

}