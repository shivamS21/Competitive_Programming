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
int arr[200005];
vector<int>ans;
void update(int seg[], int vertex, int start, int end, int pos, int val){
    if(start == end)
    seg[vertex] = val;
    else{
        int mid = (start+end)/2;
        if(pos <= mid)
        update(seg, 2*vertex, start, mid, pos, val);
        else update(seg, 2*vertex+1, mid+1, end, pos, val);
        seg[vertex] = seg[2*vertex+1] + seg[2*vertex];
    }
} 
int sum(int seg[], int vertex, int start, int end, int l, int r){
    if(l > r) return 0;
    if(start == l and end == r) return seg[vertex];
    int mid = (start + end)/2;
    ll s1 = sum(seg, 2*vertex, start, mid, l, min(mid, r));
    ll s2 = sum(seg, 2*vertex+1, mid+1, end, max(mid+1,l), r);
    return s1 + s2;
}
void bsearch(int seg[], int no, int n){
    int a = 0, b = n-1;
    while(a < b){
        int mid = (a+b)/2;
        int one = sum(seg, 1, 0, n-1, 0, mid);
        int empty = mid+1-one;
        if(empty >= no)
        b = mid;
        else a = mid+1;
    }
    ans.pb(arr[a]);
    update(seg, 1, 0, n-1, a,1);
}
void solve(){
    ll m,n,k;
    cin >> n;
    rep(i,0,n) cin >> arr[i];
    int seg[4*n]={0};
    rep(i,0,n){
        int post; cin >> post;
        bsearch(seg,post,n);
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
 