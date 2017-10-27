#include <bits/stdc++.h>

using namespace std;

vector<pair<double, double> > 
graham_scan(vector<pair<double, double> >::iterator a,
            vector<pair<double, double> >::iterator b)
{
	pair<double, double> pivot = *min_element(a, b);	
	sort(a, b, [&pivot](const pair<double, double> &x,
	                    const pair<double, double> &y) {
		double dx1 = x.first - pivot.first;
		double dx2 = x.second - pivot.second;
		double dy1 = y.first - pivot.first;
		double dy2 = y.second - pivot.second;
		if (dx1 == 0 && dx2 == 0) return true;
		if (dy1 == 0 && dy2 == 0) return false;
		return dx2 * dy1 < dy2 * dx1;
	});
	vector<pair<double, double> > v; 
	for (auto it = a; it != b; ++it) {
		while (v.size() >= 2 && (*it).first * v[v.size() - 1].second +
			v[v.size() - 1].first * v[v.size() - 2].second +
			v[v.size() - 2].first * (*it).second > 
			v[v.size() - 2].first * v[v.size() - 1].second +
			v[v.size() - 1].first * (*it).second + 
			(*it).first * v[v.size() -2].second) {
			v.pop_back();
		}
		v.push_back(*it);
	}
	return v;
}

int main()
{
	freopen("infasuratoare.in", "rt", stdin);
	freopen("infasuratoare.out", "wt", stdout);
	int n;
	vector<pair<double, double> > v;

	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		double a, b;
		scanf("%lf%lf", &a, &b);
		v.push_back(make_pair(a, b));
	}
	auto convex_hull = graham_scan(v.begin(), v.end());

	printf("%lu\n", convex_hull.size());
	for(auto it = convex_hull.begin(); it != convex_hull.end(); ++it) {
		printf("%.6lf %.6lf\n", (*it).first, (*it).second);
	}

	return 0;
}
