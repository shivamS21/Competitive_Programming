#include<bits/stdc++.h>
using namespace std;
long long big = pow(2, 31);
long long formno(vector<int> &arr){
    long long ans = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i])
        ans += pow(2, 31-i);
    }
    return ans;
}
long long solve(long long l, long long r){
    int i = 0, flag = 0, index = -1;
    long long temp = r, bigtemp = big;
    while(temp > 0){
        if(temp >= bigtemp){
            temp -= bigtemp;
            flag = 1;
            index = i;
            break;
        }
        bigtemp/=2;
        i++;
    }
    if(!flag) return 0;
    long long ans = 0;
    for(int x = index; x < 31; x++){
        vector<int> arr(32, 1);
        for(int j = 0; j < index; j++){
            arr[j] = 0;
        }
        arr[x] = 0;
        // for(int j = 0; j < 32; j++){
        //         cout << j << " " << arr[j] << " )";
        //     }
        //     cout << endl;
        for(int y = x+1; y < 32; y++){
            arr[y] = 0;
            long long no = formno(arr);
            // cout << no << endl;
            if(no >= l && no <= r) ++ans;
            // cout << x << " " << y << endl;
            // for(int j = 0; j < 31; j++){
            //     cout << arr[j] << " ";
            // }
            // cout << endl;
            arr[y] = 1;
        }
        arr[x] = 1;
    }
    return ans;
}
int main(){
    int t; cin >> t;
    while(t--){
        long long l, r; cin >> l >> r;
        cout << solve(l, r) << endl;
    }
} 