#include <bits/stdc++.h>

using namespace std;

#define esq(x) x + x
#define dir(x) x + x + 1

const int N = 1e5 + 10;

struct node{
  int freq[9];
  node(){
    memset(freq,0,sizeof freq);
  }
  int getFreq(){
      int old = 0;
      for(int i = 1; i < 9; i++){
          if(this->freq[i] >= this->freq[old]){
              old = i;
          }
      }
      return old;
  }
};

int add(int x){
  if(x >= 9){
    x -= 9;
  }
  return x;
}

node st[N << 2];
int lazy[N << 2];
int v[N];

node merge(const node &a, const node &b){
  
  node c;
  for(int i = 0; i < 9; i++){
    c.freq[i] = a.freq[i] + b.freq[i];
  }
  return c;
}
void propagate(int id, int l, int r){
  if(lazy[id] == 0){
    return;
  }
  node tmp = st[id];
  for(int i = 0; i < 9; i++){
    st[id].freq[add(i + lazy[id])] = tmp.freq[i];
  }
  if(l != r){
    lazy[esq(id)] = add(lazy[esq(id)] + lazy[id]);    
    lazy[dir(id)] = add(lazy[dir(id)] + lazy[id]);
  }
  lazy[id] = 0;
}

void build(int id, int l, int r){
  if(l == r){
    st[id].freq[1] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(esq(id), l, mid);
  build(dir(id), mid + 1, r);
  st[id] = merge(st[esq(id)], st[dir(id)]);
  
}

void update(int id, int l, int r, int i, int j, int x){
  propagate(id,l,r);
  if(l > j || r < i){
    return;
  }
  if(l >= i && r <= j){
    lazy[id] += x;
    propagate(id,l,r);
    return;
  }
  int mid = (l + r) >> 1;
  update(esq(id),l, mid, i, j, x);
  update(dir(id), mid + 1, r, i, j, x);
  st[id] = merge(st[esq(id)], st[dir(id)]);
}  


node query(int id, int l, int r, int i, int j){
  propagate(id,l,r);
  if(l > j || r < i){
    return node();
  }
  if(l >= i && r <= j){
    return st[id];
  }
  int mid = (l + r) >> 1;
  node a = query(esq(id),l, mid, i, j);
  node b = query(dir(id), mid + 1, r, i, j);
  return merge(a,b);
}

int main()
{
  
  int n, q;
  scanf("%d %d",&n, &q);
  
  build(1,0,n-1);
  while(q--){
    int a,b;
    scanf("%d %d",&a,&b);
    
    update(1,0,n-1,a,b,query(1,0,n-1,a,b).getFreq());
    
  }
  
  for(int i = 0; i < n; ++i){
    printf("%d\n", query(1,0,n-1,i,i).getFreq());
  }
  return 0;
}
