#include <iostream>
#include <vector>
#include <cassert>
#include <tuple>
#include <cstring>

const unsigned maxn = 1e5 + 10;

const int inf = 0x3f3f3f3f;
const int ninf = 0xc0c0c0c0;

int dp_max[maxn], dp_min[maxn];

std::vector<std::tuple<unsigned, int>> G[maxn];

std::tuple<int, int> dp(unsigned u) {
    if (dp_max[u] != ninf) {
        assert(dp_min[u] != inf);
        return {dp_max[u], dp_min[u]};
    }
    if(G[u].size() == 0) {
        dp_max[u] = dp_min[u] = 0;
        return {0, 0};
    };
    for(auto [v, w] : G[u]) {
        auto [maxv, minv] = dp(v);
        dp_max[u] = std::max(dp_max[u], maxv + w);
        dp_min[u] = std::min(dp_min[u], minv + w);
    }
    return {dp_max[u], dp_min[u]};
}

int main() {
freopen("data.in", "r", stdin);

    unsigned n, m;
    std::cin >> n >> m;

    memset(dp_max, 0xc0, sizeof(decltype(dp_max[0])) * (n + 1));
    memset(dp_min, 0x3f, sizeof(decltype(dp_min[0])) * (n + 1));

    for(unsigned i = 0;i < m;i++) {
        unsigned u, v;
        int w;
        std::cin >> u >> v;
        std::cin >> w;

        G[u].push_back({v, w});
    }

    auto [maxv, minv] = dp(1);
    std::cout << maxv << " " << minv << '\n';
}
