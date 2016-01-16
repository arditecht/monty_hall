#include <bits/stdc++.h>
using namespace std;
// maximum subsequence
vector<long> logger(10000, -1);
vector<long> table(10000, -1);

long maxer(vector<long> bush, unsigned long index, long K){
	if(table[index] > -1){
		return table[index];
	}
	//if(index = bush.size()-1 && bush
	long sum = bush[index], maxi=0;
	if(bush[index] == K){
		table[index] = bush[index];
		return table[index];
	}
	if(bush[index] > K){
		table[index] = 0;
		return table[index];
	}
	for(unsigned long i = index+2; i<bush.size(); i++){
		sum = bush[index];
		
		if(sum+bush[i]<K && i+2<bush.size())
		{sum += bush[i] + maxer(bush, i+2, K-bush[i]-sum);}
		
		else if(sum+bush[i]>K)
		{continue;}
		
		else
		{sum+=bush[i];}
		
		maxi = max(sum, maxi);
		//cout<<endl<<sum<<"+"<<bush[i]<<" : "<<maxi<<endl;
	}
	table[index] = max(sum, maxi);
	return table[index];
}

int main(){
	int T, indexer;
	cin>>T;indexer = T;
	long N, K, i_th;
	while(T--){
		table = logger;
		vector<long> bush;
		cin>>N>>K;
		while(N--){
			cin>>i_th;
			bush.push_back(i_th);
		}
		long maximum = -1;
		for(uint i=0; i<bush.size(); i++){
		maximum = max(maximum, maxer(bush, i, K));
		}
		cout<<"Scenario #" << indexer-T <<": "<<maximum<<endl;
	}
	return 0;
}
