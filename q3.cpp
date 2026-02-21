#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int ba = 0, bc = 0, ca = 0, cb = 0, bca = 0, cba = 0;
        while (q--) {
            char l, r;
            cin >> l >> r;
            if (l == 'b' && r == 'a') {
                ++ba;
                if (cba < cb) ++cba;
            }
            if (l == 'b' && r == 'c') {
                ++bc;
            }
            if (l == 'c' && r == 'a') {
                ++ca;
                if (bca < bc) ++bca;
            }
            if (l == 'c' && r == 'b') {
                ++cb;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                if (ba > 0) {
                    --ba;
                    s[i] = 'a';
                } else if (bca > 0 && bc > 0 && ca > 0) {
                    --bca;
                    --bc;
                    --ca;
                    s[i] = 'a';
                }
            }
            if (s[i] == 'c') {
                if (ca > 0) {
                    --ca;
                    s[i] = 'a';
                } else if (cba > 0 && cb > 0 && ba > 0) {
                    --cba;
                    --cb;
                    --ba;
                    s[i] = 'a';
                } else if (cb > 0) {
                    --cb;
                    s[i] = 'b';
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
