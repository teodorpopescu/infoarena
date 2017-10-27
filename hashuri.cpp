#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("hashuri.in", "rt", stdin);
	freopen("hashuri.out", "wt", stdout);

	int n;
	unordered_multiset<int> H;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int op, x;
		scanf("%d %d", &op, &x);
		switch (op) {
		case 1:
			H.insert(x);
			break;
		case 2:
			H.erase(x);
			break;
		case 3:
			if (H.find(x) != H.end()) printf("1\n");
			else printf("0\n");
			break;
		}
	}

	return 0;
}
