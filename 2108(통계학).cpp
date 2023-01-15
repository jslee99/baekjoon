#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
int num[500000];
int sorted[500000];
int cnt[8001];
bool visited[8001];
int N;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		sorted[i] = num[i];
	}

	sort(sorted, sorted + N);

	//
	int sum = 0;
	for (int i = 0; i < N; i++) sum += num[i];

	int ans = round((double)sum / (double)N);
	cout << (int)ans << endl;
	//
	cout << sorted[N / 2] << endl;
	//
	int max_cnt = -1;
	ans = -1;
	for (int i = 0; i < N; i++) {
		cnt[num[i] + 4000]++;
		if (cnt[num[i] + 4000] > max_cnt) {
			max_cnt = cnt[num[i] + 4000];
		}
	}
	vector<int> v;
	for (int i = 0; i < N; i++) {
		if (cnt[num[i] + 4000] == max_cnt) {
			if (!visited[num[i] + 4000]) {
				visited[num[i] + 4000] = true;
				v.push_back(num[i]);
			}
		}
	}

	sort(v.begin(), v.end());

	if (v.size() == 1) {
		ans = v[0];
	}
	else {
		ans = v[1];
	}

	cout << ans << endl;
	//
	cout << sorted[N - 1] - sorted[0] << endl;
}
