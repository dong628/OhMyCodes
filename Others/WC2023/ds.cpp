#include "ds.h"
#include <vector>

void solve(int n, int lim1, int lim2) {
	std::vector<int> par(n - 2), val(n - 2);
	for (int i = 0; i < n - 1; i++) par[i] = i + 1;
	for (int i = 0; i < n - 1; i++) val[i] = i + 1;
	answer(par, val);
}