#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,X,Y;
        cin>>N>>X>>Y;
        int *array = new int[N];

        int count = 0;
        for(int i = 0; i < N; i++){
            cin>>array[i];
            if((array[i] <= X) && (array[i] % Y == 0)){
                count++;
            }
        }
        cout<<count;
    }
}