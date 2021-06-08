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
const int N  = 2e5+10;
ll arr[N];
void build(ll segtree[], int vertex, int a, int b){
    if(a==b) segtree[vertex] = arr[a];
    else{
        int mid = (a+b)/2;
        build(segtree, 2*vertex, a, mid);
        build(segtree, 2*vertex+1, mid+1, b);
        segtree[vertex] = max(segtree[2*vertex], segtree[2*vertex+1]);
    }
}
void update(ll segtree[], int vertex, int start, int end, int pos, int val){
    if(start == end) segtree[vertex] = val;
    else{
        int mid = (start+end)/2;
        if(pos <= mid){
            update(segtree, 2*vertex, start, mid, pos, val);
        }
        else update(segtree, 2*vertex+1, mid+1, end, pos, val);
        segtree[vertex] = max(segtree[2*vertex], segtree[2*vertex+1]);
    }
}
ll maxValue(ll segtree[], int vertex, int start, int end, int l, int r){
    if(l > r) return -1;
    if(l==start and r == end) return segtree[vertex];
    int mid = (start+end)/2;
    ll val1 = maxValue(segtree, 2*vertex, start, mid, l, min(r, mid));
    ll val2 = maxValue(segtree, 2*vertex+1, mid+1, end, max(mid+1, l), r);
    return max(val1, val2);
}
vector<int>ans;
void bsearch(ll segtree[], ll n){
    ll m; cin >> m;
    int a = 0, b = n-1;
    while(a < b){
        int mid = (a+b)/2;
        ll mx1 = maxValue(segtree, 1, 0, n-1, a, mid);
        if(mx1 >= m)
        b = mid;
        else a = mid+1;
    }
    // cout << "index " << a << endl;
    if(a == n-1 and arr[a] < m)
    ans.pb(0);
    else{
        ans.pb(a+1);
        update(segtree, 1, 0, n-1, a, arr[a] - m);
        arr[a] -= m;
    }
}
void solve(){
    ll m,n,k;
    cin >> n >> k;
    rep(i,0,n) cin >> arr[i];
    ll segtree[4*n] = {-1};

    build(segtree, 1, 0, n-1);
    rep(i,0,k){
        bsearch(segtree, n);
    }
    print(ans);
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 