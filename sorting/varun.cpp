#include<bits/stdc++.h>
using namespace std;
int cap = 0;
map<int,int> mp;
map<int,int> f;
set<pair<int,int>> pq;
vector<int> solve(int N, int Q, vector<vector<int>>&o){
    vector<int> ans;
    for(int i = 0; i < o.size(); i++){
        if(o[i][0] == 1){
            if(mp.find(o[i][1]) == mp.end())
            ans.push_back(-1);
            else ans.push_back(mp[o[i][1]]);
        } else{
            // 2
            if(mp.find(o[i][1]) != mp.end()){
                // presenet
                mp[o[i][1]] = o[i][2];
                int fre = f[o[i][1]];
                pq.erase({fre, o[i][1]});
                pq.insert({fre+1, o[i][1]});
                f[o[i][1]]++;
            } else{
                // not present
                if(pq.size() == N){
                    //removal
                    int fre = f[o[i][1]];
                    int a = (*pq.begin()).first, mn = (*pq.begin()).second;
                    mp.erase(mp.find(mn));
                    pq.insert({1, o[i][1]});
                    mp[o[i][1]] = o[i][2];
                    f[o[i][1]] = 1;
                } else{
                    mp[o[i][1]] = o[i][2];
                    pq.insert({1, o[i][1]});
                    f[o[i][1]] = 1;
                }
            }
        }
    }
    return ans;
}
int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> vec(q, vector<int>(3));
    for(int i = 0; i < q; i++){
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }
    vector<int> v = solve(n, q, vec);
    for(int ele: v) cout << ele << " ";
}