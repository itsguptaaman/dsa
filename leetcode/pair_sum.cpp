#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// https://leetcode.com/problems/majority-element/description/


// Brute force approach
vector<int> pair_sum1(vector<int> nums, int target){
    vector<int> idx;
    int size = nums.size();
    for(int i = 0; i < size; i += 1){
        for(int j = 0; j < size; j += 1){
            if (nums[i] + nums[j] == target){
                idx.push_back(i);
                idx.push_back(j);
                return idx;
            }
        }
    }
    return idx;
}



vector<int> pair_sum(vector<int> nums, int target){
    vector<int> idx;
    int size = nums.size(), start = 0, end = size - 1;
    while (start < end)
    {
        int pair_sum_val = nums[start] + nums[end];
        if(pair_sum_val > target){
            end -= 1;
        }
        else if(pair_sum_val < target){
            start += 1;
        }
        else{
            idx.push_back(start);
            idx.push_back(end);
            return idx;
        }
    }
    
    return idx;
}

int main(){

    vector<int> nums = {2, 7, 11, 15};
    int target = 26;

    vector<int> ans = pair_sum(nums, target);
    cout << ans[0] << ", " << ans[1] << endl;

    return 0;
}