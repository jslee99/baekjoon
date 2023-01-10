#include<iostream>
#include<vector>
#include<stack>

using namespace std;
vector<char> op;
stack<int> S;
int list[100000];
int N;
int num = 1;

int main(void) {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}
	
	S.push(0);
	for (int i = 0; i < N; i++) {
		while (list[i] > S.top()) {
			S.push(num++);
			op.push_back('+');
		}
		while (list[i] < S.top()) {
			S.pop();
			op.push_back('-');
		}

		if (list[i] == S.top()) {
			S.pop();
			op.push_back('-');
		}
		else {
			printf("NO\n");
			return 0;
		}
	}

	vector<char>::iterator iter;
	for (iter = op.begin(); iter != op.end(); iter++) {
		printf("%c\n", *iter);
	}
}