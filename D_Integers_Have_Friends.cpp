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
const int N = 2e5+1;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
 
}
void build(int segtree[], vector<int> diff, int vertex, int start, int end){
    if(start > end) return;
    if(start == end){
        segtree[vertex] = diff[start];
        return;
    }
    int mid = (start+end)/2;
    build(segtree, diff, 2*vertex, start, mid);
    build(segtree, diff, 2*vertex+1, mid+1, end);
    segtree[vertex] = gcd(segtree[2*vertex], segtree[2*vertex+1]);
}
 
int query(int segtree[], int vertex, int start, int end, int l , int r){
    if(l > end or r < start) return 0;
    if(l > r) return 0;
    if(start == l and end == r) return segtree[vertex];
    int mid = (start+end)/2;
    int a = query(segtree, 2*vertex, start, mid, l, min(r, mid));
    int b = query(segtree, 2*vertex+1, mid+1, end, max(mid+1, l), r);
    return gcd(a, b);
}
void solve(){
    ll m,n,k;
    cin >> n;
    vector<int> arr(n);
    rep(i,0,n){
        cin >> arr[i];
    }
    vector<int> diff(n-1);
    rep(i,0,n-1){
        diff[i] = abs(arr[i] - arr[i+1]);
    }
    int segtree[4*N];
    build(segtree,diff, 1, 0, n-2);
    int answer = 1;
    int s = 0;
    int e = 0;
    int currGcd = diff[s];
    while(e<n-1){
        if(abs(diff[e]) == 1){
            s = e +1;
            e = s;
            currGcd = diff[e];
            continue;
        }
        answer = max(answer,e-s+2);
        // dp we extend
        if(e!=n-2){
            if(abs(__gcd(currGcd,diff[e+1]))!=1){
                currGcd = __gcd(currGcd,diff[e+1]);
                e++;
                continue;
            }
        }
        // we shrink
        s++;
        if(s>e){
            e++;
            if(e == n-1) break;
            currGcd = diff[s];
        }else{
            currGcd = query(segtree, 1, 0, n-2, s, e);
        }


    }
    // cout << "check: " << query(segtree, 1, 0, n-2, 2, 3) << endl;
    cout << answer<< endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 