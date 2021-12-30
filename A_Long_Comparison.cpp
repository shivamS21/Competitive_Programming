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
    ll x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    ll n1 = 0, n2 = 0, tempx1 = x1, tempx2 = x2;
    while(tempx1 != 0){
        ++n1;
        tempx1 /= 10;
    }
    while(tempx2 != 0){
        ++n2;
        tempx2 /= 10;
    }
    if(n1-1+p1 > n2-1+p2)cout<<">";
    else if(n1-1+p1 < n2-1+p2) cout << "<";
    else{
        if(p1 > p2){
            double x = (double)x2 / (double)(pow(10, (p1-p2)));
            if(x1 > x) cout<<">";
            else if(x1 < x) cout<<"<";
            else cout<<"=";
        }
        else if(p1 != p2){
            double x = (double)x1 / (double)(pow(10, (p2-p1)));
            if(x2 > x) cout<<"<";
            else if(x2 < x) cout<<">";
            else cout<<"=";
        } else{
            if(x1 > x2) cout << ">";
            else if(x1 < x2) cout << "<";
            else cout << "=";
        }
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
 