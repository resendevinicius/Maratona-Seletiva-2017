#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int v[N];
vector<pair<int,int> > G[N];
int capacidade;
int n;

pair<int,int> dfs(int x, int dad, int cost){
  
  int ans = 0;

  for(int i = 0; i < G[x].size(); ++i){
    int y = G[x][i].first, c = G[x][i].second;
    
    if(y != dad){
      pair<int,int> k = dfs(y,x,c * 2);
      ans += k.first;
      v[x] += k.second;
    }
  }
  return make_pair(ans + (cost * (ceil(v[x] / (double) capacidade))), v[x]);
}

int main(){
  
  scanf("%d %d",&n,&capacidade);
  
  for(int i = 0; i < n; i++){
    scanf("%d",&v[i]);
  }
  
  for(int i = 0; i < n - 1; i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a--; b--;
    G[a].push_back(make_pair(b,c));
    G[b].push_back(make_pair(a,c));
    
  }

  printf("%d\n", dfs(0,-1,0).first);
  
  return 0;
}
