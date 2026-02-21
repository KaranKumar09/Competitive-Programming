#include <iostream>
using namespace std;
int sumOfDigits(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if (y == 1 && x % 9 == 0) {
            cout << "Yes" << endl;
            continue;
        }
        bool found = false;
        for (int n = 0; n <= 1000000; n++) {
            if (sumOfDigits(n) == x && sumOfDigits(n + 1) == y) {
                found = true;
                break;
            }
        }
        if (found) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
