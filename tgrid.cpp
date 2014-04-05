#include<cstdio>
#include<iostream>
#include<cassert>

using namespace std;

int main(){
	int t,m,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		int small = min(m,n);
		small = (small/2)*2;
		m -= small;
		n -= small;
		
		if(m == 0)	puts("L");
		else if(n == 0) puts("U");
		else if(m == 1) puts("R");
		else if(n == 1) puts("D");
		else	assert(true);
	}
}
