#include <stdio.h>
int main(void) {
 int n, capacity, tokens, refill;
 printf("Number of packet requests: ");
 if (scanf("%d",&n)!=1 || n<=0) return 1;
 printf("Bucket capacity: ");
 if (scanf("%d",&capacity)!=1 || capacity<=0) return 1;
 printf("Initial tokens: ");
 if (scanf("%d",&tokens)!=1 || tokens<0 || tokens>capacity) return 1;
 printf("Tokens added per time unit: ");
 if (scanf("%d",&refill)!=1 || refill<0) return 1;
 for(int i=0;i<n;i++){
  int request;
  printf("Token cost of packet %d: ",i+1);
  if(scanf("%d",&request)!=1 || request<0) return 1;
  if(request<=tokens){tokens-=request;printf("Packet sent. Tokens remaining: %d\n",tokens);}
  else puts("Packet delayed/dropped: insufficient tokens.");
  tokens+=refill;if(tokens>capacity)tokens=capacity;
  printf("After refill: %d tokens\n",tokens);
 }
 return 0;
}