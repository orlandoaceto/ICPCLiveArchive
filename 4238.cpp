//4238 - Area of Polycubes
//ICPC Live Archive
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
The solution of this problem is to memorize which cubes have been
previously added and for each new added cube, check if it has a neighbor
among the previously inserted cubes. To do that, it's necessary to save the
cubes in a set since saving them in an unordered container would make the
solution complexity O(n^2) (O(n) insertions and at each insertion, O(n) to
verify all previous cubes and check for neighbors), which would likely get TLE.
The area can be easily computed while the cubes are added. Each new cube adds
an area of 6 - 2*(numbers of neighbors).
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
#define x first
#define y second.first
#define z second.second

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;

/*struct pt{
	ll x, y, z;
	bool operator < (const pt &c) const{
		if(x < c.x) return x < c.x;
		else if(y < c.y) return y < c.y;
		else return z < c.z;
	}
	bool operator == (const pt &c) const{
		return(x == c.x && y == c.y && z == c.z);
	}
	bool operator > (const pt &c) const{
		if(x > c.x) return x > c.x;
		else if(y > c.y) return y > c.y;
		else return z > c.z;
	}
};*/

int main(){
	set<pair<int, ii> > s;
	int n, t, i, k;
	int area;
	pair<ll, pair<ll, ll> > p;
	pair<ll, pair<ll, ll> > check;
	bool valid = 1;
	int index;
	
	scanf("%d\n", &t);
	
	fr1(k,t){
		scanf("%d\n", &n);
		s.clear();
		valid = 0;
		scanf(" %lld,%lld,%lld", &p.x, &p.y, &p.z);
		area = 6;
		s.insert(p);
		for(i = 0; i < n-1; i++){
			scanf(" %lld,%lld,%lld", &p.x, &p.y, &p.z);
			if(s.find(p) == s.end()){
				s.insert(p);
			}
			else{
				index = i+2;
				valid = 0;
				i++;
				break;
			}
			int viz = 0;
			valid = 0;
			check = p;
			check.x--;
			if(s.find(check) != s.end()){
				valid = 1;
				viz++;
			}
			check.x++;
			check.x++;
			if(s.find(check) != s.end()){
				valid = 1;
				viz++;
			}
			check.x--;
			check.y--;
			if(s.find(check) != s.end()){
				valid = 1;
				viz++;
			}
			check.y++;
			check.y++;
			if(s.find(check) != s.end()){
				valid = 1;
				viz++;
			}
			check.y--;
			check.z--;
			if(s.find(check) != s.end()){
				valid = 1;
				viz++;
			}
			check.z += 2;
			if(s.find(check) != s.end()){
				valid = 1;
				viz++;
			}
			area += 6 - 2*viz;
			if(!valid){
				index = i+2;
				i++;
				break;
			}
		}
		for(; i < n-1; i++){
			scanf(" %lld,%lld,%lld", &p.x, &p.y, &p.z);
		}
		
		if(valid){
			printf("%d %d\n", k, area);
		}
		else{
			printf("%d NO %d\n", k, index);
			valid = 1;
		}
	}
	
	return 0;
}
