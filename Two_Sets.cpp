#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
#define ll long long
bool comp(ll x, ll y){
    return x > y; }
/*...............code starts here................*/
void solve(){
    ll n; cin >> n;
    if((n*(n+1))%4){
        cout<<"NO";
        return;
    }
    cout<<"YES"<<endl;
    vector<ll>arr1, arr2;
    ll sum = (n*(n+1))/4;
    for(ll i = n; i>0;i--){
        if(sum >= i){
            arr1.push_back(i);
            sum -= i;
        } else{
            arr2.push_back(i);
        }
    }
    cout<<arr1.size()<<endl;
    for(ll ele: arr1) cout<<ele<<" "; cout<<endl;
    cout<<arr2.size()<<endl;
    for(ll ele: arr2) cout<<ele<<" ";cout<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
