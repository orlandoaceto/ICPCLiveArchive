//7215 - Udin and Ucok
//Problem at ICPC Live Archive	
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
Game theory (Sprague-Grundy Theorem)
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


int pd[100000];

int go(int n){ //The PD is just to find the pattern (and exceptions)
  if(n < 2) return n;
  if(pd[n] != -1) return pd[n];
  
  bool v[200];
  
  clr(v);
  
  v[go(n-2)] = 1;
  v[go(n-3)] = 1;
  
  int i, j;
  
  i = 1;
  j = n - 4;
  
  
  if(j > 0){
    while(i <= j){
       v[go(i) ^ go(j)] = 1;
       i++;
       j--;
    }
  }
  
  for(i = 0; v[i] == 1; i++);
  
  return pd[n] = i;
  
}

int main() {
  int t, k, n, ans;
  sc(t);
  int v[34];
  
  memset(pd, -1, sizeof pd);
  
  for(int i = 0; i < 100; i++){
    go(i);
  }
  
    for(int i = 0; i < 34; i++){
      v[i] = go(i+10*34); //The period is 34, but the first 2 have exceptions, so get a period higher than 2nd (here it's the 11th)
  }

  fr1(k,t){
    sc(n);
    
    if(n >= 2){
      ans = v[n%34]; //At first assume it's not an exception
    }
    
    if(n == 0 || n == 14 || n == 34) ans = 0; //Exceptions
    if(n == 16 || n == 17 || n == 31 || n == 51) ans = 2; //Exceptions
    
    printf("Case #%d: ", k);
    if(ans == 0){
      printf("UCOK\n");
    }
    else{
      printf("UDIN\n");
    }
  }
  return 0;
}
