#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		if(abs(a) > abs(b)) {
			return true;
		}
		else if (abs(a) == abs(b)) {
			if (a > b) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
};

priority_queue<int, vector<int>, cmp> pq;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (n--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}

	return 0;
}