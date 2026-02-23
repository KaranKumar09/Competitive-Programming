  #include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.pop_back();
	//cout<<v.at(2)<<endl;
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
	cout<<v.front()<<endl;
	cout<<v.back()<<endl;
	cout<<v.empty()<<endl;
}
