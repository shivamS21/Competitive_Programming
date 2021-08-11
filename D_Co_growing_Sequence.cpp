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
vector<int> bin(ll no){
    vector<int> b(32, 0);
    ll p = pow(2, 31), chance = 31;
    while(no > 0){
        if(no >= p){
            no -= p;
            b[chance] = 1;
        } 
        p /= 2;
        chance -= 1;
    }
    // cout << no << " "; print(b);
    return b;
}
void solve(){
    ll m,n,k;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    ll y = 0;
    vector<ll> ans;
    ans.pb(y);
    rep(i,1,n){
        ll no = a[i-1] ^ y;
        vector<int> b = bin(no);
        vector<int> c = bin(a[i]);
        // print(b);
        // print(c);
        ll temp = 0;
        ll mult = 1;
        rep(k,0,31){
            int nos = 0;
            if(b[k]){
                if(c[k]) nos = 0;
                else nos = 1;
            } else{
                nos = 0;
            }
            temp = temp + nos * mult;
            mult *= 2;
        }
        // cout << i << " " << temp << endl;
        ans.pb(temp);
        y = temp;
        // cout << "halut" << endl;
    }
    print(ans);
    vector<int> x;
    rep(i,0,n){
        x.pb(a[i] ^ ans[i]);
    }
    // print(x);
    // rep(i,0,n-1) cout << (x[i] ^ x[i+1]) << " ";
    // cout << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 