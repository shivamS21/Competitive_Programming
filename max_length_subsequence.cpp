#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    cin >> arr[i];
    pair<int,int> dp[n][2];
    // 0 -> positive
    // 1 -> negative
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            dp[i][1] = {arr[i], 1};
            dp[i][0] = {-1e7, 0};
        } else{
            dp[i][0] = {arr[i], 1};
            dp[i][1] = {-1e7, 0};
        }
        for(int j = 0; j < i; j++){
            if(arr[i] < 0 and arr[j] >= 0){
                int current = dp[j][0].first + arr[i];
                if(current > dp[i][1].first){
                    dp[i][1] = {current, dp[j][0].second+1};
                } else if(current == dp[i][1].first){
                    dp[i][1].second = max(dp[i][1].second, dp[j][0].second+1);
                }
            }
            else if(arr[i] >= 0 and arr[j] < 0){
                int current = dp[j][1].first + arr[i];
                if(current > dp[i][0].first){
                    dp[i][0] = {current, dp[j][1].second+1};
                } else if(current == dp[i][0].first){
                    dp[i][0].second = max(dp[i][0].second, dp[j][1].second+1);
                }
            }
        }
    }
    int mxSum = 0;
    for(int i = 0; i <n; i++){
        if(arr[i] >= 0)
        mxSum =  max(mxSum, dp[i][0].first);
        else mxSum = max(mxSum, dp[i][1].first);
    }
    cout << mxSum << endl;
}