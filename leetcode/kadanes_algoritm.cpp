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

// Problem: Maximum Subarray Sum
// Approach: Kadane’s Algorithm
// Time: O(n)
// Space: O(1)

// ---------------- BASIC INTUITION ----------------
// Hum array ko left se right scan karte hain
// Har step pe ek running sum maintain karte hain
//
// Rule simple hai:
// 1) Current element ko running sum mein add karo
// 2) Max answer update karo
// 3) Agar running sum negative ho jaaye
//    toh usse discard (0 se reset) kar do
//
// Reason:
// Negative sum future ke liye poison hota hai
// Woh aage ke positive numbers ka result kharab karega

// Example array:
// [-2, 1, -3, 4, -1, 2, 1, -5, 4]

int maxsum_kadanes(vector<int> arr){

    int n = arr.size();

    // cur_sum = current subarray ka sum
    // max_sum = ab tak ka maximum subarray sum
    int cur_sum = 0;
    int max_sum = INT_MIN;

    for(int i = 0; i < n; i++){

        // Current element ko add karo
        cur_sum += arr[i];

        // Har step pe maximum update karo
        max_sum = max(cur_sum, max_sum);

        // Agar current sum negative ho gaya
        // toh future ke liye useless hai
        // isliye reset kar do
        if(cur_sum < 0){
            cur_sum = 0;
        }
    }

    return max_sum;
}

// ---------------- IMPORTANT NOTES ----------------
// +ve + +ve  => +ve (continue karo)
// -ve + big +ve => +ve (negative tolerate ho sakta hai)
// +ve + big -ve => -ve (poison, reset required)

// Edge Case:
// Agar poora array negative ho
// tab bhi max_sum correct rahega
// kyunki hum max_sum ko INT_MIN se start karte hain


int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxsum_kadanes(arr);
    return 0;
}