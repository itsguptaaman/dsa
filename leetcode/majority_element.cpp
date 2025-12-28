#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


// Bruteforce approach
int majority_element1(vector<int> arr){
    int size = arr.size(), freq;
    for(int i = 0; i < size; i += 1){
        freq = 0;
        for(int j = 0; j < size; j += 1){
            if (arr[i] == arr[j]){
                freq += 1;
            }
        }
        if (freq >= size / 2 ){
            return arr[i];
        }
    }
    return -1;
}


// Optimize Approach
int majority_element2(vector<int> arr){

    sort(arr.begin(), arr.end());
    int size = arr.size(), freq = 0;
    
    for(int i = 0; i < size; i += 1){
        if (arr[i] == arr[i - 1]){
            freq += 1;
        }
        else{
            freq = 0;
        }
        if (freq >= size / 2){
            return arr[i];
        }
    }
    
    return -1;
}


// Moores algorithm
// Intutition if element is 0 assign you ans if the element is same do ++ element is different do -- 

int majority_element(vector<int> arr){
    int size = arr.size(), freq = 0, ans = 0;
    
    for(int i = 0; i < size; i += 1){
        if(freq == 0){
            ans = arr[i];
        }
        if(arr[i] == ans){
            freq += 1;
        }
        else{
            freq -= 1;
        }
    }
    
    return ans;
}

int main(){
    vector<int> nums = {3, 2, 3, 5, 5, 5, 5};
    cout << majority_element(nums) << endl;

}