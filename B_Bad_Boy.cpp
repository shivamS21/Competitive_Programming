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
    ll m,n,i,j;
    cin >> n >> m >> i >> j;
    vector<pair<ll,ll> > co;
    if(n == 1 and m== 1){
        rep(x,0,2) co.pb(mk(1,1));
    }
    else if(m == 1){
        if(i == 1 and j == 1){
            co.pb(mk(n,1));
            co.pb(mk(n,1));
        }
        else if(i == n and j == 1){
            co.pb(mk(1,1));
            co.pb(mk(1,1));
        }
        else{
            co.pb(mk(1,1));
            co.pb(mk(n,1));
        }
    }
    else if(n == 1){
        if(j == 1){
            co.pb(mk(1,m));
            co.pb(mk(1,m));
        }
        else if(j == m){
            co.pb(mk(1,1));
            co.pb(mk(1,1));
        }
        else{
            co.pb(mk(1,1));
            co.pb(mk(1,m));
        }
    }
    else{
        vector<pair<ll,ll> > p;
        p.pb(mk(1,1));
        p.pb(mk(1,m));
        p.pb(mk(n,1));
        p.pb(mk(n,m));
        pair<ll,ll> temp1, temp2;
        ll d = -1;
        rep(x,0,4){
            rep(y,x+1,4){
                ll d1 = 0;
                d1 = abs(p[x].first - p[y].first) + abs(p[x].second - p[y].second);
                d1 += abs(p[x].first - i) + abs(p[x].second - j);
                d1 += abs(p[y].first - i) + abs(p[y].second - j);
                if(d1 > d){
                    temp1 = p[x];
                    temp2 = p[y];
                    d = d1;
                }
            }
        }

        // cout << d << endl;
        co.pb(temp1);
        co.pb(temp2);
    }
    rep(x,0,2)
    cout << co[x].first << " " << co[x].second << " ";
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
 