#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 100000;

int n, m;
int bit[kMaxN + 1];

inline int get_zeros(int x)
{
	return (x ^ (x - 1)) & x;
}

void add(int k, int x)
{
	for (int i = k; i <= n; i += get_zeros(i)) {
		bit[i] += x;
	}
}

int query(int k)
{
	int r = 0;
	for (int i = k; i > 0; i -= get_zeros(i)) {
		r += bit[i];
	}
	return r;
}

int search(int x)
{
	int i, step = 1;
	while (step <= n) step <<= 1;
	step >>= 1;
	for (i = 0; step > 0; step >>= 1) {
		if (i + step <= n && bit[i + step] <= x) {
			i += step;
			x -= bit[i];
			if (x == 0) return i;
		}
	}
	return -1;
}	

int main()
{
	freopen("aib.in", "rt", stdin);
	freopen("aib.out", "wt", stdout);

	int op, a, b;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		add(i, a);
	}

	for (int i = 0; i < m; ++i) {
		scanf("%d", &op);
		switch (op) {
		case 0:
			scanf("%d %d", &a, &b);
			add(a, b);
			break;
		case 1:
			scanf("%d %d", &a, &b);
			printf("%d\n", query(b) - query(a - 1));
			break;
		case 2:
			scanf("%d", &a);
			printf("%d\n", search(a));
			break;
		}
	}

	return 0;
}
