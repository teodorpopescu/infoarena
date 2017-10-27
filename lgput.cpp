#include <bits/stdc++.h>

using namespace std;

const int kModulo = 1999999973;

long long power(long long n, long long k)
{
	int r = 1;
	while (k) {
		if (k % 2) r = (r * n) % kModulo;
		n = (n * n) % kModulo;
		k >>= 1;
	}
	return r;
}

int main()
{
	freopen("lgput.in", "rt", stdin);
	freopen("lgput.out", "wt", stdout);
	long long n, p;
	scanf("%lld%lld", &n, &p);
	printf("%lld\n", power(n, p));
	return 0;
}
