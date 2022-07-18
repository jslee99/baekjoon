#include<iostream>
#include<vector>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;
int N;

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		pq.push(temp);
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			if (pq.top() < temp) {
				pq.pop();
				pq.push(temp);
			}
		}
	}
	cout << pq.top() << endl;
}



