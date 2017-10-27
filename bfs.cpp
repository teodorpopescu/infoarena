#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 100000;
const int kUnreached = -1;

int n, m, s;
int D[kMaxN + 1];
vector<int> G[kMaxN + 1];

int main()
{
	freopen("bfs.in", "rt", stdin);
	freopen("bfs.out", "wt", stdout);
	queue<int> Q;

	scanf("%d %d %d", &n, &m, &s);

	for (int i = 1; i <= n; ++i) D[i] = kUnreached;
	
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
	}

	Q.push(s);
	D[s] = 0;

	while (!Q.empty()) {
		int a = Q.front();
		Q.pop();
		for (int b : G[a]) {
			if (D[b] == kUnreached) {
				D[b] = D[a] + 1;
				Q.push(b);
			}
		}
	}

	for (int i = 1; i <= n; ++i) printf("%d ", D[i]);
	printf("\n");

	return 0;
}
