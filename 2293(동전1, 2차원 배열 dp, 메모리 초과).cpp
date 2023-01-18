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


//������ ����ϴ� ������ �׻� increasing order �� 1�� �޿� ����ϰ� 2�� �޿� ����ϰ� 5�� �޿� ����ϰԵȴ�.
// dp[i][j]�� i���� ����µ� �Ǹ������� coin[j]�� ����ϴ� ��츦 ���Ѵ�.
//���� dp[i][j]�� �����Ҷ� dp[i][j] = dp[i - coin[0]][0] + (dp[i - coin[1]][1] + dp[i - coin[1]][1]) + .......
// ��, �Ǹ������� coin[0]�� ����Ͽ� i���� ����� ���(������ i - coin[0]���� ���鶧 �������� coin[0]�� ����߾�� �Ѵ�.) + �������� coin[1]�� ����Ͽ� i���� ����� ���(������ i - coin[1]���� ���鶧 �������� coin[0] or coin[1]�� ����߾�� �Ѵ�.).......