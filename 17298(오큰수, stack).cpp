#include<iostream>
#include<climits>
#include<stack>

using namespace std;
int A[1000002];
int NEG[1000001];
int N;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	A[N + 1] = INT_MAX;
	stack<int> s; // top�� �� �ٷ� ������ ���� ��ū���̰� stack���� ������ �μ��� ���� �ִ� ���� ��ū���� �Ʒ� �ִ� ���̴�.

	for (int i = N; i >= 1; i--) {
		if (A[i] < A[i + 1]) {
			NEG[i] = A[i + 1];
			s.push(A[i + 1]);
		}
		else {
			while (A[i] >= s.top()) {
				s.pop();
			}
			NEG[i] = s.top();
		}
	}

	for (int i = 1; i <= N; i++) {
		if (NEG[i] == INT_MAX) {
			NEG[i] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << NEG[i] << ' ';
	}
}