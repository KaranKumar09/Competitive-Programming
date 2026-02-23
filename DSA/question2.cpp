#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the absolute ASCII distance
int calculateDistance(char a, char b) {
    return abs(a - b);
}

// Function to find the nearest good character for a given character
char findNearestGoodChar(char c, const vector<char>& goodString, char& prevGoodChar) {
    char nearestChar = goodString[0];
    int minDistance = calculateDistance(c, goodString[0]);
    
    for (char goodChar : goodString) {
        int dist = calculateDistance(c, goodChar);
        
        // If this character has a smaller distance, update the nearestChar
        if (dist < minDistance) {
            nearestChar = goodChar;
            minDistance = dist;
        }
        // If distances are the same, prefer the one closer to the previous good letter
        else if (dist == minDistance) {
            if (calculateDistance(prevGoodChar, goodChar) < calculateDistance(prevGoodChar, nearestChar)) {
                nearestChar = goodChar;
            }
        }
    }
    
    prevGoodChar = nearestChar;
    return nearestChar;
}

// Function to compute the total distance for the given name using the good string
int computeTotalDistance(const string& goodString, const string& name) {
    vector<char> goodLetters(goodString.begin(), goodString.end());
    char prevGoodChar = goodLetters[0];  // Initially, previous good character is the first character of the good string
    int totalDistance = 0;

    for (char c : name) {
        // If the current character is already in the good string, no need to change it
        if (find(goodLetters.begin(), goodLetters.end(), c) != goodLetters.end()) {
            prevGoodChar = c;
            continue;
        }
        // Find the nearest good character and calculate the distance
        char nearestGoodChar = findNearestGoodChar(c, goodLetters, prevGoodChar);
        totalDistance += calculateDistance(c, nearestGoodChar);
    }

    return totalDistance;
}

int main() {
    string goodString, name;
    
    // Input
    getline(cin, goodString);
    getline(cin, name);
    
    // Output the total distance
    cout << computeTotalDistance(goodString, name) << endl;
    
    return 0;
}
