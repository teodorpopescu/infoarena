#include <bits/stdc++.h>

using namespace std;


const int kMaxFactors = 50;
const int kMaxRootN = 1000000;
const int kModulo = 9973;

bool sieve[kMaxRootN + 1]; //true if not prime
vector<int> primes;

int main()
{
	int t;
	freopen("ssnd.in", "rt", stdin);
	freopen("ssnd.out", "wt", stdout);

	//Build sieve
	for (int i = 3; i * i <= kMaxRootN; i += 2) {
		for (int j = i * i; j <= kMaxRootN; j += i) {
			sieve[j] = true;
		}
	}
	primes.push_back(2);
	for (int i = 3; i <= kMaxRootN; i += 2) {
		if (!sieve[i]) primes.push_back(i);
	}

	//Queries
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		long long n;
		int factors[2][kMaxFactors], k = 0;
		int count = 1, sum = 1;
		
		scanf("%lld", &n);

		for (auto it = begin(primes); n != 1 && *it * (*it) <= n; ++it) {
			if (!(n % *it)) {
				factors[0][k] = *it;
				factors[1][k] = 0;
				while (!(n % *it)) {
					++factors[1][k];
					n /= *it;
				}
				++k;
			}
		}

		if (n != 1) {
			count = 2;
			sum = (n + 1) % kModulo;
		}

		for (int i = 0; i < k; ++i) {
			long long aux = 1;
			count *= factors[1][i] + 1;
			for (int j = 0; j <= factors[1][i]; ++j) {
				aux *= factors[0][i];
			}
			sum = (sum * (aux - 1) / (factors[0][i] - 1)) % kModulo;
		}
		printf("%d %d\n", count, sum);
	}

	return 0;
}
