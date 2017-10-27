#include <bits/stdc++.h>

void extended_gcd(int a, int b, int *d, int *x, int *y)
{
	if (b) {
		int x0, y0;
		extended_gcd(b, a % b, d, &x0, &y0);
		*x = y0;
		*y = x0 - a / b * y0;
	} else {
		*d = a;
		*x = 1;
		*y = 0;
	}
}

int main()
{
	int t;
	freopen("euclid3.in", "rt", stdin);
	freopen("euclid3.out", "wt", stdout);

	scanf("%d", &t);
	
	for (int i = 0; i < t; ++i) {
		int a, b, d, x, y, c;
		scanf("%d%d%d", &a, &b, &c);
		extended_gcd(a, b, &d, &x, &y);
		if (c % d) x = y = 0;
		else x *= c / d, y *= c / d;
		printf("%d %d\n", x, y);
	}

	return 0;
}
