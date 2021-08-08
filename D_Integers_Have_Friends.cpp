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
const int N = 200000;
bool comp(ll x,ll y){
    return x > y;
}
ll segtree[4*N];
/*...............code starts here................*/
// C is first won in M
void build(ll segtree[], vector<ll> &diff, int vertex, ll start, ll end){
    if(start == end){
        segtree[vertex] = diff[start];
        return;
    }
    int mid = (start+end)/2;
    build(segtree, diff, 2*vertex, start, mid);
    build(segtree, diff, 2*vertex+1, mid+1, end);
    segtree[vertex] = __gcd(segtree[2*vertex], segtree[2*vertex+1]);
}

ll query(ll segtree[], int vertex, int start, int end, int l , int r){
    if(l > r) return 0;
    if(start == l and end == r) return segtree[vertex];
    int mid = (start+end)/2;
    ll a = query(segtree, 2*vertex, start, mid, l, min(r, mid));
    ll b = query(segtree, 2*vertex+1, mid+1, end, max(mid+1, l), r);
    return __gcd(a, b);
}
void solve(){
    ll m,n,k;
    cin >> n;
    vector<ll> arr(n);
    rep(i,0,n){
        cin >> arr[i];
    }
    if(n==1){
        cout << 1 << endl;
        return;
    }
    vector<ll> diff(n-1);
    rep(i,0,n-1){
        diff[i] = abs(arr[i] - arr[i+1]);
    }
    build(segtree,diff, 1, 0, n-2);
    ll ans = 1;
    ll s = 0, e = 0;
    ll currgcd = diff[0];
    while(e < n-1){
        if(diff[e] == 1){
            s = ++e;
            currgcd = diff[e]; 
            continue;
        }
        ans = max(ans, e-s+2);
        if(e != n-2){
            ll temp = __gcd(currgcd, diff[e+1]);
            if(temp != 1){
                e += 1;
                currgcd = temp;
                continue;
            } 
        } 
        ++s;
        if(s > e){
            e += 1;
            currgcd = diff[s];
        } else{
            currgcd = query(segtree, 1, 0, n-2, s, e);
        }
    }
    // cout << "check: " << query(segtree, 1, 0, n-2, 2, 3) << endl;
    cout << ans<< endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 