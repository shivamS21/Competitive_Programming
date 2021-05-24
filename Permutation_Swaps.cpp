//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define ppb pop_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define mem(v,a) 		 memset(v, a, sizeof(v))
#define M 1000000007
bool comp(ll x,ll y)
{
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
 
void solve(){
    ll m,n,k;
    cin >> n;
    vector<int>a(n+1,0);
    rep(i,1,n+1){
        cin >> a[i];
    }
    vector<int>p(n+1,0);
    rep(i,0,n){
        cin >> p[i];
    }
    int q;
    cin >> q;
    vector<int>b(n+1);
    rep(i,1,n+1){
        b[p[i]] = a[i];
    }
    int f = 0;
    while(q--){
        int no; cin >> no;
        if(no==3){
            int x; cin >> x;
            if(f==0)
            cout<<a[x]<<endl;
            else cout<<b[x]<<endl;
        }
        else if(no == 1){
            f = abs(1 - f);
        }
        else{
            int x,y,temp;
            cin >> x >> y;
            if(f==0){
                int tmp = a[x];
                a[x] = a[y];
                a[y] = tmp;

                tmp = b[p[x]];
                b[p[x]] = b[p[y]];
                b[p[y]] = tmp;
            }else{
                int tmp = b[x];
                b[x] = b[y];
                b[y] = tmp;

                tmp = a[p[x]];
                a[p[x]] = a[p[y]];
                a[p[y]] = tmp;

            }
        }
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
 
 
 
 
// g++ -std=c++17