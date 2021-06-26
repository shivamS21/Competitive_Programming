//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end())
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define M 1000000007
 

 
/*...............code starts here................*/
// C is first won in M
 
void solve(){
    ll m,n,k;
    cin >> n;
    vector<pair<double,double> > vec(n);
    rep(i,0,n){
        ll t;
        cin >> t >> vec[i].first >> vec[i].second;
        double &s = vec[i].first, &l = vec[i].second;
        if(t==2)
        l -= 0.001;
        else if(t==3)
        s += 0.001;
        else if(t==4){
            s += 0.001;
            l -= 0.001;
        }
    }
    sortd(vec);
    // rep(i,0,n) cout << vec[i].first << " " << vec[i].second << endl;
    ll count = 0;
    rep(i,0,n){
        double s = vec[i].first, l = vec[i].second;
        rep(j,0,n){
            if(i==j) continue;

            double maxa = max(vec[i].first,vec[j].first);
            double mina = min(vec[i].second,vec[j].second);
            if (maxa<=mina)
            count++;
        }
        // cout << "Hello";
    }
    cout << count/2 << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}