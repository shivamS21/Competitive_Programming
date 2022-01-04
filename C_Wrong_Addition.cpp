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
    string s, a, b=""; cin >> a >> s;
    int i, j;
    for( i = s.length()-1, j = a.length()-1; i > -1 && j > -1; i--,j--){
        int x = s[i] - '0';
        int y = a[j] - '0';
        if(x >= y){
            b = to_string(x-y)+b;
        } 
        else{
            int z = 10+ x - y;
            z = z % 10;
            b = to_string(z) + b;
            i--;
            if(s[i] != '1'){
                // cout << i << " " << s[i] << endl;
                cout << -1 << endl;
                return;
            }
        }
        // cout << x << " " << y << " " << b << endl;
    }
    while(i > -1){
        b = s[i]+b;
        --i;
    }
    i = 0;
    while(i < b.length() && b[i] == '0'){
        ++i;
    }
    if(j == -1){
        for(;i < b.length(); i++) cout << b[i];
        cout << endl;
    }
    else cout << -1 << endl;
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 