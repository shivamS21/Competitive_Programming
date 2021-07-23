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
    string s, t;
    cin >> s >> t;
    n = s.length();
    m = t.length();
    vector<int> post;
    rep(i,0,n){
        if(s[i] == t[0])
        post.pb(i);
    }
    for(int x: post){
        int len = n - x;
        // cout << "x " << x << endl;
        rep(j, 1, m+1){
            if(j > len) break;
            string a, b;
            a = s.substr(x, j);
            b = t.substr(0, j);
            if(a != b) break;
            int y = m - j;
            int av = x + j - 1;
            if(y > av) continue;
            string c, d;
            c = t.substr(j, y);
            d = s.substr(x+j-1-y, y);
            reverse(d.begin(), d.end());
            if(c == d){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 