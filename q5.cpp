#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<vector<bool>> can(3, vector<bool>(3, false));
        for (int i = 0; i < 3; ++i) can[i][i] = true;
        for (int i = 0; i < q; ++i) {
            char l, r;
            cin >> l >> r;
            int from = l - 'a';
            int to = r - 'a';
            can[from][to] = true;
        }
        for (int k = 0; k < 3; ++k)
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    if (can[i][k] && can[k][j])
                        can[i][j] = true;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (can[c][0]) s[i] = 'a';
            else if (can[c][1]) s[i] = 'b';
            else if (can[c][2]) s[i] = 'c';
        }
        cout << s << '\n';
    }
    return 0;
}
