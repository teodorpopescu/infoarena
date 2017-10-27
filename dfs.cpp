#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 100000;

int n, m;
bool v[kMaxN + 1];
vector<int> G[kMaxN + 1];

void dfs(int s)
{
	stack<int> S;
	S.push(s);
	v[s] = true;
	while (!S.empty()) {
		int a = S.top();
		S.pop();
		for (int b : G[a]) {
			if (!v[b]) {
				v[b] = true;
				S.push(b);
			}
		}
	}
}

int main()
{
	freopen("dfs.in", "rt", stdin);
	freopen("dfs.out", "wt", stdout);

	int r = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		if (!v[i]) {
			++r;
			dfs(i);
		}
	}

	printf("%d\n", r);

	return 0;
}
