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
   ll a,b,c; cin >> a >> b >> c;
   int arr[7] = {0,1,2,0,2,1,0};
   ll ans = 0;
   rep(i,0,7){
       //i = 0 denotes that I start the day from monday.
        ll count = 0;
        ll aa =a , bb = b, cc = c;
        rep(j,i,7){
            if(arr[j]==0){
                if(aa>0){
                    ++count; 
                    aa -= 1;
                }
                else break;
            }
            else if(arr[j]==1){
                if(bb>0){
                    ++count;
                    bb -= 1;
                }
                else break;
            }
            else{
                if(cc>0){
                    ++count;
                    cc -= 1;
                }
                else break;
            }
        }
        vector<ll> days;
        days.pb((aa/3));
        days.pb((bb/2));
        days.pb((cc/2)); 
        sorta(days);
        count += 7 * days[0];
        aa -= 3 * days[0];
        bb -= 2 * days[0];
        cc -= 2 * days[0];
        rep(j,0,7){
            if(arr[j]==0){
                if(aa>0){
                    ++count; 
                    aa -= 1;
                }
                else break;
            }
            else if(arr[j]==1){
                if(bb>0){
                    ++count;
                    bb -= 1;
                }
                else break;
            }
            else{
                if(cc>0){
                    ++count;
                    cc -= 1;
                }
                else break;
            }
        }
        ans = max(ans, count);
        // cout << count << " ";
   }
   cout << ans << endl;
}

int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 