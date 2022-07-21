#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int height[10000];
vector<int> v;
int T;
int N;

int main(void){
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int ans = 0;
		scanf("%d", &N);
		for (int n = 0; n < N; n++) {
			scanf("%d", &height[n]);
		}
		sort(height, height + N);

		for (int i = N - 1; i >= 0; i--) {
			if (i % 2 == 0) {
				v.insert(v.begin(), height[i]);
			}
			else {
				v.push_back(height[i]);
			}
		}

		for (int i = 0; i <= N - 2; i++) {
			ans = max(ans, abs(v[i] - v[i + 1]));
		}
		printf("%d\n", ans);
		v.clear();
	}

}