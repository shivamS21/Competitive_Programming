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
void update(ll seg[], ll index, ll start, ll end, ll post, ll value){
    if(start == end) seg[index] += value;
    else{
        ll mid = (start+end)/2;
        if(post <= mid)
        update(seg, 2*index, start, mid, post, value);
        else update(seg, 2*index+1, mid+1, end, post, value);
        seg[index] = seg[2*index+1] + seg[2*index];
    }
}
ll rangesum(ll seg[], ll index, ll start, ll end, ll l, ll r){
    if(l > r) return 0;
    if(l == start and r == end) return seg[index];
    ll mid = (start+end)/2;
    ll sum1 = rangesum(seg, 2*index, start, mid, l, min(r, mid));
    ll sum2 = rangesum(seg, 2*index+1, mid+1, end, max(l, mid+1), r);
    return sum1+sum2;
}
void solve(){
    ll m,n,k;
    cin >> n >> k;
    ll arr[n];
    for(ll i = 0; i < n; i++) cin >> arr[i];
    ll seg[4*n+10];
    memset(seg, 0, sizeof(seg));
    for(ll i = 0; i < k; i++){
        ll check; cin >> check;
        if(check == 1){
            ll a, b, u;
            cin >> a >> b >> u;
            update(seg, 1, 0, n, a-1, u);
            update(seg, 1, 0, n, b, -u);
        } else{
            ll q; cin >> q;
            cout << arr[q-1] + rangesum(seg, 1, 0, n, 0, q-1) << endl;
        }
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
 