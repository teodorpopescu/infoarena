#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("nim.in", "rt", stdin);
	freopen("nim.out", "wt", stdout);
	int t, n, s;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int x;
		scanf("%d", &n);
		s = 0;
		for (int j = 0; j < n; ++j) {
			scanf("%d", &x);
			s ^= x;
		}
		if (s) printf("DA\n");
		else printf("NU\n");
	}

	return 0;
}
