#include<stdio.h>
#define MAX_N 200000
int par[MAX_N];
int original_par[MAX_N];
int rank[MAX_N];
int query_list[MAX_N][2];

void init(int n){
  int i;
  for(i=0;i<n;i++){
    par[i] = i;
    rank[i] = 0;
  }
}
int find(int x){
  if(par[x]==x){
    return x;
  }else {
    return par[x] = find(par[x]);
  }
}
void unite(int x,int y){
  x =find(x);
  y =find(y);
  if(x==y){
    return ;
  }
  par[y] = x;
  if(rank[x] < rank[y]){
    par[x] = y;
  }else {
    par[y] = x;
    if(rank[x] == rank[y])rank[x]++;
  }
}
int same(int x,int y){
  return find(x)==find(y);
}
void print_par(int N){
  for(int i = 0; i < N; i++){
    printf("%d ", par[i]);
  }
  printf("\n");
}
int main(){
  int N,Q;
  long long int ans;
  int i,j,k;
  int marked_list[MAX_N];
//??¨??¨????????§?????????????????§1?????¬???
  while(1){
    scanf("%d %d",&N,&Q);
    if(N==0&&Q==0)break;
    for(i=0;i<N;i++){
      marked_list[i]=0;
    }
    marked_list[0]=1;
    original_par[0]=0;
    ans=0;

    for(i=1;i<N;i++){
      scanf("%d\n",&original_par[i]);
      original_par[i]--;
    }
    for(i=0;i<Q;i++){
      char bc;
      scanf("%c %d\n",&bc,&query_list[i][1]);
      query_list[i][0] = bc;
      query_list[i][1]--;
    }

    init(N);
    for(i=0;i<Q;i++){
      if(query_list[i][0]=='M'){
                if(marked_list[query_list[i][1]]==1){
                    query_list[i][0]='N';
                }
        marked_list[query_list[i][1]]=1;
      }
    }
    for(i=0;i<N;i++){
      if(0==marked_list[i]){
        print_par(N);
        unite(original_par[i],i);
      }
    }
    print_par(N);
    for(i=Q-1;i>=0;i--){
      if(query_list[i][0]=='Q'){
        int q_a = find(query_list[i][1])+1;
        ans += q_a;
        printf(":%lld\n",ans);
        print_par(N);
      }else if(query_list[i][0]=='M'){
        int m = query_list[i][1];
        unite(original_par[m],m);
      }
    }
    printf("%lld\n",ans);
  }
  return 0;

}
