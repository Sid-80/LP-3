#include<iostream>
#include<vector>
using namespace std;

void fiboNonRec(int n){
    cout<<"0 ";
    if(n == 1) return;
    
    cout<<"1 ";
    if(n == 2) return;
    
    n -= 2;

    int prev1 = 0, prev2 = 1;

    for(int i = 0;i < n;i++){
        int sum = prev1+prev2;
        cout<<sum<<" ";
        prev1 = prev2;
        prev2 = sum;
    }
    return;
}

int fiboRec(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    return fiboRec(n - 1) + fiboRec(n - 2);
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter n : ";cin>>n;

    for(int i = 0;i < n;i++){
        cout<<fiboRec(i)<<" ";
    }

    return 0;
}
