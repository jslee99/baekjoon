#include<iostream>

using namespace std;

int A[1000];
int dp_inc[1000]; // A[i]를 끝으로 가지는 가장 긴 증가 부분수열
int dp_dec[1000];
pair<int, bool> max_inc[1000]; // i의 왼쪽(include i)에서 가장긴 증가 부분수열, i가 포함이 되는지?
pair<int, bool> max_dec[1000];
int N;
int ans = -1;

int main(void){
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		dp_inc[i] = 0;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				dp_inc[i] = max(dp_inc[i], dp_inc[j]);
			}
		}
		dp_inc[i]++;
	}


	for (int i = N - 1; i >= 0; i--) {
		dp_dec[i] = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (A[j] < A[i]) {
				dp_dec[i] = max(dp_dec[i], dp_dec[j]);
			}
		}
		dp_dec[i]++;
	}

	for (int i = 0; i < N; i++) {
		int before = dp_inc[i];
		int after = 0;
		for (int j = i + 1; j < N; j++) {
			if (A[j] < A[i]) {
				after = max(after, dp_dec[j]);
			}
		}
		ans = max(ans, before + after);
	}

	cout << ans << endl;
}