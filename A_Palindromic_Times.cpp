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
int StringToInt(string a) 
{ 
    char x[100]; 
    int res; 
    strcpy(x, a.c_str()); 
    sscanf(x, "%lld", &res); 
    return res; 
}
void solve(){
    char time[5];
    string a="",b="";
    rep(i,0,2){
        char c; cin >> c;
        a += c;
    }
    char c; cin >> c;
    rep(i,0,2){
        cin >> c;
        b += c;
    }

    // cout<<a<<" " << b << endl;
    // cout<<time[0]<<time[1];
    int h = StringToInt(a);
    string t = a;
    reverse(t.begin(), t.end());
    int m = StringToInt(b);
    int x = StringToInt(t);
    // cout<<h << " " << m << endl;
    if(x > m and x < 60){
        // cout<<"YES";
        cout << a<<":"<<t;
    }
    else{
        if(a == "23"){
            cout<<"00:00";
        }
        else{
            if(a=="00"){
                cout<<"01:10";
            }
            else if(a=="01"){
                cout<<"02:20";
            }
            else if(a=="02"){
                cout<<"03:30";
            }
            else if(a=="03"){
                cout<<"04:40";
            }
            else if(a=="04"){
                cout<<"05:50";
            }
            else if(h<10){
                cout<<"10:01";
            }
            else if(h==10){
                cout<<"11:11";
            }
            else if(h==11){
                cout<<"12:21";
            }
            else if(h==12){
                cout<<"13:31";
            }
            else if(h==13){
                cout<<"14:41";
            }
            else if(h==14){
                cout<<"15:51";
            }
            else if(h<20 and h>=15){
                cout<<"20:02";
            }
            else if(h==20){
                cout<<"21:12";
            }
            else if(h==21){
                cout<<"22:22";
            }
            else if(h==22){
                cout<<"23:32";
            }
            else if(h==23){
                cout<<"00:00";
            }
        }
    }
    
}
int main() {
    // FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
        cout<<endl;
    
    }
}
 
 
 
 
// g++ -std=c++17