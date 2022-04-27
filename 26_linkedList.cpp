#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int max_subarray = 0;
        int count = 0;
        int j = 0;
        int N;
        cin >> N;
        int *array = new int[N];

        for(int i = 0; i < N; i++){
            cin >> array[i];
        }

        while(j < N){
            
            if(array[j] % 2 == 0){
                count++;
                if(max_subarray < count){
                    max_subarray = count;
                }
                j++;
            }
            else{
                count == 0;
                j++;
            }
        }
        cout << max_subarray;
    }
}