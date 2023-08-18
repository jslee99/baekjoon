#include<iostream>
#include<climits>

using namespace std;

int n;
string eq;
int ans = INT_MIN;

int calc(int a, int b, char op) {
	switch (op) {
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	}
}

void solve(int idx, int cur) {//idx는 숫자를 가리킨다
	if (idx == n - 1) {
		int r = calc(cur, eq[idx] - '0', eq[idx - 1]);
		ans = max(ans, r);
	}
	else if (idx >= n) {
		ans = max(ans, cur);
	}
	else {
		//묶기
		int r = calc(cur, calc(eq[idx] - '0', eq[idx + 2] - '0', eq[idx + 1]), eq[idx - 1]);
		solve(idx + 4, r);
		//안묶기
		int r2 = calc(cur, eq[idx] - '0', eq[idx - 1]);
		solve(idx + 2, r2);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cin >> eq;
	eq.insert(0, "+");
	n = eq.size();

	solve(1, 0);

	cout << ans << '\n';

	return 0;
}