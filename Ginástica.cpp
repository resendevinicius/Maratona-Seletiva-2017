#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

int pd[51][(int) 1e5];
int a,b,c;
int f(int i, int j){
  if(i >= a){
    return 1;
  }
  
  if(j < b || j > c) {
    return 0;
  }
  
  int &p = pd[i][j];
  if(p != -1) return p;
  
  p = f(i + 1,j + 1) % mod;
  p = (p + f(i + 1, j - 1)) % mod;
  
  return p;
}



int main()
{
  
  scanf("%d %d %d",&a,&b,&c);
  
  int ans = 0;
  memset(pd,-1,sizeof pd);
  for(int i = b; i < c; i++){
    ans = (ans + f(1,i)) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
