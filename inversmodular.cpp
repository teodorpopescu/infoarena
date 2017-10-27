#include <bits/stdc++.h>

void extended_gcd(int a, int b, int *d, int *x, int *y)
{
	if (b) {
		int x0, y0;
		extended_gcd(b, a % b, d, &x0, &y0);
		*x = y0;
		*y = x0 - a / b * y0;
	} else {
		*x = 1;
		*y = 0;
		*d = a;
	}
}

int main()
{
	int a, n;
	freopen("inversmodular.in", "rt", stdin);
	freopen("inversmodular.out", "wt", stdout);

	scanf("%d%d", &a, &n);

	int x, y, d;
	extended_gcd(a, n, &d, &x, &y);
	while (x < 0) x += n;
	printf("%d\n", x);

	return 0;
}	
