#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int A[1000005];
vector<int> v;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	v.push_back(-1000000001);
	for (int i = 1; i <= n; i++) {
		vector<int>::iterator it = lower_bound(v.begin(), v.end(), A[i]);
		if (it == v.end()) {
			v.push_back(A[i]);
		}
		else if (A[i] < *it) {
			*it = A[i];
		}
	}

	cout << v.size() - 1 << '\n';
}