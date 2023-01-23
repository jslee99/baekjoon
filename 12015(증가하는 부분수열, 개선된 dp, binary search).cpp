#include<iostream>

using namespace std;

int A[1000000];
int dp[1000001];
int N;


int main(void){
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> A[i];

	for (int i = 1; i <= N; i++)
		dp[i] = -1;

	dp[1] = A[0];
	int min_left = 1, max_right = 1;
	for (int i = 1; i < N; i++) {
		if (dp[min_left] > A[i] || dp[max_right] < A[i]) {
			if (dp[min_left] > A[i]) {
				dp[min_left] = A[i];
			}
			if (dp[max_right] < A[i]) {
				dp[++max_right] = A[i];
			}
		}
		else {
			// dp : strictly inc
			//left <= A[i]  A[i] < right
			if (dp[max_right] == A[i]) continue;

			//binary
			int left = min_left, right = max_right;
			while (left + 1 < right) {
				int mid = (left + right) / 2;
				if (dp[mid] > A[i]) {
					right = mid;
				}
				else {
					left = mid;
				}
			}

			if (dp[left] == A[i]) continue;

			dp[right] = A[i];
		}
	}

	cout << max_right << endl;
}