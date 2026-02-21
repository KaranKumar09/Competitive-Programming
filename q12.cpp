#include<bits/stdc++.h>
using namespace std;
set<char> getDigits(int num){
    set<char> digits;
    string s=to_string(num);
    for(char c : s){
        digits.insert(c);
    }
    return digits;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        set<char>digitsOfX=getDigits(x);
        for(int y=0;y<=1000;++y){
            string sy=to_string(y);
            bool found=false;
            for(char c : sy){
                if(digitsOfX.count(c)){
                    cout<<y<<endl;
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
    }
    return 0;
}
