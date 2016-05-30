//5059 - Playing With Stones
//Problem at ICPC Live Archive
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
Theoretically, this problem could be solved by finding the nimber of each number that appears
and doing the bitwise or of all of them. The problem is that the nimber of a number is the mex
(minimum excludent) of all the states it can transform into. Since the number in this problem can
go up to 10^18, 5*10^17 states would have to be checked to find it (and each of these states would
need to check many more too). PD is also not feasible because a vector of size 10^18 wouldn't fit 
(and O(n) isn't good enough with 10^18 anyway). So faster way needs to be found. Turns out there is
a log(n) way to find the nimber of a number in this problem. If you generate the first few (say 100)
numbers and their respective nimber (computing the mex), you could figure out that every even number n
has a nimber of n/2, and every odd number has the nimber equal to nimber of floor(n/2). This is easier to
see in binary since the sequence of numbers that have a certain nimber is pretty peculiar, and it's easy to
see in this base that a number m in the sequence of numbers with a certain nimber becomes the next lowest
number in the sequence with a right shift (m>>1), which is equivalent to m/2. 
*/

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

ll compute(ll x){
	return x%2?compute(x>>1):x>>1;
}

int main(){
	int t, n, i;
	ll ans, aux;
	sc(t);
	while(t--){
		sc(n);
		ans = 0;
		fr(i,n){
			scanf("%lld", &aux);
			ans ^= compute(aux);
		}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
