#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<stack>
#include<set>

using namespace std;

string a;
stack<string::iterator> s;
vector<pair<string::iterator, string::iterator>> v;
vector<pair<string::iterator, string::iterator>> select_;
vector<string> ans;
set<string> r;

bool contains(string::iterator it) {
	vector<pair<string::iterator, string::iterator>>::iterator iter;
	for (iter = select_.begin(); iter != select_.end(); iter++) {
		if (iter->first == it || iter->second == it)
			return true;
	}
	return false;
}

void pr() {
	string res;
	string::iterator it;
	for (it = a.begin(); it != a.end(); it++) {
		if (*it == '(' || *it == ')') {
			if (contains(it)) {

			}
			else {
				res.push_back(*it);
			}
		}
		else {
			res.push_back(*it);
		}
	}
	ans.push_back(res);
}

void func(int idx, const int num) {
	if (select_.size() == num) {
		pr();
		return;
	}

	for (int i = idx + 1; i < v.size(); i++) {
		select_.push_back(v[i]);
		func(i, num);
		select_.erase(--select_.end());
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a;

	string::iterator it;
	for (it = a.begin(); it != a.end(); it++) {
		if (*it == '(') {
			s.push(it);
		}
		else if (*it == ')') {
			v.push_back(make_pair(s.top(), it));
			s.pop();
		}
		else {
			continue;
		}
	}

	for (int i = 1; i <= v.size(); i++) {
		func(-1, i);
	}

	sort(ans.begin(), ans.end());
	vector<string>::iterator iter;
	for (iter = ans.begin(); iter != ans.end(); iter++) {
		if (r.find(*iter) == r.end()) {
			cout << *iter << '\n';
			r.insert(*iter);
		}
	}

	return 0;
}