#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int n, l;
int ans = 0;
pair<int, int> a[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int aa, b;
		cin >> aa >> b;
		a[i] = make_pair(aa, --b);
	}

	sort(a, a + n);

	int c = -1;
	for (int i = 0; i < n; i++) {
		int s = a[i].first, e = a[i].second;
		if (e <= c) {
			continue;
		}
		else if (s <= c && c < e) {
			s = c + 1;
			int cnt;
			if ((e - s + 1) % l == 0) {
				cnt = (e - s + 1) / l;
			}
			else {
				cnt = (e - s + 1) / l + 1;
			}
			ans += cnt;
			c = s + cnt * l - 1;
		}
		else {
			int cnt;
			if ((e - s + 1) % l == 0) {
				cnt = (e - s + 1) / l;
			}
			else {
				cnt = (e - s + 1) / l + 1;
			}
			ans += cnt;
			c = s + cnt * l - 1;
		}
	}

	cout << ans << '\n';

	return 0; 
}