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
string IntToString(ll a) 
{ 
    char x[100]; 
    sprintf(x, "%lld", a); 
    string s = x; 
    return s; 
}
int lcs(string a, string b){
    int n = a.length(), m = b.length(), c = 0, i = 0, j = 0;
    while(i < n and j < m){
        if(a[i]==b[j]){
            c++; i++; j++;
        }else i++;
    }
    cout << b << " " << c << endl;
    return a.length() - c + b.length() - c;
}


void solve(){
    string a;cin >> a;
    int ans = 200;
    unsigned long long int b = 1;
    for(int i=0; i<64; i++){
        string tmp = IntToString(b);
        ans = min(ans, lcs(a, tmp));
        b = b*2;
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
 