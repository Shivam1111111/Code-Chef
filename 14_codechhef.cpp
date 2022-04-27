#include<iostream>
using namespace std;

int main(){
    int n,Q;
    cin>>n;
    cin>>Q;

    int *array = new int[n];

    for(int i = 1; i <= n; i++){
        cin >> array[i];
    }
    while(Q > 0){
        int l,r,x;
        int count = 0;
        cin >> l >> r >> x;

        while( l <= r){
            if(array[l] >= x){
                count = (r - l) + 1;
                break;
            }
            else{
                l++;
            }
        }
        cout<< count<<endl;
        Q--;
    }
}