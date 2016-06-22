//275 - Dice Cup
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
	int n, m, i, j;
	bool first = 1;
	int maxi;
	int v[41];
	
	while(scanf("%d %d", &n, &m) > 0){
		if(first) first = 0;
		else printf("\n");
		
		clr(v);
		maxi = 0;
		fr1(i,n){
			fr1(j,m){
				v[i+j]++;
				maxi = max(maxi, v[i+j]);
			}
		}
		
		fr1(i,40){
			if(v[i] == maxi) printf("%d\n", i);
		}
	}

	return 0;
}
