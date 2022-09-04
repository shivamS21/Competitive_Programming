#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    arr[n-1] = (1<<29);
    arr[n-2] = ((1<<28)^(1<<29));
    arr[n-3] = (1<<28);
    int count = 0;
    for(int i = n - 4; i >= 0; i--){
        arr[i] = (i + 2);
        if(count%2==0) arr[n - 2] = (arr[n-2]^arr[i]);
        else arr[n - 1] = (arr[n - 1]^arr[i]);
        count++;
    }
    for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << "\n";
}
int32_t main(){
    int w;
    cin >> w;
    while(w--){
        solve();
    }
}