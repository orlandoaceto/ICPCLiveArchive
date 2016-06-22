//7278 - Game of Cards
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

vector<vi> cards;
vector<vi> grundy;
int p, k, n;

int calc(int num, int card){
	if(card < 0) return 0;
	if(grundy[num][card] != -1) return grundy[num][card];

	bool v[1010];
	clr(v);
	int i;
	
	for(i = 0; i <= k; i++){
		if(card >= i && card-i-cards[num][card-i] >= -1){
			v[calc(num, card-i-cards[num][card-i])] = 1;
		}
	}
	
	for(i = 0; v[i]; i++);
	
	
	return grundy[num][card] = i;
}

int main(){
	int i, j;
	int ans;
	while(scanf("%d %d", &p, &k) > 0){
		cards.assign(p+10, vi());
		grundy.assign(p+10, vi());
		fr(i,p){
			sc(n);
			cards[i].resize(n);
			grundy[i].assign(n+10, -1);
			fr(j,n){
				sc(cards[i][j]);
			}
		}
		ans = 0;
		fr(i,p){
			ans ^= calc(i, (int)cards[i].size()-1);
		}
		
		if(ans == 0){
			printf("Bob will win.\n");
		}
		else{
			printf("Alice can win.\n");
		}
		
	}
	
	return 0;
}
