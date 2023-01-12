#include<iostream>
#include<string>

using namespace std;

int N, K;
int res;
bool cant = true;

bool visited[1000001][11];

void calc(string str, int str_size) {
	if (cant) {
		cant = false;
		res = stoi(str);
	}
	else {
		for (int i = 0; i < str_size; i++) {
			if (res < stoi(str)) {
				res = stoi(str);
				break;
			}
		}
	}
	
}

void dfs(string str, int str_size,int depth) {
	if (str[0] == '0') return;

	if (visited[stoi(str)][depth]) return;
	visited[stoi(str)][depth] = true;

	if (depth == K) {
		calc(str, str_size);
		return;
	}

	for (int i = 0; i < str_size - 1; i++) {
		for (int j = i + 1; j < str_size; j++) {
			swap(str[i], str[j]);
			dfs(str, str_size, depth + 1);
			swap(str[i], str[j]);
		}
	}
}

int main(void) {
	cin >> N >> K;
	string str = to_string(N);
	int str_size = (int)str.size();
	res = stoi(str);

	if (str_size == 1) {
		cout << -1 << endl;
		return 0;
	}
	else{
		dfs(str, str_size, 0);

		if (cant) {
			cout << -1 << endl;
		}
		else {
			cout << res << endl;
		}
	}

	return 0;
}