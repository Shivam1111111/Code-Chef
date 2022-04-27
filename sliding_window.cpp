#include<iostream>
using namespace std;

int main(){
    int array[] = {1,2,2,4,1,5,1,1,1,2};
    int size = sizeof(array)/sizeof(array[0]);
    int k = 5;
    int max_subarray = 0;
    int i = 0;
    int j = 0;
    int sum = 0;

    while(j < size){
        sum = sum + array[j];

        if(sum < k){
            j++;
        }

        else if(sum == k){
            if(max_subarray < j-i+1 ){
                max_subarray = j-i+1;
            }
            j++;
        }

        else if(sum > k){
            while(sum > k){
                sum = sum - array[i];
                i++;
            }
            j++;
        }
    }
    cout<< max_subarray<<" "<<sum;
}