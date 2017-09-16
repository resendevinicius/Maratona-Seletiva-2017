#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int primo[N];
vector<int> v;
void crivo(){
  
  for(int i = 2; i < N; i++){
    if(!primo[i]){
      for(int j = i; j < N; j += i){
        primo[j] = 1;
      }
      v.push_back(i);
    }
  }
}

int main(){
  crivo();
  long long int x;
  scanf("%lld",&x);
  set<int> fat;
  int i = 0;
  
  while(x > 1 && i < v.size()){
    if(x % v[i] == 0){
      x /= v[i];
      fat.insert(v[i]);
    } else{
      i++;
    }
  }
  int n = fat.size();
  if(i >= v.size() && x > 1){
   n++; 
  }
  printf("%d\n", (1 << n) - n - 1);
  return 0;
}

