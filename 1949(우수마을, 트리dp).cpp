#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class node {
public:
	vector<int> ch;
	int notGoodNotGood;//���� not good�̰� �� �ڽĵ��� ��� not good�� ���
	int notGoodGood;//���� not good�̰� �� �ڽĵ��� �ϳ��� good�� ���
	int good;// ���� good�̰� �� �ڽĵ� ��ΰ� not good�� ���
	int p;
};

node t[10005];
int n;
vector<int> map[10005];

void dfs(int nd, int pa) {
	for (int i = 0; i < map[nd].size(); i++) {
		int ch = map[nd][i];
		if (ch == pa) continue;
		
		t[nd].ch.push_back(ch);
		dfs(ch, nd);
	}
}

void solveDfs(int nd) {
	if (t[nd].ch.size() == 0) {
		t[nd].good = t[nd].p;
		t[nd].notGoodNotGood = 0;
		t[nd].notGoodGood = -1;
		return;
	}

	for (int i = 0; i < t[nd].ch.size(); i++) solveDfs(t[nd].ch[i]);

	t[nd].good = t[nd].p;
	for (int i = 0; i < t[nd].ch.size(); i++) {
		int ch = t[nd].ch[i];
		t[nd].good += max(t[ch].notGoodGood, t[ch].notGoodNotGood);
	}

	t[nd].notGoodNotGood = 0;
	for (int i = 0; i < t[nd].ch.size(); i++) {
		int ch = t[nd].ch[i];
		t[nd].notGoodNotGood += max(t[ch].notGoodGood, t[ch].notGoodNotGood);
	}

	t[nd].notGoodGood = 0;
	int sumP = 0;
	bool maxGoodExist = false;
	for (int i = 0; i < t[nd].ch.size(); i++) {
		int ch = t[nd].ch[i];
		if (t[ch].good >= t[ch].notGoodGood && t[ch].good >= t[ch].notGoodNotGood) {
			maxGoodExist = true;
			sumP += t[ch].good;
		}
		else {
			sumP += max(t[ch].notGoodGood, t[ch].notGoodNotGood);
		}
	}

	if (maxGoodExist) {
		t[nd].notGoodGood += sumP;
	}
	else {
		int maxGood = -1;
		int maxCh = -1;
		for (int i = 0; i < t[nd].ch.size(); i++) {
			int ch = t[nd].ch[i];
			if (maxGood < t[ch].good) {
				maxGood = t[ch].good;
				maxCh = ch;
			}
		}
		sumP = sumP - max(t[maxCh].notGoodGood, t[maxCh].notGoodNotGood) + t[maxCh].good;
		t[nd].notGoodGood += sumP;
	}

	return;
	for (int i = 0; i < t[nd].ch.size(); i++) {
		int ch = t[nd].ch[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> t[i].p;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	dfs(1, 0);

	solveDfs(1);

	cout << max(t[1].good, t[1].notGoodGood) << '\n';

	return 0;
}