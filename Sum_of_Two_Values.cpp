//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define M 1000000007
#include<unordered_map>
bool comp(ll x,ll y){
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
 
void solve(){
    ll m,n,k;
    cin >> n >> k;
    unordered_map<int,int> mp;
    int arr[n];
    rep(i,0,n) cin >> arr[i];
    rep(i,0,n){
        mp[arr[i]] += 1;
    }
    rep(i,0,n){
        if(mp.find(k - arr[i])!=mp.end()){
            if(arr[i] != k-arr[i]){
                cout << arr[i] << endl;
                return;
            }
            else if(mp[arr[i]] > 1){
                cout << arr[i] << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 