#include<bits/stdc++.h>
using namespace std;
 
#define int long long

long long power(long long a, long long b)
{
    long long result = 1;
    while (b) {
        if (b & 1)
            result = (result * a);
        a = (a * a);
        b >>= 1;
    }
    return result;
}

int Min_Num(int n, int k){
    int maximum_exp = ceil(log(n)*1.0/log(k));
    int minimum_num = power(k,maximum_exp);
    if(minimum_num == n){
      return minimum_num;
    }
    int sub_ans = power(k,maximum_exp-1);
    int power_counter = maximum_exp-2;
    if(power_counter<0){
      return minimum_num;
    }
    for(int i = power_counter; i>=0; i--){
        sub_ans+=power(k,i);
        if(sub_ans>=n){
          minimum_num = min(minimum_num, sub_ans);
          sub_ans-=power(k,i);
        }
    }
    return minimum_num;
}

int32_t main(){
    int n = 3620, k = 3;
    
    //We have to generate the minimum number >= n so that it can be written as sum of powers of k
    //Such that the powers are distinct


    int min_num_greater_than_n = Min_Num(n,k);

    cout<<min_num_greater_than_n<<endl;
    
    return 0;
}