#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int N;
        cin >> N;
        int *array = new int[N];

        bool increasing = true;

        for(int i = 0; i < N; i++){

            cin >> array[i];
            if(i > 0 && array[i] <= array[i-1]){
                increasing = false;
            }
        }
        if(increasing){
            cout << "Yes";
        }
        else
            cout << "No";
    }
}