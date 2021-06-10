//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(int i=a;i<N;i++)
#define rrep(i,a,N)     for(int i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define M 1000000007
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using cust_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// cust_set<array<int,2>> f;
bool comp(ll x,ll y){
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
 
void solve(){
    int n, l, r; cin >> n >> l >> r;
    vector<int> vec(n);
    cust_set<array<int,2>> f;
    rep(i,0,n){
        cin >> vec[i];
    }
    ll ans = 0;
    rrep(i,n-1,-1){
        int ele = vec[i];
        if(ele < l){
            int a = l - ele, b = r - ele;
            ans += f.order_of_key({b+1,0}) - f.order_of_key({a,1});
        }
        else if(ele > r){
            continue;
        }
        else{
            int a = r - ele;
            ans += f.order_of_key({a+1,0});
        }
        f.insert({vec[i],i});
    }
    cout << ans << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 