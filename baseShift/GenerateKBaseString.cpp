#include<bits/stdc++.h>
using namespace std;
 
#define int long long

vector<int>Kth_Based_Number(int n, int k){
    vector<int>reversed_v;
    while(n>0){
      int remainder = n%k;
      reversed_v.push_back(remainder);
      n/=k;
    }
    vector<int>real_v;
    for(int i = reversed_v.size()-1; i>=0; i--){
        real_v.push_back(reversed_v[i]);
    }
    return real_v;

}

int32_t main(){
    int n = 3620, k = 3;

    //generating k base number
    
    vector<int>k_base_num = Kth_Based_Number(n,k);

    for(auto& el: k_base_num){
        cout<<el;
    }
    return 0;
}