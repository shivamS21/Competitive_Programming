#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
#define ll long long
bool comp(ll x, ll y){
    return x > y; }
/*...............code starts here................*/
int solve(){
    int k, x, d, n, m;
    
    cin >> n >> k >> x >> d >> m;
    vector<vector<pair<int,int> > > time(n+1);


    for(int i = 0; i < m; i++){
        int p; cin >> p;
        int start, end;
        cin >> start >> end;

        time[p].push_back(make_pair(start+1, end-1));
    }

    for(int i = 0; i <= n; i++){
        sort(time[i].begin(), time[i].end());
    }

    int ans = INT_MAX;
    for(int p = 0; p <= d-x; p++){
        int start = p, end = p+x, count = 0;

        for(int i = 1; i <= n; i++){
            if(time[i].size()==0)
                ++count;
            else{
                if(end <= time[i][0].first)
                    ++count;
                else if(start >= time[i].back().second)
                    ++count;
                else{
                    
                    for(int j = 0; j < time[i].size()-1; j++){
                        int meet1start = time[i][j].first;
                        int meet1end = time[i][j].second;
                        int meet2start = time[i][j+1].first;
                        int meet2end = time[i][j+1].second;

                        if(start >= meet1end and end <= meet2start){
                            ++count;
                            break;
                        }
                            
                    }
                }
            }
        }

        if(count >= k)
            return 0;
        
        ans = min(ans, k-count);

    }
    return ans;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    for(int t = 1; t <= tt; t++){
        cout<<"Case #"<<t<<": "<<solve()<<endl;
    }
}
