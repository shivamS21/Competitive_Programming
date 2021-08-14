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
ll best(int start, int end, vector<ll> &a, ll n, int check){
    if(start > end) return 0;
    // if(start == n-1) return a[n-1];
    // if(end == 0) return a[0];
    ll x = 0;
    ll d = 0;
    if(check == 0){
        rrep(i,end, start-1){
            d += a[i];
            x = max(x, d);
        }
    } else{
        rep(i,start, end+1){
            d += a[i];
            x = max(x, d);
        }
    }
    return x;
}
ll maxSubArraySum(vector<ll> &a, int size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
void solve(){
    ll m,n,k,q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i,0,n) cin >> a[i];
    rep(j,0,n) cin >> b[j];
    vector<ll> suff(n+1), pre(n+1);
    ll global = 0;
    rep(i,0,n){
        pre[i] = max(0ll, global + a[i]);
        global = pre[i];
    }
    global = 0;
    rrep(i,n-1,-1){
        suff[i] = max(0ll, global + a[i]);
        global = suff[i];
    }
    ll ans = maxSubArraySum(a, n);
    rep(i,0,n){
        ll p , s;
        if(i == 0){
            p = 0;
            if(i != n-1)
            s = suff[i+1];
            else s = 0;
        } else if(i == n-1){
            if(i != 0)
            p = pre[i-1];
            else p = 0;
            s = 0;
        } else{
            p = pre[i -1];
            s = suff[i+1];
        }
        // cout << p << " " << s << " " << a[i
        ans = max(ans, p+s+max(a[i], a[i]+q*b[i]));
    }
    cout << max(ans, ll(0)) << endl;
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 