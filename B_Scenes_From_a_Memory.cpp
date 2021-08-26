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
ll StringToInt(string a) 
{ 
    char x[100]; 
    ll res; 
    strcpy(x, a.c_str()); 
    sscanf(x, "%lld", &res); 
    return res; 
}

//to check the no as prime........
bool prime(ll no)
{
    if(no < 3)
    return true;
    int factor = 0;
    for(int i=2;i*i<= no;i++)   
    {
        if(no%i == 0)
        {
            return false;
        }
    }
    return true;
}

bool check(int no){
    return (!prime(no));
} 
void solve(){
    ll m,k;
    cin >> k;
    string n; cin >> n;
    vector<char> vec = {'1', '4', '6', '8', '9'};
    for(char c: vec){
        for(int i = 0; i < k; i++){
            if(n[i] == c){
                cout << 1 << endl << c << endl;
                return;
            }
        }
    }
    cout << 2 << endl;
    for(int i = 0; i < k; i++){
        for(int j = i+1; j < k; j++){
            int s = (n[i] - '0') * 10 + (n[j] - '0');
            if(check(s)){
                cout << s << endl;
                return;
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
 