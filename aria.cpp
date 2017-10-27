#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	long double x0, y0, x1, y1, x2, y2, s = 0;
	freopen("aria.in", "rt", stdin);
	freopen("aria.out", "wt", stdout);

	scanf("%d", &n);
	
	scanf("%Lf%Lf", &x0, &y0);
	x2 = x0; y2 = y0;
	for (int i = 1; i < n; ++i) {
		x1 = x2; y1 = y2;
		scanf("%Lf%Lf", &x2, &y2);
		s += x2 * y1 - x1 * y2;
	}
	s += x0 * y2 - x2 * y0;
	if (s < 0) s = -s;
	s /= 2;

	printf("%.6Lf\n", s);

	return 0;
}
