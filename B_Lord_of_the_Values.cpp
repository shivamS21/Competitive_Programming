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
    vector<int> vec(n);
    rep(i,0,n) cin >> vec[i];
    vector<string> ans;
    cout<<n*3<<endl;
    for(int i=0; i < n; i+=2){
        if(vec[i+1] >= vec[i]){
            // count += 6;
            string s;
            s = "1 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i] = vec[i] + vec[i+1];
            ans.pb(s);
            s = "2 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i+1] = vec[i+1] - vec[i];
            ans.pb(s);
            s = "2 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i+1] = vec[i+1] - vec[i];
            ans.pb(s);
            s = "1 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i] = vec[i] + vec[i+1];
            ans.pb(s);
            s = "2 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i+1] = vec[i+1] - vec[i];
            ans.pb(s);
            s = "2 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i+1] = vec[i+1] - vec[i];
            ans.pb(s);
        }
        else{
            // count += 6;
            string s;
            s = "2 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i+1] = vec[i+1] - vec[i];
            ans.pb(s);
            s = "1 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i] = vec[i] + vec[i+1];
            ans.pb(s);
            s = "1 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i] = vec[i] + vec[i+1];
            ans.pb(s);
            s = "2 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i+1] = vec[i+1] - vec[i];
            ans.pb(s);
            s = "1 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i] = vec[i] + vec[i+1];
            ans.pb(s);
            s = "1 "+ to_string(i+1)+" "+to_string(i+2);
            vec[i] = vec[i] + vec[i+1];
            ans.pb(s);
        }
    }
    // cout<<count<<endl;
    for(string p: ans){
        cout<< p << endl;
    }
    // print(vec);
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 
