#include<iostream>
#include<algorithm>

using namespace std;

int n, d, k, c;

int a[30005];
int s[3005];
int ss = 0;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < k; i++) {
		s[a[i]]++;
	}
	for (int i = 1; i <= d; i++) {
		if (s[i] > 0) ss++;
	}
	if (s[c] == 0) ans = ss + 1;
	else ans = ss;



	for (int i = 1; i < n; i++) {
		int e = (i + k - 1) % n;
		
		s[a[i - 1]]--;
		if (s[a[i - 1]] == 0) ss--;

		s[a[e]]++;
		if (s[a[e]] < 2) ss++;

		if (s[c] == 0) ans = max(ans, ss + 1);
		else ans = max(ans, ss);
	}

	cout << ans << '\n';
}