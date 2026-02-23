#include <iostream>
#include <string>

using namespace std;

// Function to check if the input string is valid (contains only 'M' and 'L')
bool isValidInput(const string& row) {
    for (char c : row) {
        if (c != 'M' && c != 'L') {
            return false;
        }
    }
    return true;
}

// Function to count valid triplets
int countPossibilities(const string& row) {
    int n = row.length();
    
    // Possibility count is based on identifying valid subsequences of 3 trees
    if (n < 3) return 0; // No possible triplets in less than 3 trees

    int possibilities = 0;

    // Traverse the string and look for triplets
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (row[i] != row[j]) {  // First two trees must be different
                for (int k = j + 1; k < n; k++) {
                    if (row[j] != row[k]) {  // Second and third trees must be different
                        possibilities++;
                    }
                }
            }
        }
    }

    return possibilities;
}

int main() {
    string ashokRow, anandRow;

    // Input
    getline(cin, ashokRow);
    getline(cin, anandRow);

    // Check for invalid input
    if (!isValidInput(ashokRow) || !isValidInput(anandRow)) {
        cout << "Invalid input" << endl;
        return 0;
    }

    // Calculate possibilities for both Ashok and Anand
    int ashokPossibilities = countPossibilities(ashokRow);
    int anandPossibilities = countPossibilities(anandRow);

    // Determine the winner or if it's a draw
    if (ashokPossibilities > anandPossibilities) {
        cout << "Ashok" << endl;
    } else if (anandPossibilities > ashokPossibilities) {
        cout << "Anand" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}