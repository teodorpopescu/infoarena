#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 100000;
const int kUnreached = -1;

int n;
int  D[kMaxN + 1];
vector<int> G[kMaxN + 1];

void bfs(int s)
{
	queue<int> Q;
	D[s] = 0;
	Q.push(s);
	while (!Q.empty()) {
		int a = Q.front();
		Q.pop();
		for (int b : G[a]) {
			if (D[b] != kUnreached) continue;
			D[b] = D[a] + 1;
			Q.push(b);
		}
	}
}
	

int main()
{
	freopen("darb.in", "rt", stdin);
	freopen("darb.out", "wt", stdout);
	int x;
	
	scanf("%d", &n);
	
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) D[i] = kUnreached;
	bfs(1);
	x = 1;
	for (int i = 2; i <= n; ++i) {
		if (D[x] < D[i]) x = i;
	}
	for (int i = 1; i <= n; ++i) D[i] = kUnreached;
	bfs(x);
	for (int i = 1; i <= n; ++i) {
		if (D[x] < D[i]) x = i;
	}

	printf("%d\n", D[x] + 1);
	
	return 0;
}
