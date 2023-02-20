#include<iostream>
#include<queue>

using namespace std;

struct data {
	int id;
	int val;
};

struct cmp_less {
	bool operator() (const struct data& a, const struct data& b) {
		return a.val > b.val;
	}
};
struct cmp_greater {
	bool operator() (const struct data& a, const struct data& b) {
		return a.val < b.val;
	}
};

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		bool is_deleted[1000000];
		char op;
		int val;
		int id = 0;
		priority_queue<struct data, vector<struct data>, cmp_less> less_pq;
		priority_queue<struct data, vector<struct data>, cmp_greater> greater_pq;
		for (int i = 0; i < N; i++) is_deleted[i] = false;

		for (int i = 0; i < N; i++) {
			cin >> op >> val;

			switch (op) {
			case 'D':
				switch (val) {
				case -1:
					while (!less_pq.empty() && is_deleted[less_pq.top().id]) less_pq.pop();

					if (less_pq.empty()) {
					}
					else {
						is_deleted[less_pq.top().id] = true;
						less_pq.pop();
					}

					break;
				case 1:
					while (!greater_pq.empty() && is_deleted[greater_pq.top().id]) greater_pq.pop();

					if (greater_pq.empty()) {
					}
					else {
						is_deleted[greater_pq.top().id] = true;
						greater_pq.pop();
					}

					break;
				}
				break;
			case 'I':
				struct data x;
				x.id = id++;
				x.val = val;
				less_pq.push(x);
				greater_pq.push(x);
				break;
			}

			
			
		}
		while (!less_pq.empty() && is_deleted[less_pq.top().id]) 
			less_pq.pop();
		

		while (!greater_pq.empty() && is_deleted[greater_pq.top().id])
			greater_pq.pop();

		if (less_pq.empty() && greater_pq.empty()) cout << "EMPTY" << '\n';
		else cout << greater_pq.top().val << " " << less_pq.top().val << '\n';
	}

}