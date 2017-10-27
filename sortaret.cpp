#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 50000;

int n, m;
bool v[kMaxN + 1];
vector<int> G[kMaxN + 1];
vector<int> order;

void dfs(int s)
{
	v[s] = true;
	for (int b : G[s]) {
		if (!v[b]) dfs(b);
	}
	order.push_back(s);	
}

int main()
{
	freopen("sortaret.in", "rt", stdin);
	freopen("sortaret.out", "wt", stdout);

	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
	}

	for (int i = 1; i <= n; ++i) {
		if (!v[i]) dfs(i);
	}

	for (int i = order.size() - 1; i >= 0; --i) printf("%d ", order[i]);
	printf("\n");

	return 0;
}
