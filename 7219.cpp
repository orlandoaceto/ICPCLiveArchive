//7219 - Problem on Group Trip
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
	int t, k;
	int n, i, j;
	vii v[3];
	int time[100][3];
	int elapsed, processed, mini;
	vector<bool> checked;
	sc(t);
	fr1(k,t){
		sc(n);
		fr(i,3) v[i].clear();
		fr(i,n){
			scanf("%d %d %d", &time[i][0], &time[i][1], &time[i][2]);
			v[0].pb(p(i,0));
		}
		
		
		bool flag;
		fr(i,2){
			checked.assign(n, false);
			elapsed = 0;
			processed  = 0;
			while(processed < n){
				mini = oo;
				flag = 0;
				fr(j,n){
					if(!flag && !checked[j] && elapsed >= v[i][j].se){ 
			
						if(time[v[i][j].fi][i] == 0){
							v[i+1].pb(p(v[i][j].fi, v[i][j].se));
							processed++;
							checked[j] = 1;
							continue;
						}
			
						elapsed += time[v[i][j].fi][i];
						v[i+1].pb(p(v[i][j].fi, elapsed));
						processed++;
						checked[j] = 1;
						flag = 1;
					}
					else if(!checked[j]){
						mini = min(mini, v[i][j].se);
					}
				}
				if(mini > elapsed && mini != oo) elapsed = mini;
			}
			sort(v[i+1].begin(), v[i+1].end());
		}
		
		
		checked.assign(n, false);
		elapsed = 0;
		processed = 0;
		while(processed < n){
			mini = oo;
			flag = 0;
			fr(j,n){
				if(!flag && !checked[j] && elapsed >= v[i][j].se){ 
		
					if(time[v[i][j].fi][i] == 0){
						processed++;
						checked[j] = 1;
						continue;
					}
		
					elapsed += time[v[i][j].fi][i];
					processed++;
					checked[j] = 1;
					flag = 1;
				}
				else if(!checked[j]){
					mini = min(mini, v[i][j].se);
				}
			}
			if(mini > elapsed && mini != oo) elapsed = mini;
		}
		
		printf("Case #%d: %d\n", k, elapsed);
	}
	return 0;
}
