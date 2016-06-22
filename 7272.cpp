//7272 - Promotions
//Problem at ICPC Live Archive
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

#include <bits/stdc++.h>
using namespace std;

#define fr(a, n) for(a = 0; a < n; a++)
#define fr1(a, n) for(a = 1; a <= n; a++)
#define frR(a, n) for (a = n; a >= 0; a--)
#define sc(a) scanf("%d", &a)
#define pr(a) printf("%d\n", a)
#define p(i, j) make_pair(i, j)
#define fi first
#define se second
#define pb push_back
#define clr(a) memset(a, 0, sizeof a);

const int oo = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

vi dep, locks;
vector<vi> adjList;
bool reached[5000];

void rec(int v, int u){
	reached[v] = 1;
	locks[u]++;
	dep[v]++;
	for(int i = 0; i < adjList[v].size(); i++)
		if(!reached[adjList[v][i]])
			rec(adjList[v][i], u);
}

int main(){
	//ios::sync_with_stdio(0);
	int a, b, e, p;
	int i, j, u, v;
	int ansA, ansB, imp;
	
	while(scanf("%d %d %d %d", &a, &b, &e, &p) > 0){
		adjList.assign(e, vi());
		dep.assign(e,0);
		locks.assign(e,0);
		fr(i,p){
			scanf("%d %d", &u, &v);
			adjList[u].pb(v);
		}
		
		fr(i,e){
			clr(reached);
			fr(j,adjList[i].size()){
				if(!reached[adjList[i][j]])
					rec(adjList[i][j], i);
			}
		}
		ansA = ansB = imp = 0;
		
		fr(i,e){
			if(e - locks[i] - 1 < a) ansA++;
			if(e - locks[i] - 1 < b) ansB++;
			if(dep[i] >= b) imp++;
		}
		
		printf("%d\n%d\n%d\n", ansA, ansB, imp);
		
	}
	
	return 0;
}
