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
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int b, int a, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(b), abs(a), x0, y0);
    // cout << "g " << g << endl;
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    return true;
} 
void solve(){
    ll m,n,k,a,b;
    cin >> n >> a >> b;
    if(a==1){
        if((n -a) % b == 0) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    else{   
        ll x=1, check = 1;
        while(x<=n){
            if((n-x)%b==0){
                check = 0;
                break;
            }
            x *= a;
        }
        if(!check) cout<<"Yes"<<endl;
        else{
            cout<<"No"<<endl;
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
 