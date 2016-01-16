//lexicorgraphically, greatest string or lexi smallest if there are multiple answers
//playground
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int asc(char c){
	return (int)c;
}


void lexi_greater(string tex){
	int count = 0;
	string temp = tex;
	for(uint i=0; i<tex.size()-1; i++){
		for(uint j=i+1; j<tex.size();j++){
			if(asc(tex[i]) < asc(tex[j])){
				count++;
				swap(tex[i], tex[j]);
			}
		}
	}
	if(temp == tex){
		cout<<"no answer"<<endl;
	}
	else if(count > 1){
		for(string::reverse_iterator i = tex.rbegin(); i<tex.rend(); i++){
			cout<<*i;
		}
	}
	else{
		cout<<tex;
	}
	cout<<endl;
}


int main() {
	long long t;
	cin>>t;
	string *w = new string[t];
	for(int i=0; i<t; i++){
		cin>>w[i];
	}
	for(int i=0; i<t;i++){
		lexi_greater(w[i]);
	}
    return 0;
}
