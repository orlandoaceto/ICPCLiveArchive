//7273 - Black Vienna
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
vi dfs_num, dfs_low, S, visited;
int dfsNumCount, numSCC;
vi sccNum;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumCount++;
	S.pb(u);
	visited[u] = 1;
	for(int j = 0; j < (int)adjList[u].size(); j++){
		int v = adjList[u][j];
		
		if(dfs_num[v] == -1)
			tarjanSCC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	
	if(dfs_low[u] == dfs_num[u]){
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			sccNum[v] = numSCC;
			if(u == v) break;
		}
		numSCC++;
	}
}

int main(){
	vector<vi> op;
	int n, i, j, k, l;
	char a, b;
	bool sol;
	bool sus1, sus2;
	
	while(scanf("%d", &n) > 0){
		op.assign(n, vi(4, 0));
		fr(i,n){
			scanf(" %c %c %d %d", &a, &b, &op[i][2], &op[i][3]);
			op[i][0] = (a-'A')*2;
			op[i][1] = (b-'A')*2;
			
			if(op[i][2] == 2){
				op[i][0]++;
				op[i][1]++;
			}
		}
		
		int ans = 0;
		for(i = 0; i < 26; i++){
			for(j = i+1; j < 26; j++){
				for(k = j+1; k < 26; k++){
					sol = 1;
					adjList.assign(52, vi());
					fr(l,n){
						sus1 = sus2 = 0;
						if(op[l][0]/2 == i || op[l][0]/2 == j || op[l][0]/2 == k) sus1 = 1;
						if(op[l][1]/2 == i || op[l][1]/2 == j || op[l][1]/2 == k) sus2 = 1;
						
						if(op[l][3] == 2){
							if(sus1 || sus2){
								sol = 0;
								break;
							}
							else{
								adjList[op[l][0]^1].pb(op[l][0]);
								adjList[op[l][1]^1].pb(op[l][1]);
							}
						}
						else if(op[l][3] == 1){
							if(sus1 && sus2){
								sol = 0;
								break;
							}
							else if(sus1){
								adjList[op[l][1]^1].pb(op[l][1]);
							}
							else if(sus2){
								adjList[op[l][0]^1].pb(op[l][0]);
							}
							else{
								adjList[op[l][0]^1].pb(op[l][1]);
								adjList[op[l][1]^1].pb(op[l][0]);
								adjList[op[l][0]].pb(op[l][1]^1);
								adjList[op[l][1]].pb(op[l][0]^1);
							}
						}
						else{
							if(!sus1){
								adjList[op[l][0]].pb(op[l][0]^1);
							}
							if(!sus2){
								adjList[op[l][1]].pb(op[l][1]^1);
							}
						}
						
					}
					if(sol){
						dfs_num.assign(52, -1);
						dfs_low.assign(52, 0);
						visited.assign(52, 0);
						dfsNumCount = numSCC = 0;
						sccNum.assign(52, 0);
						fr(l,52) if(dfs_num[l] == -1) tarjanSCC(l);
						for(l = 0; l < 52; l += 2){
							if(sccNum[l] == sccNum[l+1]){
								sol = 0;
								break;
							}
						}
						if(sol) ans++;
					}
				}
			}
		}
		
		printf("%d\n", ans);
		
	}
	return 0;
}
