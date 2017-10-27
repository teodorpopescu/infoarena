#include <bits/stdc++.h>

int gcd(int a, int b)
{
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int t;
	freopen("euclid2.in", "rt", stdin);
	freopen("euclid2.out", "wt", stdout);

	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}

	return 0;
}
