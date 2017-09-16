#include <bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  
  int x = a * 2 + c * 2;
  int y = a * 4 + b * 2;
  int z = b * 2 + c * 4;
  printf("%d\n", min(x,min(y,z)));

  return 0;
}
