#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> mp;
    mp[1] = "Karan";
    mp[2] = "Keshav";
    mp[3] = "Vishal";

    // Using an iterator to iterate over the map in C++98
    for (map<int, string>::iterator it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

