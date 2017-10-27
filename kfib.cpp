#include <bits/stdc++.h>

using namespace std;

int kModulo = 666013;

int main()
{
	int k;
	long long s0, s1, s2, s3;
	long long c0, c1, c2, c3;
	long long r0, r1, r2, r3;
	freopen("kfib.in", "rt", stdin);
	freopen("kfib.out", "wt", stdout);

	scanf("%d", &k);
	c0 = 0;
	c1 = c2 = c3 = 1;
	s0 = s3 = 1;
	s1 = s2 = 0;

	while (k) {
		if (k % 2) {
			r0 = s0 * c0 + s1 * c2;
			r1 = s0 * c1 + s1 * c3;
			r2 = s2 * c0 + s3 * c2;
			r3 = s2 * c1 + s3 * c3;
			s0 = r0 % kModulo;
			s1 = r1 % kModulo;
			s2 = r2 % kModulo;
			s3 = r3 % kModulo;
		}
		r0 = c0 * c0 + c1 * c2;
		r1 = c0 * c1 + c1 * c3;
		r2 = c2 * c0 + c3 * c2;
		r3 = c2 * c1 + c3 * c3;
		c0 = r0 % kModulo;
		c1 = r1 % kModulo;
		c2 = r2 % kModulo;
		c3 = r3 % kModulo;
		k >>= 1;
	}

	printf("%lld\n", s1);

	return 0;
}
