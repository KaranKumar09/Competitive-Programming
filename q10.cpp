#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,q;
	cin>>n>>q;
	vector<long long> arr(n+1);
	vector<long long> prefix(n+1,0);
	for(int i=1;i<=n;i++){
	    cin>>arr[i];
	    prefix[i] = prefix[i-1] + arr[i];
	}
	while(q--){
	    int a,b;
	    cin>>a>>b;
	    cout<<prefix[b] - prefix[a-1]<<endl;
	}
    return 0;
}
