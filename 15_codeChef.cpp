#include<iostream>
using namespace std;

int main(){
    int t;
    cin>> t;

    while(t--){
        int N,C,K;
        cin >> N >> C >> K;
        int *array = new int[N];
        for(int s = 0; s < N; s++){
            cin >> array[s]; 
        }
        int i = 0;
        int j = 0;
        int max_element = 0;
        int w_sum = 0;

        while(j < N){
            w_sum = w_sum + array[j];

            if(w_sum < C){
                j++;
            }

            else if(w_sum <= C && w_sum >= K){
                if(max_element < j-i+1){
                    max_element = j-i+1;
                }
                j++;
            }

            else if(w_sum > C){
                while(w_sum > C){
                    w_sum = w_sum - array[i];
                    i++;
                }
                j++;
            }
        }
        cout<< max_element;
    }
} 


    