#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1000000;

int v[kMaxN];

int main()
{
	freopen("elmaj.in", "rt", stdin);
	freopen("elmaj.out", "wt", stdout);
	int n, e, k;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}

	e = v[0];
	k = 1;
	for (int i = 1; i < n; ++i) {
		if (v[i] == e) ++k;
		else if (--k == 0) {
			e = v[i];
			k = 1;
		}
	}
	k = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i] == e) ++k;
	}
	if (k >= n / 2 + 1) printf("%d %d\n", e, k);
	else printf("-1\n");

	return 0;
}
