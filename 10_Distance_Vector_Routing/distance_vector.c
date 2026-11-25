#include <stdio.h>
#define MAX 20
#define INF 99999
int main(void){
 int n,cost[MAX][MAX],dist[MAX][MAX],next[MAX][MAX];
 printf("Number of routers (max %d): ",MAX);
 if(scanf("%d",&n)!=1||n<=0||n>MAX)return 1;
 printf("Enter cost matrix (use %d for no direct link):\n",INF);
 for(int i=0;i<n;i++)for(int j=0;j<n;j++){
  if(scanf("%d",&cost[i][j])!=1)return 1;
  dist[i][j]=cost[i][j];next[i][j]=(i!=j&&cost[i][j]<INF)?j:-1;
 }
 for(int k=0;k<n;k++){
  int changed=0;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)
   if(dist[i][k]<INF&&dist[k][j]<INF&&dist[i][k]+dist[k][j]<dist[i][j]){
    dist[i][j]=dist[i][k]+dist[k][j];next[i][j]=next[i][k];changed=1;
   }
  if(!changed)break;
 }
 for(int i=0;i<n;i++){
  printf("\nRouting table for router %d\nDestination\tCost\tNext hop\n",i);
  for(int j=0;j<n;j++){
   printf("%d\t\t",j);
   if(dist[i][j]>=INF)puts("INF\t-");
   else if(i==j)puts("0\t-");
   else printf("%d\t%d\n",dist[i][j],next[i][j]);
  }
 }
 return 0;
}