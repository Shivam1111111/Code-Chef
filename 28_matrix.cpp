#include<iostream>
#include<limits>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int R,C;
        cin >> R >> C; 
        
        int a;
        int diff = 0;

        for(int i = 0 ; i < R; i++){
            int min = INT32_MAX;
            int max = INT32_MIN;
            for(int j = 0; j < C; j++){
                cin >> a;

                if(a > max){
                    max = a;
                }
                if(a < min){
                    min = a;
                }
            }
            if( max - min > diff){
                diff = (max-min);
            }
        }
        cout << diff;
    }
}