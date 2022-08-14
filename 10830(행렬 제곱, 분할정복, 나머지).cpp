#include<iostream>

int N;
long long B;

using namespace std;

int** matrix_mul(int** A, int** B) {
	int** ans = new int*[N];
	for (int i = 0; i < N; i++) ans[i] = new int[N];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans[i][j] = 0;
			for (int k = 0; k < N; k++) {
				ans[i][j] += A[i][k] * B[k][j];
			}
			ans[i][j] = ans[i][j] % 1000;
		}
	}
	
	return ans;
}

int** matrix_pow(int** A, long long pow) {
	if (pow == (long long)1) {
		return A;
	}

	int** half_result = matrix_pow(A, pow / (long long)2);
	int** ans;
	if (pow % (long long)2 == 1) {
		ans = matrix_mul(matrix_mul(half_result, half_result), A);
	}
	else {
		ans = matrix_mul(half_result, half_result);
	}

	return ans;
}

int main(void) {
	cin >> N >> B;

	int** A = new int*[N];
	for (int i = 0; i < N; i++) A[i] = new int[N];

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		cin >> A[i][j];
		A[i][j] = A[i][j] % 1000;
	}
	

	int** ans = matrix_pow(A, B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << ans[i][j] << " ";
		cout << endl;
	}
}
