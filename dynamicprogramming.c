#include<stdio.h>
int max(int x,int y){
    return x>y?x:y;
}
int main(){
    int w,n;
    printf("enter the bag capacity");
    scanf("%d",&w);
    printf("enter no of items");
    scanf("%d",&n);
    int weight[n],profit[n];
    printf("enter the weight of each item");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&weight[i]);
    }
    printf("enter the profit of each item");
    for(int i=0;i<n;i++){
        scanf("%d",&profit[i]);
    }
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int W=0;W<=w;W++){
            if(i==0||W==0){
                dp[i][W]=0;
            }
            else if(weight[i-1]<=w)
            {
                dp[i][W]=max(dp[i-1][W],dp[i-1][W-weight[i-1]]+profit[i-1]);
            }
            else{
                dp[i][W]=dp[i-1][W];
            }
        }
    }
    printf("maximum profit = %d",dp[n][w]);
}
