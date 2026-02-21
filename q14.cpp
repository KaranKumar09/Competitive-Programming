#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long c;
    cin >> n >> c;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<long long, long long> dp;
    function<long long(int, vector<long long>&)> rec = [&](int mask, vector<long long>& weights) -> long long {
        if (mask == (1 << n) - 1) {
            return 0;
        }
        long long key = mask;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                key = key * 1000000001 + weights[i];
            }
        }
        if (dp.count(key)) {
            return dp[key];
        }
        
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) { 
                vector<long long> new_weights = weights;
                for (int j = 0; j < n; j++) {
                    if (!(mask & (1 << j))) {
                        new_weights[j] *= 2;
                    }
                }
                long long cost = (weights[i] > c) ? 1 : 0;
                ans = min(ans, cost + rec(mask | (1 << i), new_weights));
            }
        }

        return dp[key] = ans;
    };
    vector<long long> weights = a;
    cout << rec(0, weights) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}