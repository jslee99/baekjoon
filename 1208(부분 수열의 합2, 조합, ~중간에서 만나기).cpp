#include<iostream>
#include<map>
#include<string>

using namespace std;

long long ans = 0;
int N, S;
int seq[40];
bool is_selected[40];
map<int, int> right_m;

void calc_right(int left, int right) {
	int sum = 0;
	for (int i = left; i < right; i++) {
		if (is_selected[i]) sum += seq[i];
	}

	if (sum == S) ans++;

	map<int, int>::iterator iter;
	iter = right_m.find(sum);
	if (iter == right_m.end()) {//empty, 0
		right_m.insert(make_pair(sum, 1));
	}
	else {
		(*iter).second++;
	}
}

void comb_right(int left, int right, int last_selected, int selected_num,int max_len) {
	if (selected_num == max_len) {
		calc_right(left, right);
		return;
	}

	for (int i = last_selected + 1; i < right; i++) {
		is_selected[i] = true;
		comb_right(left, right, i, selected_num + 1, max_len);
		is_selected[i] = false;
	}
}

void _right(int left, int right) { // from left(include) to right(exclude)

	for (int len = 1; len <= right - left; len++) {
		comb_right(left, right, left - 1, 0,len);
	}

}

void calc_left(int left, int right) {
	int sum = 0;
	for (int i = left; i < right; i++) {
		if (is_selected[i]) sum += seq[i];
	}

	if (sum == S) ans++;

	map<int, int>::iterator iter;
	iter = right_m.find(S - sum);
	if (iter != right_m.end()) {
		ans += (long long)((*iter).second);
	}
}

void comb_left(int left, int right, int last_selected, int selected_num, int max_len) {
	if (selected_num == max_len) {
		calc_left(left, right);
		return;
	}

	for (int i = last_selected + 1; i < right; i++) {
		is_selected[i] = true;
		comb_left(left, right, i, selected_num + 1, max_len);
		is_selected[i] = false;
	}

}

void _left(int left, int right) {

	for (int len = 1; len <= right - left; len++) {
		comb_left(left, right, left - 1, 0, len);
	}
}
	
int main(void) {
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> seq[i];

	_right(N / 2, N);
	_left(0, N / 2);

	cout << ans << endl;
}