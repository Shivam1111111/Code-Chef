#include<iostream>
#include<limits>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        int *array = new int[N];
        int sum = 0;
        int max = INT32_MIN;

        for(int i = 0; i < N; i++){
            cin >> array[i]; 
        }
        for(int i = 0; i < N; i++){
            sum = array[i] + array[i+2];
            if(max < sum){
                max = sum;
            }
        }
        cout << max;
    }
}