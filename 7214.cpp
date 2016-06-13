//7214 - Arithmetical CAPTCHA
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

int n[4];
bool printed;

void calc (int posOp, int op[3]){
  if(posOp == 3 && !printed){
    bool valid = 1;
    int countEq = 0;
    for(int i = 0; i < 3; i++){
      if(op[i] == 1){
        countEq++;
        int sumLeft = 0;
        int sumRight = 0;
        for(int j = i-1;;j--){
          if(j < 0 || op[j] == 1){
            sumLeft += n[j+1];
            break;
          }
          else if(op[j] == 2){
            sumLeft += n[j+1];
          }
          else{
            sumLeft -= n[j+1];
          }
        }
        sumRight += n[i+1];
        for(int j = i+1; j < 3 && op[j] != 1; j++){
          if(op[j] == 2){
            sumRight += n[j+1];
          }
          else{
            sumRight -= n[j+1];
          }
        }
        if(sumLeft != sumRight){
          valid = 0;
          break;
        }
      }
    }
    if(countEq > 0 && valid){
      printf("%d", n[0]);
      printed = 1;
      for(int i = 0; i < 3; i++){
        if(op[i] == 1){
          printf(" = ");
        }
        else if(op[i] == 2){
          printf(" + ");
        }
        else if(op[i] == 3){
          printf(" - ");
        }
        printf("%d", n[i+1]);
      }
    }
  }
  else if(posOp < 3){
    op[posOp] = 1;
    calc(posOp+1, op);
    op[posOp] = 2;
    calc(posOp+1, op);
    op[posOp] = 3;
    calc(posOp+1, op);
   }
  
}

int main() {
  int t, k;
  
  sc(t);
  
  fr1(k,t){
    printf("Case #%d: ", k);
    printed = 0;
    scanf("%d %d %d %d", &n[0], &n[1], &n[2], &n[3]);
    int op[3];
    clr(op);
    calc(0, op);
    printf("\n");
  }

  return 0;
}
