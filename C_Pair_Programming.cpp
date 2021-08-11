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
 
void solve(){
    ll m,n,k;
    cin >> k >> n >> m;
    vector<int> a(n), b(m);
    rep(i,0,n) cin >> a[i];
    rep(j,0,m) cin >> b[j];
    vector<int> ans;
    int i =0, j = 0;
    while(i < n and j < m){
        while(i < n and !a[i]){
            ans.pb(0);
            ++i;
            ++k;
        }
        while(j < m and !b[j]){
            ans.pb(0);
            ++j;
            ++k;
        }
        if(i < n and j < m){
            if(a[i] <= b[j]){
                if(a[i] <= k)
                ans.pb(a[i]);
                else{
                    cout << -1 << endl;
                    return;
                }
                i++;
            }
            else{
                if(b[j] <= k)
                ans.pb(b[j]);
                else{
                    cout << -1 << endl;
                    return;
                }
                j++;
            }
        }
        else if(i < n){
            if(a[i] > k){
                cout << -1 << endl;
                return;
            } else{
                ans.pb(a[i]);
                ++i;
            }
        }
        else if(j < m){
            if(b[j] > k){
                cout << -1 << endl;
                return;
            } else{
                ans.pb(b[j]);
                ++j;
            }
        }
    }
    // cout << "YES";
    // cout << "size " << k << " " << i << " " << j << endl;
    while(i < n){
        if(a[i] != 0){
            if(a[i] <= k){
                ans.pb(a[i]);
                ++i;
            } else{
                cout << -1 << endl;
                return;
            }
        }
        else{
            ans.pb(0);
            ++k;
            ++i;
        }
    }
    while(j < m){
        if(b[j] != 0){
            if(b[j] <= k){
                ans.pb(b[j]);
                ++j;
            } else{
                cout << -1 << endl;
                return;
            }
        }
        else{
            ans.pb(0);
            ++k;
            ++j;
        }
    }
    print(ans);
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 