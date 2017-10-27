#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 100000;

int n, m;
list<int> G[kMaxN + 1];
vector<int> circuit;

void build_circuit(int s)
{
	stack<int> S;
	S.push(s);
	while (!S.empty()) {
		int a = S.top();
		if (G[a].empty()) {
			circuit.push_back(a);
			S.pop();
		} else {
			int b = G[a].front();
			G[a].pop_front();
			G[b].erase(find(G[b].begin(), G[b].end(), a));
			S.push(b);
		}
	}
}

int main()
{
	freopen("ciclueuler.in", "rt", stdin);
	freopen("ciclueuler.out", "wt", stdout);

	bool is_eulerian = true;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		if (G[i].size() && G[i].size() % 2 == 1) {
			is_eulerian = false;
			break;
		}
	}

	if (is_eulerian) {
		build_circuit(1);
		for  (auto x : circuit) printf("%d ", x);
		printf("\n");
	} else {
		printf("-1\n");
	}

	return 0;
}
