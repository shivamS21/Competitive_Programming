#include<bits/stdc++.h>
using namespace std;
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main(){
    FAST_FURIER;
    int n, m; 
    cin >> n >> m;
    int dp[n+10][32];
    for(int i = 0; i < n; i++){
        cin >> dp[i][0];
        --dp[i][0];
    }
    //dp[i][j] = the jth parent of ith node.
    for(int i = 1; i < 32; i++){
        for(int j = 0; j < n; j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    for(int j = 0; j <m; j++){
        int a, b; cin >> a >> b;--a;
        //bth parent of a
        for(int i = 0; i < 32; i++){
            if((1<<i)&b){
                a = dp[a][i];
                b = b ^ (1<<i);
            }
            if(!b) break;
        }
        cout<<a+1<<endl;
    }
}