#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 100000;
const int kMaxLogN = 17;

int n, m;
int v[kMaxLogN + 1][kMaxN + 1];

void rmq_build()
{
	for (int i = 1; (1 << i) <= n; ++i) {
		for (int j = 1; j <= n - (1 << i) + 1; ++j) {
			v[i][j] = min(v[i - 1][j], v[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int rmq_query(int a, int b)
{
	int i, k = 1;
	for (i = 0; k <= b - a + 1; ++i) k <<= 1;
	k >>= 1; --i;
	return min(v[i][a], v[i][b - k + 1]);
}
int main()
{
	freopen("rmq.in", "rt", stdin);
	freopen("rmq.out", "wt", stdout);

	int a, b;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &v[0][i]);
	}

	rmq_build();
	
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		printf("%d\n", rmq_query(a, b));
	}

	return 0;
}
