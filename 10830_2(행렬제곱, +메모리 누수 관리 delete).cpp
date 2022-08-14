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
		int** ret = new int* [N];
		for (int i = 0; i < N; i++)ret[i] = new int[N];
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)ret[i][j] = A[i][j];
		return ret;
	}

	int** half_result = matrix_pow(A, pow / (long long)2);
	int** ans;
	if (pow % (long long)2 == 1) {
		ans = matrix_mul(matrix_mul(half_result, half_result), A);
	}
	else {
		ans = matrix_mul(half_result, half_result);
	}

	//for (int i = 0; i < N; i++) delete[] half_result[i];
	//delete[] half_result;

	return ans;
}

int main(void) {
	cin >> N >> B;

	int ** matrix = new int*[N];
	for (int i = 0; i < N; i++) matrix[i] = new int[N];

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		cin >> matrix[i][j];
		matrix[i][j] = matrix[i][j] % 1000;
	}
	

	int** ans = matrix_pow(matrix, B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << ans[i][j] << " ";
		cout << endl;
	}
}
