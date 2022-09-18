#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool comp1(vector<ll>&a, vector<ll>&b){
    if(a[1] != b[1])
        return a[1] > b[1];
    
    return a[2] > b[2];
}
bool comp2(vector<ll>&a, vector<ll>&b){
    if(a[2] != b[2])
        return a[2] > b[2];
    
    return a[1] < b[1];
}
ll d, n, x;
ll findAnswer(vector<vector<ll> > &arr){
    ll ans = 0, i = 0, day = 1;
    while(i < n and day < d){
        ll &seeds = arr[i][0];
        if(seeds<1)
        i++;
        ll days = arr[i][1];
        ll value = arr[i][2];

        if(seeds > x){
            //I can move forward to next day
            if(days+day <= d){
                ans += x * value;
                seeds -= x;
                day++;
            } else
                i++;
        } else{
            if(days+day <= d){
                ans += seeds * value;
            }
            if(seeds==x)
                day++;
            i++;
        }
        // cout << day << " " << ans << endl;
    }
    return ans;
}
ll solve(){
    
    cin >> d >> n >> x;
    vector<vector<ll> > arr(n, vector<ll>(3, 0));
    for(int i = 0; i < n; i++){
        //Qi, Li, Vi
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    sort(arr.begin(), arr.end(), comp1);
    int ans1 = findAnswer(arr);
    sort(arr.begin(), arr.end(), comp2);
    int ans2 = findAnswer(arr);
    return max(ans1, ans2);
}
int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #"<<i<<": "<<solve()<<endl;
    }
}