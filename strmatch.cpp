#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 20000000;
const int kMaxPrint = 1000;

int n_matches, len_A;
char A[kMaxN + 2], B[kMaxN + 2];
int prefix[kMaxN + 2];
vector<int> matches;

void compute_prefix()
{
	prefix[1] = 0;
	int k = 0;
	for (int i = 2; A[i] != '\0'; ++i) {
		while (k > 0 && A[k + 1] != A[i]) k = prefix[k];
		if (A[k + 1] == A[i]) ++k;
		prefix[i] = k;
	}
}

void kmp()
{
	int k = 0;
	for (int i = 1; B[i] != '\0'; ++i) {
		while (k > 0 && A[k + 1] != B[i]) k = prefix[k];
		if (A[k + 1] == B[i]) ++k;
		if (A[k + 1] == '\0') {
			k = prefix[k];
			++n_matches;
			if (n_matches <= kMaxPrint) matches.push_back(i - len_A);
		}
	}
}

int main()
{
	freopen("strmatch.in", "rt", stdin);
	freopen("strmatch.out", "wt", stdout);

	scanf("%s", A + 1);
	scanf("%*c");
	scanf("%s", B + 1);
	len_A = strlen(A + 1);
	compute_prefix();
	kmp();

	printf("%d\n", n_matches);
	for (auto x : matches) printf("%d ", x);
	printf("\n");

	return 0;
}
