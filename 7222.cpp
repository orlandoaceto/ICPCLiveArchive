//7222 - National Disaster
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
	int can;
	double dist;
	ll difX, difY, lies;
	pair<ll, ll> v[200];
	vector<pair<ll, bool> > pa;
	pair<ll, ll> best;
	sc(t);
	
	fr1(k,t){
		sc(n);
		fr(i,n){
			scanf("%lld", &v[i].fi);
		}
		fr(i,n){
			scanf("%lld", &v[i].se);
		}
		
		lies = 0;
		pa.clear();
		fr(i,n){
			fr(j,n){
				sc(can);
				if(i != j){
					difX = v[i].fi - v[j].fi;
					difY = v[i].se - v[j].se;
					if(can){
						pa.pb(p(difX*difX + difY*difY, true));
						lies++;
					}
					else{
						pa.pb(p(difX*difX + difY*difY, false));
					}
				}
			}
		}
		sort(pa.begin(), pa.end());
		
		best = p(lies, 0);
		ll dist = 0;
		for(i = 0; i < pa.size(); i++){
			dist = pa[i].fi;
			while(i < pa.size() && pa[i].fi == dist){
				if(pa[i].se){
					lies--;
				}
				else{
					lies++;
				}
				i++;
			}
			i--;
			best = min(best, p(lies, dist));
		}
		if(ans == oo) ans = 0;
		printf("Case #%d: %lld %lld\n", k, best.se, best.fi);
		
	}
	return 0;
}
