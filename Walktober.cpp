#include<bits/stdc++.h>
using namespace std;
int solve(){
    int n, m, p;
    cin >> m >> n >> p;
    int arr[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int day = 0; day < n; day++){
        //calculate maximum in that column
        int mx = 0;
        for(int row = 0; row < m; row++){
            mx = max(mx, arr[row][day]);
        }
        ans += max(0, mx-arr[p-1][day]);
    }
    return ans;
}
int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        cout<<"Case #"<<i<<": "<<solve()<<endl;
    }
}