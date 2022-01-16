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
    string s; cin>> s;
    n = s.length();
    map<char,int> mp;
    for(int i = 0; i < n; i++){
        char c = s[i];
        // if(se.find(c) == se.end())
        mp[c] += 1;
    }
    vector<char> a, b;
    for(pair<char, int> p: mp){
        if(p.second == 2){
            a.push_back(p.first);
        } else b.push_back(p.first);
    }
    string ans = "";
    for(char c: a){
        ans += c;
    }
    for(char c: a){
        ans += c;
    }
    for(char c: b){
        ans += c;
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
 