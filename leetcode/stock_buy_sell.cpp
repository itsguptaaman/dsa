#include <iostream>
#include <vector>
using namespace std;


// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Problem: Best Time to Buy and Sell Stock (1 transaction allowed)
// Goal: Ek baar buy + ek baar sell karke maximum profit nikalna
// Constraint: Buy pehle hoga, sell baad mein

// ---------------- BASIC INTUITION ----------------
// Har din ko SELLING DAY maan ke socho
// Aur poochho:
// "Agar main aaj sell karta, toh sabse sasta buy kab hota?"
//
// Isliye humein do cheezein track karni hain:
// 1) best_buy   → ab tak ka minimum price (best buying day) => kya aaj ka din best buy ban sakta hai?
// 2) max_profit → ab tak ka maximum profit

// Example:
// prices = [7, 1, 5, 3, 6, 4]
//
// Day 0: price = 7
// best_buy = 7
//
// Day 1: price = 1
// best_buy = 1   (better buy mil gaya)
//
// Day 2: price = 5
// profit = 5 - 1 = 4
// max_profit = 4
//
// Day 3: price = 3
// profit = 3 - 1 = 2 (ignore, smaller)
// best_buy still 1
//
// Day 4: price = 6
// profit = 6 - 1 = 5
// max_profit = 5
//
// Day 5: price = 4
// profit = 4 - 1 = 3 (ignore)
//
// Final answer = 5

int max_profit(vector<int> prices){

    int size = prices.size();

    // best_buy = ab tak ka sabse minimum price
    // max_profit = best possible profit
    int best_buy = prices[0];
    int max_profit = 0;

    // Day 1 se start kyunki day 0 pe sirf buy ho sakta hai
    for(int i = 1; i < size; i++){

        // Aaj sell karne ka profit calculate karo
        int profit_today = prices[i] - best_buy;

        // Maximum profit update karo
        max_profit = max(max_profit, profit_today);

        // Agar aaj ka price aur sasta hai
        // toh better buy mil gaya
        best_buy = min(best_buy, prices[i]);
    }

    return max_profit;
}

// ---------------- IMPORTANT NOTES ----------------
// Profit kabhi negative nahi lenge
// Agar prices continuously gir rahe hain
// toh answer 0 hoga (no transaction)
//
// Time Complexity: O(n)
// Space Complexity: O(1)

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Expected output: 5 (buy at 1, sell at 6)
    cout << max_profit(prices) << endl;
    return 0;
}
