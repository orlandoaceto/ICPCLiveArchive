//6491 - You Win!
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

string s;
int n, lim;
int pd[(1<<18)+100][18+10];

int go(int bitm, int curs){
	if(bitm == lim) return 0;
	if(pd[bitm][curs]) return pd[bitm][curs];

	int mini, i, cost, costMov, cont, charAt;
	
	if(bitm == 0){
		charAt = 0;
		mini = oo;
		for(i = 0; i < n; i++){
			cost = 1 + min((s[i]-'A'-charAt+ 26) % 26, (charAt - (s[i]-'A') + 26) % 26) +go(bitm | 1<<i, i+1);
			mini = min(mini, cost);
		}
		return mini;
	}
	else{
		charAt = s[curs-1] - 'A';
	}
	
	mini = oo;
	for(i = curs, costMov = 0; i < n; i++){
		if((bitm & (1<<i)) != 0) costMov++;
		else{
			cost = 1 + costMov + min((s[i]-'A'-charAt+ 26) % 26, (charAt - (s[i]-'A') + 26) % 26) +go(bitm | 1<<i, i+1);
			mini = min(mini, cost);
		}
	}
	for(i = curs-2, costMov = 1; i >= 0; i--){
		if((bitm & (1<<i)) != 0){
			costMov++;
		}
		else{
			cost = 1 + costMov + min((s[i]-'A'-charAt+ 26) % 26, (charAt - (s[i]-'A') + 26) % 26) +go(bitm | 1<<i, i+1);
			mini = min(mini, cost);
		}
	}
	
	return pd[bitm][curs] = mini;
}

int main(){
	
	
	while(cin>>s){
		if(s == "0") break;
		clr(pd);
		n = s.size();
		lim = (1<<n)-1;
		printf("%d\n", go(0, 0));
		
	}
	return 0;
}
