//7165 - Feast Coins
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

ll pd[50][5001];
vii v;
int s, n;

ll go(int ind, int sum){

	if(ind == n){
		return 0;
	}

	if(pd[ind][sum] != -1) return pd[ind][sum];
	
	ll ans;
	if(s % (sum + v[ind].se) == 0 && v[ind].fi >= s / (sum + v[ind].se)){
		ans = 1;
	}
	else{
		ans = 0;
	}
	
	ans += go(ind+1, sum);
	
	if(sum + v[ind].se <= s){
		ans += go(ind+1, sum + v[ind].se);
	}
	
	return pd[ind][sum] = ans;
}

int main(){
	int k, t, i;
	
	sc(t);
	
	fr1(k,t){
		scanf("%d %d", &s, &n);
		v.resize(n);
		fr(i,n){
			scanf("%d %d", &v[i].se, &v[i].fi);
		}
		sort(v.rbegin(), v.rend());
		memset(pd, -1, sizeof pd);
		printf("Case %d: %lld\n", k, go(0, 0));
	}
	return 0;
}
