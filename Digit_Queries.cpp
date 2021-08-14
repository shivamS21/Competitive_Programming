#include <cmath>
#include<bits/stdc++.h>
using namespace std;
long long int power(long long int x,long long int n){
    // if(n == 0) return 1;
    if(n==1)
    return x;
    if(n%2==0){
        long long int res=power(x,n/2);
        return res*res;
    }
    else{
        long long int res=power(x,n/2);
        return res*res*x;
    }
}
int main(){
    long long int q;
    cin>>q;
    for(long long int i=0;i<q;i++){
        long long int p=9,sum=9,j=2,ps=9,digit,f_num;
        cin>>digit;
        while(sum<=digit){
            p=p*10;ps=p*j;sum+=ps;
        j++;
        }
        digit=digit-(sum-ps);
        long long int num=(digit/(--j));
        f_num=power(10,j-1)+num-1;
        digit=digit-num*j;
        if(digit==0){
            cout<<(f_num%10)<<endl;
        }
        else{
            ++f_num;
            cout<<to_string(f_num)[digit-1]<<endl;
        }
    }
    return 0;
}