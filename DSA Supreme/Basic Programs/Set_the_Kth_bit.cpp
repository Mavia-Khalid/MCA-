#include<iostream>
using namespace std;
void set_Kth_Bit(int n,int k){
    int ans = 1<<k; // First left shift 1 by items
    ans = ans | n; // Bitwise OR is used as if any of the bit is 1, output will be 1
    cout<<ans<<endl;
}
int main(){
    int n = 10;
    int k=2;
    set_Kth_Bit(n,k);
    return 0;
}