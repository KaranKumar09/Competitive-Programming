#include <iostream>
#include <vector>
#include <string>
using namespace std;
  
int main() {
    string s;
    cin >> s;
    string result = "";
    for (int i = 0; i < s.length(); ) {
        if (s[i] == '.') {
            result += '0';
            i++;
        }
        else if (s[i] == '-' && s[i+1] == '.') {
            result += '1';
            i += 2;
        }
        else if (s[i] == '-' && s[i+1] == '-') {
            result += '2';
            i += 2;
        }
    }
    cout << result << endl;
    return 0;
}
