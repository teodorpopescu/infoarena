#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("radixsort.in", "rt", stdin);
	freopen("radixsort.out", "wt", stdout);

	deque<int> buckets[2][256];
	vector<int> v;
	int n, a, b, c, aux;
	scanf("%d %d %d %d", &n, &a, &b, &c);

	aux = 0;
	while (n--) {
		aux = (1LL * a * aux + b) % c;
		buckets[0][aux & 0xff].push_back(aux);
	}

	for (int i = 0; i < 256; ++i) {
		while (!buckets[0][i].empty()) {
			int x = buckets[0][i].front();
			buckets[1][(x & 0xff00) >> 8].push_back(x);
			buckets[0][i].pop_front();
		}
	}
	for (int i = 0; i < 256; ++i) {
		while (!buckets[1][i].empty()) {
			int x = buckets[1][i].front();
			buckets[0][(x & 0xff0000) >> 16].push_back(x);
			buckets[1][i].pop_front();
		}
	}
	for (int i = 0; i < 256; ++i) {
		while (!buckets[0][i].empty()) {
			int x = buckets[0][i].front();
			buckets[1][(x & 0xff000000) >> 24].push_back(x);
			buckets[0][i].pop_front();
		}
	}

	for (int i = 0; i < 256; ++i) {
		while (!buckets[1][i].empty()) {
			v.push_back(buckets[1][i].front());
			buckets[1][i].pop_front();
		}
	}

	for (int i = 0; i < v.size(); i += 10) printf("%d ", v[i]);
	printf("\n");

	return 0;
}
