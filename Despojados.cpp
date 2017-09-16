#include <bits/stdc++.h>

using namespace std;

int main(){
  
  
  char str[10010];
  
  scanf("%s",str);
  
  int n = strlen(str);
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += (str[i] - '0');
  }
  
  printf("%d\n", sum % 3);
    
    
  return 0;
}
