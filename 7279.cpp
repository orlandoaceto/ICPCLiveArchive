//7279 - Sheldon Numbers
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
	ull x, y, num, ones;
	int i, j, k,len;
	int add = 1;
	set<ull>::iterator it1, it2;
	set<ull> s;
	
	fr1(i,63){
		num = (1ULL<<i)-1ULL;
		s.insert(num);
	}
	fr1(i,63){
		ones = (1ULL << i)-1ULL;
		fr1(j,63){
			len = i;
			num = ones;
			add = 0;
			while(1){
				if(add){
					num <<= i;
					num += ones;
					len += i;
					add = 0;
				}
				else{
					num <<= j;
					len += j;
					add = 1;
				}
				if(len <= 63){
					s.insert(num);
				}
				else break;
			}
		}
	}
	
	
	while(cin>>x>>y){
		it1 = s.lower_bound(x);
		it2 = s.upper_bound(y);
		cout<<distance(it1,it2)<<'\n';
		
	}
}


