#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.com/problems/single-number/description/

// Important property of XOR
//  n ^ n = 0, n ^ 0 = n
// n ^ x = 1

int main(){
    vector<int> nums = {4,1,2,1,2};
    int ans = 0;
    for(int val: nums){
        ans ^= val;
    }
    cout << ans << endl;
    return 0;
}