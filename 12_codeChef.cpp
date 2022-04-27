#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K,d,r,lowest;
        cin>>N;
        cin>>K;
        int *cost = new int[N];
        for(int i = 0; i < N; i++){
            cin>>d;
            cost[i] = K * d;
        }
        lowest = __INT_MAX__;
        for(int i = 0; i < N; i++){
            cin>>r;
            cost[i] = cost[i] + r;
            if(cost[i] < lowest){
                lowest = cost[i];
            }
        }
        cout << lowest;
    }
}