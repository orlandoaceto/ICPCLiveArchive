//5135 - Mining Your Own Business
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
vi dfs_num;
vi dfs_low;
vi dfs_parent;
int dfsNumberCounter;
vector<bool> articulation_vertex;
int dfsRoot, rootChildren;
vector<vi> bcc;
stack<int> st;

void dfs(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	st.push(u);
	for(int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
		
			if(u == dfsRoot) rootChildren++;
		
			dfs(v);
		
			if(dfs_low[v] >= dfs_num[u]){
				articulation_vertex[u] = true;
				bcc.pb(vi());
				while(st.top() != v){
					bcc.back().pb(st.top());
					st.pop();
				}
				bcc.back().pb(st.top());
				st.pop();
				bcc.back().pb(u);
			}
		
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	ll n, s, t, m;
	ll i, j;
	ll ans, counter, caseNum = 0, mult;

	while(scanf("%lld", &m) > 0){
		if(m == 0) break;
		adjList.clear();
		n = 0;
		fr(i,m){
			scanf("%lld %lld", &s, &t);
			if(max(s, t) > n){
				n = max(s,t);
				adjList.resize(n);	
			}
			s--; t--;
			adjList[s].pb(t);
			adjList[t].pb(s);
		}
		
		
		dfs_num.assign(n, -1);
		dfs_low.assign(n, 0);
		dfs_parent.assign(n, 0);
		articulation_vertex.assign(n,0);
		dfsNumberCounter = 0;
		st = stack<int>();
		bcc.clear();
		fr(i,n){
			if(dfs_num[i] == -1){
				dfsRoot = i;
				rootChildren = 0;	
				dfs(i);
				articulation_vertex[i] = (rootChildren > 1);
			}
		}
		counter = 0;
		ans = 1;
		
		fr(i,bcc.size()){
			int numArt = 0;
			fr(j,bcc[i].size()){
				if(articulation_vertex[bcc[i][j]]) numArt++;
			}
			if(numArt == 1){
				counter++;
				ans *= (ll)j -1;
			}
			if(numArt == 0){
				counter = 2;
				ans = n * (n-1) / 2;
			}
		}	
	
		printf("Case %lld: %lld %lld\n", ++caseNum, counter, ans);
	}
	
	return 0;
}
