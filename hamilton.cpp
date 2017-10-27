#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 18;
const int kInf = numeric_limits<int>::max() / 2;

int n, m;
vector<int> G[kMaxN];
int D[kMaxN][kMaxN];
int dp[1 << kMaxN][kMaxN];

int main()
{
	freopen("hamilton.in", "rt", stdin);
	freopen("hamilton.out", "wt", stdout);

	int r = kInf;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		G[b].push_back(a);
		D[a][b] = d;
	}

	dp[1][0] = 0; //distance from vertex 0 to vertex 0 using only vertex 0 is 0
	for (int i = 2; i < (1 << n); ++i) dp[i][0] = kInf;

	for (int i = 1; i < (1 << n); i += 2) { //i = coding of path from 0 to j
		for (int j = 1; j < n; ++j) { //j = destination vertex
			dp[i][j] = kInf;
			if (i & (1 << j)) { //only if the path to j contains j
				for (auto x : G[j]) { //x = from where we can arrive to j
					if (i & (1 << x)) {
						dp[i][j] = min(dp[i][j],
						           dp[i ^ (1 << j)][x] + D[x][j]);
					}
				}
			}
		}
	}

	for (auto x : G[0]) {
		r = min(r, D[x][0] + dp[(1 << n) - 1][x]);
	}

	if (r == kInf) printf("Nu exista solutie\n");
	else printf("%d\n", r);

	return 0;
}
