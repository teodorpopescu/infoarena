#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("submultimi.in", "rt", stdin);
	freopen("submultimi.out", "wt", stdout);

	int n, l;
	scanf("%d", &n);
	l = (1 << n) - 1;
	for (int i = 1; i <= l; ++i) {
		int k = i;
		for (int j = 1; j <= n; ++j) {
			if (k % 2) printf("%d ", j);
			k >>= 1;
		}
		printf("\n");
	}

	return 0;
}
