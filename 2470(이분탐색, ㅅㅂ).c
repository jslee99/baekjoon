#include<stdio.h>
#include<stdlib.h>

const int INF = 2000000001;
int liquid[100000];
int ans[2];
int min_abs;
int N;

int cmp(const int* a, const int* b) {
	return *a - *b;
}

int binary_search(int p, int q, int key) {
	if (p < q) {
		int r = (p + q) / 2;
		if (liquid[r] == key) {
			return r;
		}
		if (key < liquid[r]) {
			return binary_search(p, r - 1, key);
		}
		else {
			return binary_search(r + 1, q, key);
		}
	}
	else {//base case
		return p;
	}
}

int main(void) {
	min_abs = INF;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &liquid[i]);
	}
	qsort(liquid, N, sizeof(int), cmp);

	/*
	if (liquid[N - 1] < 0) {
		printf("%d %d", liquid[N - 2], liquid[N - 1]);
		exit(0);
	}
	else if (liquid[0] > 0) {
		printf("%d %d", liquid[0], liquid[1]);
		exit(0);
	}

	for (int i = 0; i < N; i++) {
		int opp_idx = binary_search(0, N - 1, -liquid[i]);
		if (liquid[opp_idx] == -liquid[i]) {
			ans[0] = liquid[i], ans[1] = liquid[opp_idx];
			break;
		}
		else {
			if (-liquid[i] < liquid[opp_idx]) {//opp_idx - 1, opp_idx
				if (min_abs > abs(liquid[opp_idx] + liquid[i])) 
					ans[0] = liquid[opp_idx], ans[1] = liquid[i], min_abs = abs(liquid[opp_idx] + liquid[i]);
				if(opp_idx - 1 >= 0 && min_abs > abs(liquid[opp_idx - 1] + liquid[i]))
					ans[0] = liquid[opp_idx - 1], ans[1] = liquid[i], min_abs = abs(liquid[opp_idx - 1] + liquid[i]);
			}
			else {
				if (min_abs > abs(liquid[opp_idx] + liquid[i]))
					ans[0] = liquid[opp_idx], ans[1] = liquid[i], min_abs = abs(liquid[opp_idx] + liquid[i]);
				if (opp_idx + 1 < N && min_abs > abs(liquid[opp_idx + 1] + liquid[i]))
					ans[0] = liquid[opp_idx + 1], ans[1] = liquid[i], min_abs = abs(liquid[opp_idx + 1] + liquid[i]);

			}
		}
	}
	*/
	for (int i = 0; i < N; i++) {
		int opp_idx = binary_search(0, N - 1, -liquid[i]);
		if (opp_idx == i) {
			if (opp_idx + 1 < N && min_abs > abs(liquid[i] + liquid[opp_idx + 1]))
				min_abs = abs(liquid[i] + liquid[opp_idx + 1]), ans[0] = liquid[i], ans[1] = liquid[opp_idx + 1];
			if (opp_idx - 1 >= 0 && min_abs > abs(liquid[i] + liquid[opp_idx - 1]))
				min_abs = abs(liquid[i] + liquid[opp_idx - 1]), ans[0] = liquid[i], ans[1] = liquid[opp_idx - 1];
			continue;
		}
		//opp_idx != i
		if (liquid[opp_idx] == -liquid[i]) {
			ans[0] = liquid[i], ans[1] = liquid[opp_idx];
			break;
		}
		//-liquid[i] != liquid[opp_idx]
		if (opp_idx == N - 1) {
			if (min_abs > abs(liquid[i] + liquid[opp_idx]))
				min_abs = abs(liquid[i] + liquid[opp_idx]), ans[0] = liquid[i], ans[1] = liquid[opp_idx];
			if (liquid[opp_idx] > -liquid[i] && opp_idx - 1 != i && min_abs > abs(liquid[i] + liquid[opp_idx - 1]))
				min_abs = abs(liquid[i] + liquid[opp_idx - 1]), ans[0] = liquid[i], ans[1] = liquid[opp_idx - 1];
			continue;
		}

		if (opp_idx == 0) {
			if (min_abs > abs(liquid[i] + liquid[opp_idx]))
				min_abs = abs(liquid[i] + liquid[opp_idx]), ans[0] = liquid[i], ans[1] = liquid[opp_idx];
			if (liquid[opp_idx] < -liquid[i] && opp_idx + 1 != i && min_abs > abs(liquid[i] + liquid[opp_idx + 1]))
				min_abs = abs(liquid[i] + liquid[opp_idx + 1]), ans[0] = liquid[i], ans[1] = liquid[opp_idx + 1];
			continue;
		}

		if (-liquid[i] < liquid[opp_idx]) {
			if (min_abs > abs(liquid[i] + liquid[opp_idx]))
				min_abs = abs(liquid[i] + liquid[opp_idx]), ans[0] = liquid[i], ans[1] = liquid[opp_idx];
			if (opp_idx - 1 != i && min_abs > abs(liquid[i] + liquid[opp_idx - 1]))
				min_abs = abs(liquid[i] + liquid[opp_idx - 1]), ans[0] = liquid[i], ans[1] = liquid[opp_idx - 1];
			continue;
		}

		if (-liquid[i] > liquid[opp_idx]) {
			if (min_abs > abs(liquid[i] + liquid[opp_idx]))
				min_abs = abs(liquid[i] + liquid[opp_idx]), ans[0] = liquid[i], ans[1] = liquid[opp_idx];
			if (opp_idx + 1 != i && min_abs > abs(liquid[i] + liquid[opp_idx + 1]))
				min_abs = abs(liquid[i] + liquid[opp_idx + 1]), ans[0] = liquid[i], ans[1] = liquid[opp_idx + 1];
			continue;
		}


	}
	



	if (ans[0] > ans[1]) {
		int temp = ans[0];
		ans[0] = ans[1];
		ans[1] = temp;
	}
	printf("%d %d", ans[0], ans[1]);
	return 0;
}