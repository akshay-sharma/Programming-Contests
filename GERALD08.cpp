#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<cmath>
/*
Did not get AC on Contest.
*/

using namespace std;

struct node{
	int index, edge;
	node( int a, int b){
		index = a;
		edge = b;
	}
};

struct treenode{
	vector<struct node> children;
};

treenode tree[100005];

const double eps = 1e-8;
double compute( int root){
	double nodeGameValue = 0.0;
	for(int i = 0; i < tree[root].children.size(); i++){
		int childIndex = tree[root].children[i].index;
		int color = tree[root].children[i].edge;
		assert( color == 1 || color == 0);
		double gameValue = compute(childIndex);
		if(color == 0){//black or blue
			double k=0;
			if(gameValue > 0){// x+1 should suffice
				k = 1.0;
			}
			else{
				k = ceil(1.0 - gameValue);
				if( fabs ( gameValue - (long long)gameValue) < eps)// gameValue is an integer
					k = k + 1.0;
				gameValue = gameValue + k;
				assert(gameValue > 1.0);
				gameValue = gameValue / pow(2.0, k-1);
			}
		}
		else{//white or red
			double k =0;
			if(gameValue < 0){//x-1 should suffice
				k = 1.0;
			}
			else{
				double k = ceil(gameValue + 1);
				if( fabs (gameValue - (long long)gameValue) < eps )//gameValue is an integer
					k = k + 1.0;
				gameValue = gameValue - k;
				assert(gameValue < -1.0);
				gameValue = gameValue / pow(2.0, k-1);
			}
		}
		nodeGameValue += gameValue;
	}
	//printf("gameValue for tree rooted at %d is %lf\n", root, nodeGameValue);
	return nodeGameValue;
}

int main(){
	int t,n,u,v,c;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for( int i = 1; i <=n; i++)
			tree[i].children.clear();
		for(int i = 1; i < n; i++){
			scanf("%d%d%d",&u,&v,&c);
			if(u > v)
				swap(u,v);
			tree[u].children.push_back( node(v,c));
		}
	/*
	//printing the tree
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int a = q.front();
		q.pop();
		printf("%d ",a);
		for( int i =0; i<tree[a].children.size(); i++){
			q.push(tree[a].children[i].index);
		}
	}
	puts("");
	*/
	double d = compute(1);
	//printf("%lf ",d);
	if(d > 0)
		puts("Chef Chef");
	else if(d < 0)
		puts("Ksen Ksen");
	else
		puts("Ksen Chef");
	}
}
