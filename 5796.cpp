//5796 - Hedge Mazes
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

vector<vi> adjList;
vector<vi> adjBridge;
vii bridges;
vi dfs_num;
vi dfs_low;
vi dfs_parent;
int dfsNumberCounter;

void dfs(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	
	for(int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
		
			dfs(v);
		
			if(dfs_low[v] > dfs_num[u]){
				adjBridge[v].pb(u);
				adjBridge[u].pb(v);
			}
		
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

vector<int> vis;

void df(int a, int col){
	vis[a] = col;
	for(int i = 0; i < adjBridge[a].size(); i++){
		int v = adjBridge[a][i];
		if(!vis[v]){
			vis[v] = col;
			df(v, col);
		}
		
	}
}

int main(){
	int n, c, q;
	int a, b;
	int i, j;
	
	while(scanf("%d %d %d", &n, &c, &q) > 0){
		if(n == 0 && c == 0 && q == 0) break;
		adjList.assign(n+1, vi());
		
		fr(i,c){
			scanf("%d %d", &a, &b);
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		
		dfsNumberCounter = 0;
		dfs_num.assign(n+1, -1);
		dfs_low.assign(n+1, 0);
		dfs_parent.assign(n+1, 0);
		adjBridge.assign(n+1, vi());
		
		fr1(i,n){
			if(dfs_num[i] == -1){
				dfs(i);
			}
		}
		
		vis.assign(n+1, 0);
		int count = 1;
		fr1(i,n){
			if(!vis[i]) df(i, count++);
		}
		
		fr(i,q){
			scanf("%d %d", &a, &b);
			if(vis[a] == vis[b]){
				printf("Y\n");
			}
			else{
				printf("N\n");
			}
		}
		printf("-\n");
	}
	
	return 0;
}
