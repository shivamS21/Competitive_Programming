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
    cin >> n >> k;
    vector<pair<ll,ll> > arr(n);
    map<ll,ll> mp;
    rep(i,0,n){
        cin >> arr[i].first;
        arr[i].second = i;
        mp[arr[i].first] += 1;
    }
    sorta(arr);
    vector<int> post(n,0);
    int i=0, no = 1;
    while(i < n){
        if(mp[arr[i].first] >= k){
            int count = 1;
            rep(j,i,i+k) {
                post[arr[j].second] = count;
                ++count;
            }
            i += mp[arr[i].first];
        } else{
            rep(j,i,i+mp[arr[i].first]) {
                post[arr[j].second] = no;
                no = (no)%k+1;
            }
            i += mp[arr[i].first];
        }
    }
    // print(post);
    vector<int> c(k+1, 0);
    rep(i,0,n){
        if(post[i])
        c[post[i]] += 1;
    }
    // print(c)
    int mn = n+1;
    rep(i,1,k+1){
        if(c[i]) mn = min(mn, c[i]);
    }
    rep(i,0,k+1){
        c[i] = 0;
    }
    // cout << mn << endl;
    rep(i,0,n){
        if(c[post[arr[i].second]] < mn ) c[post[arr[i].second]]  += 1;
        else post[arr[i].second] = 0;
    }
    print(post);
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 