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
    vector<int> vec(n);
    rep(i,0,n) cin >> vec[i];
    sortd(vec);
    int count = 0;
    int even = 0, odd = 0;
    vector<int> o;
    rep(i,0,n){
        if(vec[i]%2){
            ++odd;
            o.pb(vec[i]);
        }
        else ++even;
    }
    count += odd * even;
    if(even > 1){
        count += (even*(even-1))/2;
    }
    
    rep(i,0,o.size()){
        rep(j,i+1,o.size()){
            if(__gcd(o[i], o[j]) > 1)
            ++count;
        }
    }
    cout << count << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 