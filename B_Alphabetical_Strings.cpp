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
    string s; cin >> s;
    n = s.length();
    int post = -1;
    set<char> se;
    rep(i,0,n){
        if(s[i] == 'a')
        post = i;
        se.insert(s[i]);
    }
    char temp = 'a';
    for(char c: se){
        if(c != temp){
            cout << "NO" << endl;
            return;
        }
        temp += 1;
    }
    if(se.size() != n) cout << "NO";
    else{
        rrep(i,post-1,-1){
            if(s[i] < s[i+1]){
                cout << "NO" << endl;
                return;
            }
        }
        rep(i,post+1, n){
            if(s[i] < s[i-1]){
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES";
    }
    cout << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 