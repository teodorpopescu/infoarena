#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 200000;

int n, m;
int v[kMaxN + 1];
vector<pair<int, int> > apm;
vector<pair<int, pair<int, int> > > edges;

int find_root(int a)
{
	while (v[a]) {
		a = v[a];
	}
	return a;
}

void mark_set(int a, int mark)
{
	int x;
	while (v[a]) {
		x = a;
		a = v[a];
		v[x] = mark;
	}
}

int main()
{
	freopen("apm.in", "rt", stdin);
	freopen("apm.out", "wt", stdout);

	int r1, r2;
	int sum = 0;


	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		edges.push_back(make_pair(d, make_pair(a, b)));
	}

	sort(edges.begin(), edges.end());

	for (auto it = edges.begin(); it != edges.end(); ++it) {
		r1 = find_root(it->second.first);
		r2 = find_root(it->second.second);
		mark_set(it->second.first, r1);
		mark_set(it->second.second, r2);
		if (r1 != r2) {
			v[r1] = r2;
			sum += it->first;
			apm.push_back(it->second);
		}
	}

	printf("%d\n", sum);
	printf("%lu\n", apm.size());
	for (auto it = apm.begin(); it != apm.end(); ++it) {
		printf("%d %d\n", it->first, it->second);
	}

	return 0;
}
