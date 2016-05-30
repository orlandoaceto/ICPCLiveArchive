//6485 - Electric Car Rally
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

int main(){
	int n, m, a, b, c, st, en;
	int i, j, k;
	int cost[501][241];
	vector<vii> interval;
	vector<vii> adjList;
	priority_queue<pair<int, ii>,vector<pair<int, ii> >, greater<pair<int, ii> > > q;
	
	while(scanf("%d %d", &n, &m) > 0){
		if(n == 0 && m == 0) break;
		adjList.assign(n, vii());
		interval.assign(n, vii());
		fr(i,m){
			scanf("%d %d", &a, &b);
			do{
				scanf("%d %d %d", &st, &en, &c);
				adjList[a].pb(ii(b,c));
				interval[a].pb(ii(st, en));
				adjList[b].pb(ii(a,c));
				interval[b].pb(ii(st,en));
			}while(en != 1439);
		}
		
		q = priority_queue<pair<int, ii>,vector<pair<int, ii> >, greater<pair<int, ii> > > ();
		cost[0][240] = 0;
		memset(cost, 0x3f, sizeof cost);
		q.push(p(720, ii(0, 240)));
		
		int custo, vert, bat;
		
		while(!q.empty()){
			custo = q.top().fi;
			vert = q.top().se.fi;
			bat = q.top().se.se;
			q.pop();
			
			
			if(vert == n-1){
				break;
			}
			
			
			if(bat < 240 && custo + 2 < cost[vert][bat+1]){
				cost[vert][bat+1] = custo + 2;
				q.push(p(custo+2, ii(vert, bat+1)));
			}
			
			for(i = 0; i < adjList[vert].size(); i++){
				int next = adjList[vert][i].fi;
				int dur = adjList[vert][i].se;
				int start = interval[vert][i].fi;
				int end = interval[vert][i].se;
				
				if(start <= (custo % 1440) && end >= (custo % 1440) && bat >= dur){
					if(custo + dur < cost[next][bat-dur]){
						cost[next][bat-dur] = custo+dur;
						q.push(p(custo+dur, ii(next, bat-dur)));
					}
				}
				else{
					int wait = (start - (custo % 1440) + 1440) % 1440;
					int newBat = min(bat + wait/2,240);
					if(newBat >= dur){
						if(custo + wait + dur < cost[next][newBat-dur]){
							cost[next][newBat-dur] = custo + wait + dur;
							q.push(p(custo + wait + dur, ii(next, newBat-dur)));
						}
					}
					
				}
			}
		}
		
		printf("%d\n", custo - 720);
	}
	
	
	return 0;
}
