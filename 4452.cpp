//4452 - The Ministers' Major Mess
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
		++numSCC;
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			sccNum[v] = numSCC;
			if(u == v) break;
		}
	}
}

bool reach(int v, int u){
	visited[v] = 1;
	if(v == u) return 1;
	int i;
	bool ans;
	fr(i,adjList[v].size()){
		if(!visited[adjList[v][i]]){
			ans = ans | reach(adjList[v][i], u);
		}
		if(ans) break;
	}
	
	return ans;
}

int main(){
	int b, m, k;
	int i, j, l;
	char vote;
	int bills[4];
	int caseNum = 0;
	
	while(scanf("%d %d", &b, &m) > 0){
		if(b == 0 && m == 0) break;
		adjList.assign(2*b,vi());
		fr(i,m){
			sc(k);
			fr(j,k){
				scanf(" %d %c", &bills[j], &vote);
				bills[j]--;
				bills[j] *= 2;
				if(vote == 'n') bills[j] ^= 1;
				if(k <= 2){
					adjList[bills[j]^1].pb(bills[j]);
				}
			}
			
			if(k > 2){
				fr(j,k){
					fr(l,k){
						if(j != l){
							adjList[bills[j]^1].pb(bills[l]);
						}
					}
				}
			}
		}
		
		sccNum.assign(2*b, 0);
		dfs_num.assign(2*b, -1);
		dfs_low.assign(2*b, 0);
		visited.assign(2*b, 0);
		dfsNumCount = numSCC = 0;
		fr(i,2*b) if(dfs_num[i] == -1) tarjanSCC(i);

		bool sat = 1;
		for(i = 0; i < 2*b; i += 2){
			if(sccNum[i] == sccNum[i^1]){
				sat = 0;
				break;
			}
		}
		printf("Case %d: ", ++caseNum);
		if(sat){
			fr(i,b){
				bool tru, fal;
				visited.assign(2*b, 0);
				fal = reach(i*2, (i*2)^1);
				visited.assign(2*b, 0);
				tru = reach((i*2)^1, i*2);
				if(tru && !fal) printf("y");
				else if(!tru && fal) printf("n");
				else printf("?");
			}
			printf("\n");
		
		}
		else{
			printf("impossible\n");
		}
		
	}
		
	return 0;
}
