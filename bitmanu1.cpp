// // Online C++ compiler to run C++ program online
// #include <iostream>
// #include<algorithm>
// #include<string>
// using namespace std;
// string strToBinary(int n){
//     string result = " ";
//     while(n > 0){
//         if(n % 2==1){
//             result += '1';
//         }
//         else{
//             result += '0';
//         }
//         n = n/2;
//     }
//     reverse(result.begin(),result.end());
//     return result;
// }

// int main() {
//     // Write C++ code here
//     int n;
//     cout<<"Enter the number to convert in binary: ";
//     cin>>n;
//     string ans = strToBinary(n);
//     cout<<"Binary Representation: "<<ans<<endl;

//     return 0;
// }

// Online C++ compiler to run C++ program online
#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
int binaryToInt(string n){
    int ans = 0;
    int pow = 1;
    for(int i = n.length()-1; i>=0; i--){
        if(n[i] == '1'){
            ans += pow;
        }
        pow *= 2;
    }
    return ans;
}

int main() {
    // Write C++ code here
    string n;
    cout<<"Enter the binary to convert in integer: ";
    cin>>n;
    int ans = binaryToInt(n);
    cout<<"Integer Representation: "<<ans<<endl;

    return 0;
}