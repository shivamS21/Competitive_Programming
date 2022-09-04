#include <iostream>
using namespace std;
int main(){
    int count = 101;
int ans = 0;
while(--count){
    ++ans;
    count--;
}
cout << ans << endl;
}