//7274 - Canvas Painting
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
	ll t, n, i, aux;
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	ll a, b, cost;
	scanf("%lld", &t);
	
	while(t--){
		scanf("%lld", &n);
		fr(i,n){
			scanf("%lld", &aux);
			pq.push(aux);
		}
		
		cost = 0;
		while(1){
			a = pq.top();
			pq.pop();
			if(pq.empty()) break;
			b = pq.top();
			pq.pop();
			cost += a + b;
			pq.push(a+b);
		}
		printf("%lld\n", cost);
		
	}
	return 0;
}
