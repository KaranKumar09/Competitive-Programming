#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_VAL = 55;
void processTestCase() {
    int length;
    cin >> length;
    vector<int> input(length);
    for(int idx=0;idx< length;++idx){
        cin >> input[idx];
    }
    int count[MAX_VAL] = {};
    for(int val : input){
        count[val]++;
    }
    int score = 0;
    int pairs = min(count[0], count[1]);
    score += 2 * pairs;
    count[0] -= pairs;
    count[1] -= pairs;
    score += count[0];
    count[0] = 0;
    for (int i=0; i<MAX_VAL;++i) {
        if (count[i] > 0) {
            score += i * count[i];
        }
    }
    cout<<score<<endl;
}
int main() {
    int t;
    cin >>t;
    while (t--) {
        processTestCase();
    }
    return 0;
}
