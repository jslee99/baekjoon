#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[100005];
int s[100005];

int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}

	//¹ú ¹ú ²Ü
	for (int i = 2; i <= n - 1; i++) {
		int sum = 0;
		sum += s[i - 1] - s[1];
		sum += 2 * (s[n] - s[i]);
		ans = max(ans, sum);
	}

	//²Ü “¯ ¹ú
	for (int i = 2; i <= n - 1; i++) {
		int sum = 0;
		sum += 2 * (s[i - 1] - s[0]);
		sum += s[n - 1] - s[i];
		ans = max(ans, sum);
	}

	int idx = 1;
	for (int i = 2; i <= n - 1; i++) {
		if (a[idx] < a[i]) idx = i;
	}

	ans = max(ans, s[n - 1] - s[1] + a[idx]);

	cout << ans << '\n';
}