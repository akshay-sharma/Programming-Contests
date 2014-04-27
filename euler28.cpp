#include<cstdio>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int n = 1001;

	long long int ans = 1;
	for( int i = 3; i <= n; i += 2){
		int start = (i-2)*(i-2);//start of spiral ring
		for(int c = 1; c <=4; c++){
			ans += start+ c*(i-1);
			printf("%d\n", start + c*(i-1));
		}
			
	}
	printf("ans= %lld\n",ans);
}
