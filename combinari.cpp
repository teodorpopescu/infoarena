#include <bits/stdc++.h>

using namespace std;

const int kMaxK = 18;

int n, k;
int v[kMaxK + 1];

void backtrack(int x)
{
	if (x == k + 1) {
		for (int i = 1; i <= k; ++i) printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = v[x - 1] + 1; i <= n; ++i) {
		v[x] = i;
		backtrack(x + 1);
	}
}

int main()
{
	freopen("combinari.in", "rt", stdin);
	freopen("combinari.out", "wt", stdout);

	scanf("%d%d", &n, &k);
	backtrack(1);

	return 0;
}
