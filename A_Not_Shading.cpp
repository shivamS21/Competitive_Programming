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
    ll m,n,k,r,c;
    cin >> n >> m >> r >> c;
    vector<string> vec(n+1);
    for(int i =0; i < n; i++){
        cin >> vec[i+1];
        vec[i+1] = ' '+vec[i+1];
    }
    if(vec[r][c] == 'B') cout << 0 << endl;
    else{
        for(int i = 1;i <= m; i++){
            if(vec[r][i] == 'B'){
                cout << 1 << endl;
                return;
            }
        }
        for(int i = 1; i <= n; i++){
            if(vec[i][c] == 'B'){
                cout << 1 << endl;
                return;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(vec[i][j] == 'B'){
                    cout << 2 << endl;
                    return;
                }
            }
        }
        cout << -1 << endl;
    }

}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 