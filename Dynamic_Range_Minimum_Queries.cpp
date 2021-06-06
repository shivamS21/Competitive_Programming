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
#define M 1000000000000
 
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
        segtree[vertex] = min(segtree[2*vertex], segtree[2*vertex+1]);
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
        segtree[vertex] = min(segtree[2*vertex], segtree[2*vertex+1]);
    }
}
ll minValue(ll segtree[], int vertex, int start, int end, int l, int r){
    if(l > r) return INT_MAX;
    if(l==start and r == end) return segtree[vertex];
    int mid = (start+end)/2;
    ll val1 = minValue(segtree, 2*vertex, start, mid, l, min(r, mid));
    ll val2 = minValue(segtree, 2*vertex+1, mid+1, end, max(mid+1, l), r);
    return min(val1, val2);
}
void solve(){
    ll m,n,k;
    cin >> n >> k;
    rep(i,0,n) cin >> arr[i];
    
    ll segtree[4*n+1] = {M};

    build(segtree, 1, 0, n-1);
    rep(i,0,k){
        int check, a, b; cin >> check >> a >> b;
        if(check == 1){
            //updation occurs
            update(segtree, 1, 0, n-1, a-1, b);
        }
        else{
            //print min value in range[a---b];
            cout << minValue(segtree, 1, 0, n-1, a-1, b-1) << endl;
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
 