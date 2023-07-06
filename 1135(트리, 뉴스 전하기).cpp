#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class people {
public:
	int p;
	vector<int> chs;
	int t;//tree[num].t�� �ǹ� : ȸ�� ��ȣ�� num�� ȸ���� root�� ������ subtree���� �޽����� ���� �����µ� �ɸ��� �ּ� �ð�
};

int n;
people tree[105];

bool cmp1(int a, int b) {
	return tree[a].t > tree[b].t;
}

void build(int num) {
	if (tree[num].chs.empty()) {
		tree[num].t = 0;
		return;
	}

	for (int i = 0; i < (int)tree[num].chs.size(); i++) {
		build(tree[num].chs[i]);	
	}

	sort(tree[num].chs.begin(), tree[num].chs.end(), cmp1);//t�� �������� �ڽ� sorting, t�� ū����� �޽����� �����ڴ�.

	for (int i = 0; i < (int)tree[num].chs.size(); i++) {
		tree[num].t = max(tree[num].t, tree[tree[num].chs[i]].t + i + 1);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		tree[i].p = p;
		tree[i].t = 0;

		if (p == -1) continue;
		tree[p].chs.push_back(i);
	}

	build(0);

	cout << tree[0].t << '\n';
}

