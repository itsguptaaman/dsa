#include<iostream>
#include<vector>
using namespace std;


// https://leetcode.com/problems/container-with-most-water/description/
// --------------------------------------------------
// Helper function (debug ke liye)
// Har possible container pair print karta hai
// i = left wall, j = right wall
// --------------------------------------------------
void print_container(vector<int> height){
    int size = height.size();

    // Har possible (i, j) pair
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            cout << height[i] << "-" << height[j] << " ";
        }
        cout << endl;
    }
}

// --------------------------------------------------
// BRUTE FORCE APPROACH
// Problem: Container With Most Water
//
// Idea:
// Har possible pair (i, j) try karo
// Width  = j - i
// Height = min(height[i], height[j])
// Area   = width * height
//
// Jo sabse bada area mile wahi answer
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// --------------------------------------------------
int maximum_water_bf(vector<int> height){
    int size = height.size();

    int max_water = 0;
    int area, wid, hig;

    // Left wall choose karo
    for(int i = 0; i < size; i++){
        // Right wall choose karo
        for(int j = i + 1; j < size; j++){

            // Container ki width
            wid = j - i;

            // Container ki height (shorter wall decide karegi)
            hig = min(height[i], height[j]);

            // Area calculation
            area = wid * hig;

            // Maximum area update
            max_water = max(max_water, area);
        }
    }
    return max_water;
}

// --------------------------------------------------
// OPTIMIZED APPROACH (Two Pointer)
// Core Intuition:
// Sabse wide container outer walls banati hain
// Phir hum hamesha chhoti height wali wall ko move karte hain
//
// Kyun?
// Kyunki area = width * min(height)
// Agar badi wall move ki → height nahi badhegi, width kam ho jayegi
// Sirf chhoti wall move karne se height improve hone ka chance hota hai
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// --------------------------------------------------
int maximum_water(vector<int> height){
    int size = height.size();

    int max_water = 0;
    int area, wid, hig;

    // lp = left pointer, rp = right pointer
    int lp = 0;
    int rp = size - 1;

    // Jab tak pointers cross nahi karte
    while(lp < rp){

        // Current container ki height
        hig = min(height[lp], height[rp]);

        // Current container ki width
        wid = rp - lp;

        // Area calculate karo
        area = wid * hig;

        // Maximum area update
        max_water = max(max_water, area);

        // Pointer movement rule:
        // Jo wall chhoti hai, usko move karo
        if(height[lp] < height[rp]){
            lp++;   // left wall chhoti → left pointer aage
        }
        else{
            rp--;   // right wall chhoti ya equal → right pointer peeche
        }
    }
    
    return max_water;
}

// --------------------------------------------------
// Driver code
// --------------------------------------------------
int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Brute force check
    // cout << maximum_water_bf(height) << endl;

    // Optimized solution
    // Expected output: 49
    // (height 8 & 7, width = 7)
    cout << maximum_water(height) << endl;

    return 0;
}
