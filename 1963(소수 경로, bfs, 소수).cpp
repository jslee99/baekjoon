#include<iostream>
#include<queue>
#include<cmath>
#include<string>

using namespace std;

int visited[10001];
int T;
int a, b;
bool is_prime[10001];

void reset() {
	for (int i = 1000; i <= 10000; i++) visited[i] = -1;
}

void prime() {
	for (int i = 1; i <= 10000; i++) is_prime[i] = true;
	is_prime[1] = false;
	for (int i = 1; i <= 10000; i++) {
		if (is_prime[i]) {
			for (int j = 2; i * j <= 10000; j++) {
				is_prime[i * j] = false;
			}
		}
	}
}

int main(void) {

	cin >> T;
	while (T--) {
		prime();
		reset();
		queue<pair<int, int>> q;
		cin >> a >> b;
		q.push(make_pair(a, 0));

		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();

			if (visited[cur.first] != -1) continue;

			visited[cur.first] = cur.second;

			for (int i = 0; i < 4; i++) {
				if (i == 0) {
					string str = to_string(cur.first);
					for (char j = '1'; j <= '9'; j++) {
						str[i] = j;
						int a = stoi(str);
						if (is_prime[a] && visited[a] == -1) {
							q.push(make_pair(a, cur.second + 1));
						} 
					}
				}
				else {
					string str = to_string(cur.first);
					for (char j = '0'; j <= '9'; j++) {
						str[i] = j;
						int a = stoi(str);
						if (is_prime[a] && visited[a] == -1) {
							q.push(make_pair(a, cur.second + 1));
						}
					}
				}
			}
		}

		if (visited[b] == -1) cout << "Impossible" << endl;
		else cout << visited[b] << endl;
	}
}

