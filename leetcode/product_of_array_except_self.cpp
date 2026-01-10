#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// --------------------------------------------------
// LeetCode: Product of Array Except Self
// Link: https://leetcode.com/problems/product-of-array-except-self/
//
// Problem:
// Ek array diya hai nums[]
// Har index i ke liye:
// answer[i] = nums ke saare elements ka product
// EXCEPT nums[i]
//
// Constraints:
// - Division (/) use nahi kar sakte
// - O(n) time chahiye
// - Extra space ideally O(1) (output array allowed)
// --------------------------------------------------


// --------------------------------------------------
// BRUTE FORCE APPROACH
//
// Idea:
// Har index i ke liye:
//   - poore array ka product nikalo
//   - bas nums[i] ko skip karo
//
// Time Complexity: O(n^2)
// Space Complexity: O(1) (answer array ke alawa)
//
// Ye approach large input pe TLE degi
// --------------------------------------------------
vector<int> product_except_self_bf(vector<int> nums){
    int size = nums.size();
    vector<int> answer;

    for(int i = 0; i < size; i++){
        int ans = 1;

        for(int j = 0; j < size; j++){
            if(i == j){
                continue;   // khud ko skip
            }
            ans = ans * nums[j];
        }

        answer.push_back(ans);
    }
    return answer;    
}


// --------------------------------------------------
// OPTIMIZED BUT INVALID APPROACH
//
// Idea:
// Total product nikaal lo
// answer[i] = total_product / nums[i]
//
// Problem:
// - Division allowed nahi hai (constraint violation)
// - Zero present ho toh logic toot jaata hai
//
// Isliye ye solution ACCEPTED nahi hai
// --------------------------------------------------
vector<int> product_except_self_opbf(vector<int> nums){
    int size = nums.size();
    int ans = 1;

    // Total product
    for(int i = 0; i < size; i++){
        ans = ans * nums[i];
    }

    // Divide karke result
    for(int i = 0; i < size; i++){
        nums[i] = (ans / nums[i]);
    }
    return nums;    
}


// --------------------------------------------------
// PREFIX + SUFFIX ARRAYS APPROACH
//
// Core Idea:
// answer[i] = (product of elements on left of i)
//           * (product of elements on right of i)
//
// prefix[i] = nums[0] * nums[1] * ... * nums[i-1]
// suffix[i] = nums[i+1] * nums[i+2] * ... * nums[n-1]
//
// Time Complexity: O(n)
// Space Complexity: O(n)  <-- extra arrays use ho rahe hain
//
// Logic correct hai, but space optimized nahi
// --------------------------------------------------
vector<int> product_except_self_(vector<int> nums){
    int size = nums.size();
    vector<int> prefix(size, 1), suffix(size, 1);
    
    // Prefix product build
    for(int i = 1; i < size; i++){
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }
    
    // Suffix product build
    for(int i = size - 2; i >= 0; i--){
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Final answer
    for(int i = 0; i < size; i++){
        prefix[i] = prefix[i] * suffix[i];
    }

    return prefix;
}


// --------------------------------------------------
// OPTIMIZED PREFIX + SUFFIX (BEST SOLUTION)
//
// Idea:
// Prefix array use karo
// Suffix ko ek variable mein maintain karo
//
// Steps:
// 1) prefix[i] = product of elements left of i
// 2) right se iterate karke suffix product multiply karte jao
//
// Time Complexity: O(n)
// Space Complexity: O(1) extra (output array allowed)
//
// Ye LeetCode accepted solution hai
// --------------------------------------------------
vector<int> product_except_self(vector<int> nums){
    int size = nums.size();

    vector<int> prefix(size, 1);
    int suffix = 1;

    // Prefix products
    for(int i = 1; i < size; i++){
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }
    
    // Suffix products (on the fly)
    for(int i = size - 2; i >= 0; i--){
        suffix = suffix * nums[i + 1];
        prefix[i] = prefix[i] * suffix;
    }

    return prefix;
}


// --------------------------------------------------
// Driver Code
// --------------------------------------------------
int main(){
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans;

    // ans = product_except_self_bf(nums);
    // ans = product_except_self_opbf(nums);
    // ans = product_except_self_(nums);
    ans = product_except_self(nums);

    // Expected Output: 24 12 8 6
    for(int val: ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
