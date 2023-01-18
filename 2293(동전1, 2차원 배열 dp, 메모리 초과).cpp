#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n, k;
vector<int> coin;
int dp[10001][100];

int main(void){
	cin >> n >> k;

	//int min_coin = 99999999;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		coin.push_back(a);
	}

	sort(coin.begin(), coin.end());

	if (coin[0] > k) {
		cout << 0 << endl;
		return 0;
	}



	//dp[coin[0]][0] = 1;
	//for (int i = 1; i < n; i++) dp[coin[0]][i] = 0;

	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < (int)coin.size(); j++) {
			if (i - coin[j] < 0) {
				dp[i][j] = 0;
				continue;
			}
			else if (i - coin[j] == 0) {
				dp[i][j] = 1;
				continue;
			}

			for (int m = 0; m <= j; m++) {
				dp[i][j] += dp[i - coin[j]][m];
			}
		}
	}

	int res = 0;
	for (int i = 0; i < (int)coin.size(); i++) {
		res += dp[k][i];
	}

	cout << res << endl;
}


//동전을 사용하는 순서는 항상 increasing order 즉 1원 쭈욱 사용하고 2원 쭈욱 사용하고 5원 쭈욱 사용하게된다.
// dp[i][j]는 i원을 만드는데 맨마지막에 coin[j]를 사용하는 경우를 뜻한다.
//따라서 dp[i][j]를 생성할때 dp[i][j] = dp[i - coin[0]][0] + (dp[i - coin[1]][1] + dp[i - coin[1]][1]) + .......
// 즉, 맨마지막에 coin[0]을 사용하여 i원을 만드는 경우(그전에 i - coin[0]월을 만들때 마지막에 coin[0]를 사용했어야 한다.) + 마지막에 coin[1]을 사용하여 i원을 만드는 경우(그전에 i - coin[1]원을 만들때 마지막에 coin[0] or coin[1]을 사용했어야 한다.).......