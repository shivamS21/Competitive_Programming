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
    cin >> n;
    vector<int> a(n);
    map<int,int> b;
    bool flag = 0;
    rep(i,0,n){
        cin >> a[i];
        b[a[i]] += 1;
        if(b[a[i]]>1) flag = 1;
    }
    if(n ==1){
        if(!a[0]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    if(flag){
        cout << "YES" << endl;
        return;
    }
    rep(i,0,n){
        rep(j,i+1,n){
            if(i != j){
                int no = a[i]-a[j];
                if(b[no]>0 or b[-1*no] > 0){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) break;
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 