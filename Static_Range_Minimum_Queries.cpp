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
void build(int seg[], int arr[], int a, int b, int index){
    if(a == b){
        seg[index] = arr[a];
        return;
    }
    int mid = (a+b)/2;
    build(seg, arr, a, mid, 2*index+1);
    build(seg, arr, mid+1, b, 2*index+2);
    seg[index] = min(seg[2*index+1], seg[2*index+2]);
}
int find_min(int seg[], int l, int r, int a, int b, int index){
    if(a > b) return INT_MAX;
    if(a == l and b == r) return seg[index];
    int mid = (l+r)/2;
    return min(find_min(seg, l, mid, a, min(mid, b), 2*index+1), find_min(seg, mid+1, r, max(a, mid+1), b, 2*index+2));
}
void solve(){
    ll m,n,q;
    cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int seg[4*n];
    
    build(seg, arr, 0, n-1, 0);
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        cout << find_min(seg, 0, n-1, a-1, b-1, 0) << endl;
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
 