//7225 - Summation and Divisor
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

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	vector<vector<ll> > v;
	vector<ll> dif;
	
	int t, k;
	int n, m, i, j, l;
	
	ll num;

	sc(t);
	
	fr1(k,t){
		sc(n);
		v.resize(n);
		dif.clear();
		fr(i,n){
			sc(m);
			v[i].resize(m);
			fr(j,m) scanf("%lld", &v[i][j]);
			sort(v[i].begin(), v[i].end());
			for(j = 0; j < v[i].size(); j++){
				for(l = j + 1; l < v[i].size(); l++){
					dif.pb(v[i][l] - v[i][j]);
				}
			}
		}
		
		num = 0;
		for(i = 0; i < n; i++){
			num += v[i][0];
		}
		
		for(i = 0; i < dif.size(); i++){
			num = gcd(num, dif[i]);
		}
		
		
		printf("Case %d: %lld\n", k, num);
		
	}
	
	return 0;
}
