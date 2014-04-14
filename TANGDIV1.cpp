#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

typedef pair<long long, long long> pll;
typedef vector<pll> vpll;

bool violates(vpll ar, long long k){
	//binary search over inervals
	int lo=0, hi = ar.size()-1; 
	while(lo <=hi){
		int mid = lo + (hi - lo )/2;
		if(ar[mid].first <= k && k <= ar[mid].second )
			return true;
		else if(k < ar[mid].first)
			hi = mid - 1;
		else if(k > ar[mid].second)
			lo = mid + 1;
	}
	return false;
}

int main(){
	long long t,N,K,P;
	vpll k;
	k.reserve(1005);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld",&N,&K,&P);
		long long a, b;
		for(int i =0; i < K;i++){
			scanf("%lld%lld",&a,&b);
			if(a <=b)
				k.push_back(pll(2*a-1, 2*b-1));
			else{
				k.push_back(pll(2*a-1, 2*N));
				k.push_back(pll(1,2*b-1));
			}
		}
		
		sort(k.begin(), k.end());
		
		bool flag = false;
		for(int i = 0; i < P; i++){
			scanf("%lld%lld",&a,&b);
			a = 2*a-2;
			b = 2*b;
			if(a ==0)
				a = 2*N;
			if(!flag && (violates(k,a) || violates(k,b))){
				puts("No");
				flag=true;
			}
		}
		if(!flag)
			puts("Yes");
		k.clear();
	}
}
