#include <bits/stdc++.h>

const int kMaxN = 100000;

int v[kMaxN + 1];

int main()
{
	freopen("cautbin.in", "rt", stdin);
	freopen("cautbin.out", "wt", stdout);
	unsigned int n, m;

	scanf("%u", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", v + i);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int op, x;
		unsigned int step, k;

		scanf("%d%d", &op, &x);	

		step = 1;
		while (step <= n) step <<= 1;
		step >>= 1;
		k = 0;
		
		switch (op) {
		case 0:
			while (step) {
				if (k + step < n && v[k + step] <= x) k += step;
				step >>= 1;
			}
			if (v[k] == x) printf("%u\n", k + 1);
			else printf("-1\n");
			break;
		case 1:
			while (step) {
				if (k + step < n && v[k + step] <= x) k += step;
				step >>= 1;
			}
			printf("%u\n", k + 1);
			break;
		case 2:
			while (step) {
				if (k + step < n && v[k + step] < x) k += step;
				step >>= 1;
			}
			if (k == 0 && v[0] >= x) printf("1\n");
			else printf("%u\n", k + 2);
			break;
		}
	}

	return 0;
}
