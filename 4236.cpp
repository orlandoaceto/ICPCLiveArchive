//4236 - Text Messaging Improvement?
//ICPC Live Archive
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
This problem can be solved using dynamic programming technique.
The subproblem considered for this solution is as follows: if you're
looking at a given key and a given letter, you have 2 options:
1: Not include this letter in this key and go to the next key
2: Include this letter in this key and go to the next letter
The first key with the first letter is a special case since it
must be included in the first key, so you start the recursive calls
from the second letter and the first key. With this recursive solution,
memorization can be added to make it a DP solution that won't get TLE.
A second memory is necessary to save which numbers have been chosen as first
of a key in a given sub-problem during the cost computation
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
#define INF 1000000000
#define N 26

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

double memo[N][N][N];
int memoDistr[N+2][N+2][N+2];
bool s[N][N][N];
double freq[N];
int n, k;

double go(int tAtual, int posF, int dist){
	if(s[tAtual][posF][dist]) return memo[tAtual][posF][dist];
	
	if(posF == N && tAtual == k){
		return 0;
	}
	else if(posF == N && tAtual < k){
		return INF;
	}
	
	double custo = INF;	
	
	if(dist < 9)
	custo = go(tAtual, posF+1, dist+1)+ freq[posF]*dist;
	memoDistr[tAtual][posF][dist] = memoDistr[tAtual][posF+1][dist+1];
	if(tAtual < k){
		double custoAux = go(tAtual+1, posF+1, 2) + freq[posF];
		if(custoAux < custo){
			memoDistr[tAtual][posF][dist] = 1<<posF;
			memoDistr[tAtual][posF][dist] |= memoDistr[tAtual+1][posF+1][2];
			custo = custoAux;
		}
	}
	
	s[tAtual][posF][dist] = 1;
	return memo[tAtual][posF][dist] = custo;
}


int main(){
	int caso, i;
	int distr;
	double total;
	sc(n);
	
	fr1(caso, n){
		sc(k);
		total = 0;
		fr(i,N){
			scanf("%lf", &freq[i]);
			total += freq[i];
		}
		clr(s);
		memset(memoDistr, 0, sizeof memoDistr);
		distr = 0;
		printf("%d %.3lf ", caso, (freq[0]+go(1, 1, 2))/total);
		distr |= memoDistr[1][1][2];
		fr(i,N){
			if(distr & (1<<i)) printf(" ");
			printf("%c", i+'A');
		}
		printf("\n");
		
	}
}
