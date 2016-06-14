//7220 - Dungeon Trap
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

struct cell{
	int i, j, k;
	int cost;
	
	cell(){};
	
	cell(int _a, int _b, int _c, int _cost){
		i = _a;
		j = _b;
		k = _c;
		cost = _cost;
	}
	
	bool operator < (const cell o)const {
		return cost > o.cost;
	}
};

int main(){
	int t, l;
	int i, j, k, n, m;
	int mini[100][100][10];
	int ma[100][100];
	ii end;
	char r;
	int total;
	
	int dr[] = {1,-1,0,0};
	int dc[] = {0,0,-1,1};
	
	priority_queue<cell> pq;
	
	sc(t);
	
	fr1(l,t){
		scanf("%d %d\n", &n, &m);
		pq = priority_queue<cell> ();
		total = 0;
		fr(i,n){
			fr(j,m){
				scanf(" %c", &r);
				if(r == 'A'){
					pq.push(cell(i,j,0,0));
				}
				else if(r == 'B'){
					end = p(i,j);
					ma[i][j] = 0;
				}
				else{
					ma[i][j] = r - '0';
					total += ma[i][j];
					if(ma[i][j] == 0) ma[i][j] = -1;
				}
			}
		}
		
		memset(mini, 0x3f, sizeof mini);
		
		cell aux;
		cell next;
		while(!pq.empty()){
			aux = pq.top();
			pq.pop();
			
			if(aux.cost > mini[aux.i][aux.j][aux.k]){
				continue;
			}
			
			fr(i,4){
				next.i = aux.i + dr[i];
				next.j = aux.j + dc[i];
				
				if(next.i >= 0 && next.i < n && next.j >= 0 && next.j < m && ma[next.i][next.j] != -1){
					next.k = max(aux.k, ma[next.i][next.j]);
					next.cost = aux.cost + ma[next.i][next.j];
					
					if(next.cost < mini[next.i][next.j][next.k]){
						pq.push(next);
						mini[next.i][next.j][next.k] = next.cost;
					}
				}
			}
		}
		
		int ans = oo;
		
		fr(i,10){
			if(mini[end.fi][end.se][i] != oo){
				ans = min(ans, mini[end.fi][end.se][i] - i);
			}
		}
		if(ans == oo) ans = total;
		printf("Case #%d: %d\n", l, total - ans);
		
	}
	return 0;
}
