#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N;  // Number of orders
    
    deque<pair<int, int>> orders;  // To store {priority, index} for each order
    vector<int> priorities(N);  // To store the priorities
    for (int i = 0; i < N; i++) {
        cin >> priorities[i];
        orders.push_back({priorities[i], i});  // Store the order and its index
    }
    
    cin >> K;  // Position of Raj's friend's order (1-indexed)
    K--;  // Convert to 0-indexed

    int servedCount = 0;
    
    while (!orders.empty()) {
        // Find the maximum priority in the queue
        int maxPriority = -1;
        for (const auto& order : orders) {
            maxPriority = max(maxPriority, order.first);
        }
        
        // Serve the highest priority order
        if (orders.front().first == maxPriority) {
            servedCount++;  // One order is served
            if (orders.front().second == K) {
                // If the served order is Raj's friend's order, print the result
                cout << servedCount << endl;
                return 0;
            }
            // Remove the served order
            orders.pop_front();
        } else {
            // Rotate the queue: move the current order to the back of the queue
            auto frontOrder = orders.front();
            orders.pop_front();
            orders.push_back(frontOrder);
        }
    }

    return 0;
}
