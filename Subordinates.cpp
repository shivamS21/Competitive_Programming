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
int findSubOrd(vector<int>&subOrd, vector<int>adj[], int node){
    //findSubOrd will return the no of people node has subordinates
    int count = 0;
    for(int member: adj[node]){
        count += findSubOrd(subOrd, adj, member);
    }
    return subOrd[node] = 1+count;
}
void solve(){
    ll m,n,k;
    cin >> n;
    int arr[n-1];
    vector<int> adj[n+1];
    for(int i = 0; i < n-1; i++){
        cin >> arr[i];
        adj[arr[i]].push_back(i+2);
    }
    //adj is basically containing all of it child
    vector<int> subOrd(n+1, -1);
    for(int i = 1; i <= n; i++){
        if(subOrd[i] == -1){
            //means not visited
            findSubOrd(subOrd, adj, i);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << subOrd[i] -1<< " ";
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 