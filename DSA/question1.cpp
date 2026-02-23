#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int countSwaps(vector<int>& arr) {
    int n = arr.size();
    int swaps = 0;
    vector<pair<int, int> > posArr(n);  
    for (int i = 0; i < n; i++) {
        posArr[i] = make_pair(arr[i], i);  
    }
    sort(posArr.begin(), posArr.end());
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i] || posArr[i].second == i) {
            continue;
        }
        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = posArr[j].second;
            cycle_size++;
        }
        if (cycle_size > 1) {
            swaps += (cycle_size - 1);
        }
    }

    return swaps;
}
int minSwapsToBeautiful(vector<int>& arr) {
    vector<int> arrAsc = arr;
    vector<int> arrDesc = arr;
    int swapsAsc = countSwaps(arrAsc);
    reverse(arrDesc.begin(), arrDesc.end());
    int swapsDesc = countSwaps(arrDesc);
    return min(swapsAsc, swapsDesc);
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << minSwapsToBeautiful(arr) << endl;

    return 0;
}
