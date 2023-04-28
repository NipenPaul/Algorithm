int p[305]; // initially p[i] = i;
int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b){
    p[Find(b)] = Find(a);
}

int main(){
  for(int i = 0; i < n; i++){
    p[i] = i;
  }
  int ans = n;
 if(Find(i) != Find(j)){
    ans--;
    Union(i, j);
  } 
  reuturn 0;
}
