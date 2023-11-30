#include <iostream>
#include<vector>
#include<cmath>
#include<stack>

using namespace std;

int n, p;
stack<int> ss[7];
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> p;

	while (n--) {
		int a, b;
		cin >> a >> b;
		if (ss[a].empty()) {
			ss[a].push(b);
			ans++;
		}
		else {
			while (!ss[a].empty() && ss[a].top() > b) {
				ss[a].pop();
				ans++;
			}

			if (ss[a].empty()) {
				ss[a].push(b);
				ans++;
			}
			else {
				if (ss[a].top() == b) {

				}
				else {
					ss[a].push(b);
					ans++;
				}
			}

		}
	}

	cout << ans << '\n';


	return 0;
}