#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
int strToBinary(int n){
    string result = " ";
    int count = 0;
    for(int i = 1; i<=n; i++){
        while(n > 0){
            if(n % 2==1){
                result += '1';
            }
            else{
                result += '0';
            }
            n = n/2;
        }
        reverse(result.begin(),result.end());
        for(int i=0;i<result.length();i++){
          if(result[i]=='1'){
            count++;
          }
        }
    }
    return count;
}
int main() {
    // Write C++ code here
    int n;
    cout<<"Enter the number to convert in binary: ";
    cin>>n;
    int ans = strToBinary(n);
    cout<<"Binary Representation: "<<ans<<endl;

    return 0;
}