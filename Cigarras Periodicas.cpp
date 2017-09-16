#include <bits/stdc++.h>

using namespace std;
#define int long long
int n,l;

int32_t main(){
  
  scanf("%d %d",&n,&l);
  long long v[n];
  
  for(int i = 0; i < n; i++){
    scanf("%lld",&v[i]);
  }
  long long x = v[0];
  for(int i = 1; i < n; i++){
    x = x * v[i] / __gcd(x, v[i]);
  }
  long long k = 1, j = 1, res = 1;
  for(int i = 0; i <= l; i++){
    k = i * x / __gcd(i, x);
    if(k <= l && k > res){
      res = k;
      j = i;
    }
  }
  printf("%d\n", j);
  return 0;
}
