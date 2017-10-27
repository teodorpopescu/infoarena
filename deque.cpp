#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("deque.in", "rt", stdin);
	freopen("deque.out", "wt", stdout);
	
	int n, k, x;
	long long sum = 0;
	deque<pair<int, int> > dQ;

	scanf("%d %d", &n, &k);

	for (int i = 1; i < k; ++i) {
		scanf("%d", &x);
		while (!dQ.empty() && x <= dQ.back().second) dQ.pop_back();
		dQ.push_back(make_pair(i, x));
	}	
		
	for (int i = k; i <= n; ++i) {
		scanf("%d", &x);
		while (!dQ.empty() && x <= dQ.back().second) dQ.pop_back();
		dQ.push_back(make_pair(i, x));
		sum += dQ.front().second;
		if (i - dQ.front().first + 1 >= k) dQ.pop_front();
	}

	printf("%lld\n", sum);

	return 0;
}

