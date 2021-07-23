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
 
bool comp(ll x,ll y){
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
 
void solve(){
    ll m,n,k;
    cin >> n;
    vector<pair<ll, int> > arr(n);
    rep(i,0,n){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sorta(arr);
    ll sum = 0;
    rep(i,0,n) {
        sum += arr[i].first;
    }
    map<int,int> mp;
    cout << sum << endl;
    rep(i,0,n){
        int high;
        if(i != n-1)
        high = arr[n-1].first;
        else if(i != 0)
        high = arr[n-2].first;
        cout << high << " " << sum - arr[i].first << endl;
        if(sum - arr[i].first == 2*high)
        mp[arr[i].first] = arr[i].second;
    }
    cout << mp.size() << endl;
    for(pair<int,int> it: mp){
        cout << it.second << " ";
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 