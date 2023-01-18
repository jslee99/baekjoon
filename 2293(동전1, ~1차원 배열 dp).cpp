#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n, k;
vector<int> coin;
int dp[10001];

int main(void) {
	cin >> n >> k;

	//int min_coin = 99999999;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		coin.push_back(a);
	}

	sort(coin.begin(), coin.end());

	if (coin[0] > k) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i <= k; i++) dp[i] = 0;//��� ������ ������� �ʴ� ���

	for (int i = 0; i < n; i++) {// 0 ~ i������ ������ ����ϴ� ���
		dp[0] = 1;
		for (int j = 1; j <= k; j++) {// j���� ����� ��� = coin i�� ������� �ʰ� j���� ����� ��� + coin i�� �ּ��� �Ѱ��� ����ϰ� j���� ����� ���
			if (j - coin[i] >= 0) {
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}
	}

	cout << dp[k] << endl;
}
