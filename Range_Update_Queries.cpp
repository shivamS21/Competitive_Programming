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
void update(ll seg[], int index, int start, int end, int post, ll value){
    if(start == end){
        seg[index] += value;
        return;
    }
    int mid = (start + end)/2;
    if(post <= mid)
    update(seg, 2*index, start, mid, post, value);
    else update(seg, 2*index+1, mid+1, end, post, value);
    seg[index] = seg[2*index]+seg[2*index+1];
} 
ll rangesum(ll seg[], int index, int start, int end, int l, int r){
    if(l > r) return 0;
    if(start == l and end == r)
    return seg[index];
    int mid = (start+end)/2;
    ll sum1 = rangesum(seg, 2*index, start, mid, l, min(r, mid));
    ll sum2 = rangesum(seg, 2*index+1, mid+1, end, max(mid+1, l), r);
    return sum1 + sum2;
}
void solve(){
    ll m,n,k;
    cin >> n >> k;
    ll arr[n];
    rep(i,0,n) cin >> arr[i];
    ll seg[4*n+10]={0};

    rep(i,0,k){
        int check; cin >> check;
        if(check == 1){
            int a, b; ll u; cin >> a >> b >> u;
            update(seg, 1, 0, n, a-1, u);
            update(seg, 1, 0, n, b, -u);
        }
        else{
            int v; cin >> v;
            cout << arr[v-1] + rangesum(seg, 1, 0, n, 0, v-1) << endl;
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
 