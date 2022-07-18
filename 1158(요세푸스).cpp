#include<iostream>
using namespace std;

int main(void) {
	int n;
	int k;
	scanf("%d %d", &n, &k);
	bool* people = new bool[n];
	int* permutation = new int[n];
	for (int i = 0; i < n; i++) {
		people[i] = true;
	}
	int index = -1;
	int cnt = 0;
	while (cnt < n) {
		int i = 0;
		while (i < k) {
			index = (index + 1) % n;
			if (people[index] == true) {
				i++;
			}
			else {
				continue;
			}
		}
		people[index] = false;
		permutation[cnt] = index + 1;
		cnt++;
	}
	printf("<");
	for (int i = 0; i < n - 1; i++) {
		printf("%d, ",permutation[i]);
	}
	printf("%d>", permutation[n - 1]);

	delete[] people;
	delete[] permutation;
}