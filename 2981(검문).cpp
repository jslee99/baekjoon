#include<iostream>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int num[100];
int N;
vector<int> sol;

//not need
int GCD(int x, int y) {// x >= y
	if (y > x) {
		int temp = x;
		x = y;
		y = temp;
	}

	if (y == 0)
		return x;

	int r = x % y;
	return GCD(y, r);
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	int temp = abs(num[0] - num[1]);
	sol.push_back(temp);
	for (int i = 2; i <= (int)sqrt((double)temp); i++) {
		if (temp % i == 0) {
			sol.push_back(i);
			if (temp / i != i)
				sol.push_back(temp / i);
		}
	}

	for (int i = 1; i <= N - 2; i++) {
		temp = abs(num[i] - num[i + 1]);
		for (int j = 0; j < sol.size(); j++) {
			if (temp % sol[j] != 0) {
				sol.erase(sol.begin() + j);
				j--;
			}
		}
	}
	sort(sol.begin(), sol.end());
	for (int i = 0; i < sol.size(); i++) {
		printf("%d ", sol[i]);
	}

}


