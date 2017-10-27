#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1024;

int n, m;
int v1[kMaxN + 1], v2[kMaxN + 1], dp[kMaxN + 1][kMaxN + 1];
int lcs[kMaxN + 1];

int main()
{
	freopen("cmlsc.in", "rt", stdin);
	freopen("cmlsc.out", "wt", stdout);

	int i, j;

	scanf("%d %d", &m, &n);

	for (i = 1; i <= m; ++i) scanf("%d", &v1[i]);
	for (i = 1; i <= n; ++i) scanf("%d", &v2[i]);
	for (i = 1; i <= m; ++i) {
		for (j = 1; j <= n; ++j) {
			if (v1[i] == v2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	i = m; j = n;
	while (i > 0 && j > 0) {
		if (v1[i] == v2[j]) {
			lcs[dp[i][j]] = v1[i];
			--i; --j;
		} else if (dp[i - 1][j] < dp[i][j - 1]) --j;
		else --i;
	}

	printf("%d\n", dp[m][n]);
	for (i = 1; i <= dp[m][n]; ++i) printf("%d ", lcs[i]);

	return 0;
}

