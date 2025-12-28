#include<iostream>
#include<vector>
#include <climits>


using namespace std;

// https://leetcode.com/problems/maximum-subarray/description/

// Possible sub array in array is (n * (n + 1)) / 2
void print_subarray(vector<int> arr){
    int n = arr.size();
    for(int start = 0; start < n; start += 1){
        for(int end = start; end < n; end += 1){
            for(int i=start; i <= end; i += 1){
                cout << arr.at(i);
            }
            cout << " ";
        }
        cout << endl;
    }
}


// Brute Force approach
int maxsum_subarray(vector<int> arr){
    int n = arr.size(), cur_sum, max_sum = arr.at(0);

    for(int start = 0; start < n; start += 1){
        cur_sum = 0;
        for(int end = start; end < n; end += 1){
            cur_sum += arr[end];
            max_sum = max(cur_sum, max_sum);
        }
    }
    cout << max_sum << endl;
    return max_sum;
}


int maxsum_kadanes(vector<int> arr){
    int n = arr.size(), cur_sum, max_sum = INT_MIN;
    for(int i = 0; i < n; i += 1){
        cur_sum += arr[i];
        max_sum = max(cur_sum, max_sum);
        if (cur_sum < 0){
            cur_sum = 0;
        }
    }
    cout << max_sum << endl;
    return max_sum;
}


// Kadanes Algorithm Intitution
// +ve + +ve ==> +ve
// -v + big +ve ==> +ve
// +ve + big -ve => -ve
//  if we add big negative number to postive number sum will be negative so we will rest it to 0.


int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxsum_kadanes(arr);
    return 0;
}