#include <bits/stdc++.h>

using namespace std;

const int kMaxG = 10000;

int dp[kMaxG + 1];

int main()
{
	freopen("rucsac.in", "rt", stdin);
	freopen("rucsac.out", "wt", stdout);

	int r = 0, n, g;
	scanf("%d %d", &n, &g);

	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (int i = g; i >= a; --i) {
			if (dp[i - a] + b > dp[i]) dp[i] = dp[i - a] + b;
		}
	}
	for (int i = g; i >= 0; --i) {
		if (dp[i] > r) r = dp[i];
	}

	printf("%d\n", r);

	return 0;
}
