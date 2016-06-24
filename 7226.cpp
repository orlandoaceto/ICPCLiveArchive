//7276 - Wooden Signs
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

int v[2002];
ll memo[2002][2002];
int n;

ll go(int base, int pos){
	if(pos == n+1) return 1LL;
	if(memo[base][pos] != -1) return memo[base][pos];
	
	ll ans = 0;
	if(min(base, v[pos-1]) < v[pos]){
		ans += go(min(base, v[pos-1]), pos+1);
		ans %= 2147483647;
	}
	if(max(base, v[pos-1]) > v[pos]){
		ans += go(max(base, v[pos-1]), pos+1);
		ans %= 2147483647;
	}

	return memo[base][pos] = ans;
}

int main(){
	int i;
	while(sc(n) > 0){
		fr(i,n+1) sc(v[i]);
		if(n == 1){
			printf("1\n");
			continue;
		}
		memset(memo, -1, sizeof memo);
		printf("%lld\n", go(v[0], 2)%2147483647);
	}
	return 0;
}
