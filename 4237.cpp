//4237 - Extended Normal Order Sort
//ICPC Live Archive
//Solution by Orlando Aceto - contact: ova@cin.ufpe.br
//Feel free to use this code if you wish

/*
For this problem, a possible solution is to transform every "unit"
of the string (either a number or a character in ascii) and transform
it into a string representing the number or the value of the character
in ASCII. Using the stl string::compare, it can then be found if an unit
is lower, higher or equal to the respective unit of the other string.
Negative numbers must be treated as special cases, since the string will
only hold the absolute value. If both numbers are negative, the order comparison
must be inverted. If one is negative and the other is positive, then obviously
the negative is smaller than the positive (I haven't considered the possibility
of negative zero being equal to zero, so the test cases likely don't have that or
I got lucky and it works for this case even though I didn't think of it)
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

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;



int main(){
	int n;
	sc(n);
	string s1, s2;
	ll val1, val2;
	int t, i, j;
	char numAux[20];
	bool neg1, neg2;
	string num1, num2;
	
	fr1(t,n){
		cin>>s1;
		cin>>s2;
		i = j = 0;
		int k;
		int ans = 0;
		while(i < s1.size() && j < s2.size()){
			num1.clear();
			num2.clear();
			if(((i-1 < 0 || s1[i-1] < '0' || s1[i-1] > '9') && (s1[i] == '+' || s1[i] == '-') && (i+1 < s1.size() && s1[i+1] >= '0' && s1[i+1] <= '9')) || (s1[i] >= '0' && s1[i] <= '9')){
				if(s1[i] == '-'){
					neg1 = 1;
					i++;
				}
				else if(s1[i] == '+'){
					neg1 = 0;
					i++;
				}
				else neg1 = 0;
				while(s1[i] == '0') i++;
				
				k = i;
				while(k < s1.size() && s1[k] >= '0' && s1[k] <= '9'){
					k++;
				}
				num1 = s1.substr(i, k-i);
				i = k;
			}
			else{
				neg1 = 0;
				val1 = toupper((s1[i]));
				sprintf(numAux, "%lld", val1);
				num1.assign(numAux);
				i++;
			}
			if(((j-1 < 0 || s2[j-1] < '0' || s2[j-1] > '9') && (s2[j] == '+' || s2[j] == '-') && (j+1 < s2.size() && s2[j+1] >= '0' && s2[j+1] <= '9')) || (s2[j] >= '0' && s2[j] <= '9')){
				if(s2[j] == '-'){
					neg2 = 1;
					j++;
				}
				else if(s2[j] == '+'){
					neg2 = 0;
					j++;
				}
				else neg2 = 0;
				while(s2[j] == '0') j++;
				k = j;
				while(k < s2.size() && s2[k] >= '0' && s2[k] <= '9'){
					k++;
				}
				sscanf(((s2.substr(j, k-j)).c_str()), "%lld", &val2);
				num2 = s2.substr(j, k-j);
				j = k;
			}
			else{
				neg2 = 0;
				val2 = toupper(s2[j]);
				sprintf(numAux, "%lld", val2);
				num2.assign(numAux);
				j++;
			}
			
			if(!num1.empty() && !num2.empty()){
				if(neg1 == 0 && neg2 == 0){
					if(num1.size() == num2.size())
						ans = num1.compare(num2);
					else{
						if(num1.size() > num2.size()){
							ans = 1;
						}
						else{
							ans = -1;
						}
					}
				}
				else if(neg1 == 1 && neg2 == 1){
					if(num1.size() == num2.size())
						ans = num2.compare(num1);
					else{
						if(num2.size() > num1.size()){
							ans = 1;
						}
						else{
							ans = -1;
						}
					}
				}
				else if(neg1 != neg2){
					if(neg1){
						ans = -1;
					}
					else ans = 1;
				}
				if(ans != 0){
					break;
				}
			}
		}	
		
		if(i == s1.size() && j < s2.size()){
			ans = -1;
		}
		else if(i < s1.size() && j == s2.size()){
			ans = 1;
		}
		
		if(ans < 0) ans = -1;
		else if(ans > 0) ans = 1;
		printf("%d %d\n", t, ans);
	}
	
	return 0;
}
