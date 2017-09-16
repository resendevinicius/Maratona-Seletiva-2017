#include <bits/stdc++.h>

using namespace std;

int main()
{
  
  int n, k;
  scanf("%d %d",&n,&k);
  vector<int> v;
  for(int i = 0; i < n; i++){
    int x;
    scanf("%d",&x);
    v.push_back(x);
  }
  
  sort(v.rbegin(), v.rend());
  
  int res = k;
  int i = k;
  while(v[k - 1] == v[i] && i < v.size()){
    res++;
    i++;
  }
  
  printf("%d\n", res);
  
  
  return 0;
}
