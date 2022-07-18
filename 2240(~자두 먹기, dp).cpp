#include<iostream>
#include<algorithm>

using namespace std;

int T, W;
int what_tree[1001];//at second i what_tree?
int dp[1001][31];//TW
int max_count = -1;

int main(void) {//dp T W
	cin >> T >> W;
	for (int i = 1; i <= T; i++)
		cin >> what_tree[i];

	//W : even -> at tree 1   W : odd -> at tree 2
	//at start position is tree1

	if (what_tree[1] == 1)
		dp[1][1] = 0;
	else
		dp[1][1] = 1;

	int total_tree1_count = 0;
	for (int t = 1; t <= T; t++) {
		if (what_tree[t] == 1)
			total_tree1_count += 1;
		dp[t][0] = total_tree1_count;
	}



	for (int t = 2; t <= T; t++) {
		for (int w = 1; w <= W; w++) {
			if (w > t)
				break;

			if (what_tree[t] == 1) {
				if (w % 2 == 0) {//cur_pos : tree 1, what_tree  1
					dp[t][w] = max(dp[t - 1][w - 1] + 1, dp[t - 1][w] + 1);
				}
				else {//cur_post : tree 2, what_tree : 1
					dp[t][w] = max(dp[t - 1][w - 1], dp[t - 1][w]);
				}
			}
			else {
				if (w % 2 == 0) {//cur_pos : tree 1, what_tree : 2
					dp[t][w] = max(dp[t - 1][w - 1], dp[t - 1][w]);
				}
				else {//cur_post : tree 2, what_tree : 2
					dp[t][w] = max(dp[t - 1][w - 1] + 1, dp[t - 1][w] + 1);
				}
			}
		}
	}

	for (int w = 0; w <= W; w++) {
		if (w > T)
			break;
		max_count = max(max_count, dp[T][w]);
	}

	cout << max_count << endl;
}
