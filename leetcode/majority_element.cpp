#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


// https://leetcode.com/problems/majority-element/description/

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


// / Problem: Majority Element
// Condition: Koi ek element array mein > n/2 times aata hai
// Approach: Moore’s Voting Algorithm
// Time: O(n)
// Space: O(1)

// ---------------- BASIC INTUITION ----------------
// Socho voting chal rahi hai.
// Same element = same party → vote ++
// Different element = opposite party → vote --
//
// Jab vote 0 ho jaata hai:
// matlab ab tak ke votes cancel ho gaye
// toh current element ko naya candidate maan lo

// Example:
// [3, 2, 3, 5, 5, 5, 5]
//
// Step by step thinking:
// 3 → freq=1, ans=3
// 2 → different → freq=0 (3 aur 2 cancel)
// 3 → freq=1, ans=3
// 5 → different → freq=0 (3 aur 5 cancel)
// 5 → freq=1, ans=5
// 5 → freq=2
// 5 → freq=3
//
// Final candidate = 5

int majority_element(vector<int> arr){

    int size = arr.size();

    // freq = vote count
    // ans  = current candidate
    int freq = 0, ans = 0;

    for(int i = 0; i < size; i++){

        // Agar votes khatam ho gaye
        // toh current element ko candidate bana do
        if(freq == 0){
            ans = arr[i];
        }

        // Agar same element mila
        // toh vote badhao
        if(arr[i] == ans){
            freq++;
        }
        // Agar different element mila
        // toh vote ghatao
        else{
            freq--;
        }
    }

    // End mein jo bacha wahi majority element hoga
    // (Question guarantee karta hai ki majority exist karta hai)
    return ans;
}