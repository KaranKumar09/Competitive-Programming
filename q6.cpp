
#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec std::vector
#define pii std::pair<int, int>
#define se second
#define fi first
#define pb push_back
#define yes std::cout << "Yes\n";
#define no std::cout << "No\n";
namespace TwoSAT {
    const int MAX_VARS = 2 * 300 * 10;
    vec<int> adj[2 * MAX_VARS + 2];
    vec<int> rev_adj[2 * MAX_VARS + 2];
    bool visited[2 * MAX_VARS + 2];
    int component[2 * MAX_VARS + 2];
    vec<int> order;
    int num_total_vars;
    void init(int n_vars) {
        num_total_vars = n_vars;
        order.clear();
        for (int i = 0; i < 2 * num_total_vars; ++i) {
            adj[i].clear();
            rev_adj[i].clear();
            visited[i] = false;
            component[i] = -1;
        }
    }
    void dfs1(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs1(v);
            }
        }
        order.pb(u);
    }
    void dfs2(int u, int c) {
        component[u] = c;
        for (int v : rev_adj[u]) {
            if (component[v] == -1) {
                dfs2(v, c);
            }
        }
    }
    void add_clause(int u_lit, int v_lit) {
        adj[u_lit ^ 1].pb(v_lit);
        adj[v_lit ^ 1].pb(u_lit);
        rev_adj[v_lit].pb(u_lit ^ 1);
        rev_adj[u_lit].pb(v_lit ^ 1);
    }
    bool solve() {
        for (int i = 0; i < 2 * num_total_vars; ++i) {
            if (!visited[i]) {
                dfs1(i);
            }
        }
        std::reverse(all(order));

        int c = 0;
        for (int u : order) {
            if (component[u] == -1) {
                dfs2(u, c++);
            }
        }
        for (int i = 0; i < num_total_vars; ++i) {
            if (component[2 * i] == component[2 * i + 1]) {
                return false;
            }
        }
        return true;
    }
}
void solve_test_case() {
    int n, k;
    std::cin >> n >> k;
    vec<vec<vec<int>>> graphs(k, vec<vec<int>>(n, vec<int>(n, 0)));
    for (int i = 0; i < k; ++i) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j) {
            int u, v;
            std::cin >> u >> v;
            --u; --v;
            graphs[i][u][v] = 1;
            graphs[i][v][u] = 1;
        }
    }
    auto get_var_index = [&](int graph_idx, int vertex_idx, int type) {
        return (graph_idx * n + vertex_idx) * 2 + type;
    };
    int num_base_vars = k * n * 2;
    TwoSAT::init(num_base_vars);
    for (int v = 0; v < n; ++v) {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                int var_i_idx = get_var_index(i, v, 1);
                int var_j_idx = get_var_index(j, v, 0);
                TwoSAT::add_clause(2 * var_i_idx + 1, 2 * var_j_idx + 1);
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                bool indistinguishable = true;
                for (int w = 0; w < n; ++w) {
                    if (w == u || w == v) continue;
                    if (graphs[i][u][w] != graphs[i][v][w]) {
                        indistinguishable = false;
                        break;
                    }
                }
                if (indistinguishable) {
                    if (graphs[i][u][v] == 1) { 
                        int u_i_idx = get_var_index(i, u, 1);
                        int v_i_idx = get_var_index(i, v, 1);
                        TwoSAT::add_clause(2 * u_i_idx, 2 * v_i_idx);
                    } else { 
                        int u_c_idx = get_var_index(i, u, 0);
                        int v_c_idx = get_var_index(i, v, 0);
                        TwoSAT::add_clause(2 * u_c_idx, 2 * v_c_idx);
                    }
                }
            }
        }
    }
    if (TwoSAT::solve()) {
        yes
    } else {
        no
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve_test_case();
    }
    return 0;
}