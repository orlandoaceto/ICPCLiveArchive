//7281 - Saint John Festival
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

#define EPS 1e-12

int cmp(double a, double b = 0.0) {
  if (fabs(a-b) < EPS) return 0;
  else if (a < b) return -1;
  return 1;
}

struct PT {
  double x,y;
  PT() {}
  PT(double x, double y) : x(x), y(y){}
  PT(const PT &p) : x(p.x), y(p.y){}
  PT operator +(const PT &p)     const { return PT(x+p.x,y+p.y); }
  PT operator -(const PT &p)     const { return PT(x-p.x,y-p.y); }
  PT operator *(double c)        const { return PT(x*c,y*c);     }
  PT operator /(double c)        const { return PT(x/c,y/c);     }
  double operator *(const PT &p) const { return x*p.x+y*p.y;     }
  double operator %(const PT &p) const { return x*p.y-y*p.x;     }
  double operator !()            const { return sqrt(x*x+y*y);   }
  double operator ^(const PT &p) const { return fabs(atan2(*this%p,*this*p)); }
  bool operator ==(const PT &p)  const { return cmp(x,p.x)==0 && cmp(y,p.y)==0; }
  bool operator <(const PT &p)   const {
    if (cmp(x,p.x)!=0) return cmp(x,p.x)==-1;
    return cmp(y,p.y)==-1;
  }
};

vector<PT> ch(vector<PT> P) {
	int i;
	int n = P.size(), k = 0;
	vector<PT> H(2*n);
	sort(P.begin(), P.end());
	fr(i, n) {
		while(k >= 2 && ((H[k-1]-H[k-2])%(P[i]-H[k-2])) <= 0) k--;
		H[k++] = P[i];
	}
	for(int i = n-2, t = k+1; i >= 0; i--) {
		while(k >= t && (H[k-1]-H[k-2])%(P[i]-H[k-2]) <= 0) k--;
		H[k++] = P[i];
	}
	H.resize(k);
	
	return H;
}

PT tri[4];

bool intri(PT q) {
	bool c = 0;
	int i;
	fr(i, 3) {
		if((tri[i].y <= q.y && q.y < tri[i+1].y || tri[i+1].y <= q.y && q.y < tri[i].y) && q.x < tri[i].x + (tri[i+1].x - tri[i].x)*(q.y-tri[i].y)/(tri[i+1].y - tri[i].y)) {
			c = !c;
		}
	}
	return c;
}

bool inSeg(PT x, PT a, PT b){
	return cmp((x-a) % (x-b)) == 0 && cmp((x-a) * (x-b)) <= 0;
}

bool inp(PT q, const vector<PT> &P) {
	PT pivot = P[0];
	int x = 1, y = P.size();
	
	while(y - x != 1) {
		int z = (x+y)/2;
		PT diagonal = pivot - P[z];
		if(((P[x]-pivot)%(q-pivot)) * ((q-pivot)%(P[z]-pivot)) >= 0) y = z;
		else x = z;
	
	}
	
	tri[0] = pivot;
	tri[1] = P[x];
	tri[2] = P[y];
	tri[3] = pivot;
	bool opt = 0;
	int i;
	
	fr(i,3){
		opt = opt || inSeg(q, tri[i], tri[i+1]);
	}
	return intri(q) || opt;

}


int main(){
	int l, s, i;
	vector<PT> large, hull;
	PT point;
	
	while(scanf("%d", &l) > 0){
		large.resize(l);
		fr(i,l){
			scanf("%lf %lf", &large[i].x, &large[i].y);
		}
		hull = ch(large);
		sc(s);
		int ans = 0;
		fr(i,s){
			scanf("%lf %lf", &point.x, &point.y);
			if(inp(point, hull)) ans++;
		}
		printf("%d\n", ans);
		
	}
}
