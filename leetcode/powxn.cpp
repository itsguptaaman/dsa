#include<iostream>
using namespace std;


// https://leetcode.com/problems/powx-n/description/
// Binary Exponentiation


// Problem: Power Function (x^n)
// Approach: Binary Exponentiation
// Goal: x^n ko fast way mein calculate karna

// ---------------- BASIC IDEA ----------------
// Normal approach mein hum n times multiply karte hain (slow)
// Binary exponentiation mein hum power ko binary mein tod dete hain
// Time complexity: O(log n)

// Example:
// n = 5
// Binary of 5 = 101
// Matlab:
// 1 -> x^1 use karna
// 0 -> x^2 skip
// 1 -> x^4 use karna
// Final = x^1 * x^4

// ---------------- EDGE CASES ----------------
// x^0 = 1 (chahe x kuch bhi ho, except 0^0 case)
// 0^n = 0
// 1^n = 1
// (-1)^even = 1
// (-1)^odd  = -1

double myPow(double x, int n) {

    // Agar power 0 hai
    if(n == 0) return 1.0;

    // Agar base 0 hai
    if(x == 0) return 0.0;

    // Agar base 1 hai
    if(x == 1) return 1.0;

    // -1 ke special cases
    if((x == -1) && (n % 2 == 0)) return 1.0;
    if((x == -1) && (n % 2 != 0)) return -1.0;

    // n ko long mein store kiya
    // kyunki INT_MIN ka negative int mein fit nahi hota
    long binary_form = n;

    // Agar power negative hai
    // x^-n = (1/x)^n
    if(binary_form < 0){
        x = 1 / x;
        binary_form = -binary_form;
    }

    // Final answer store karega
    double ans = 1;

    // Jab tak power > 0
    while(binary_form > 0){

        // Agar current bit 1 hai
        // matlab is power ka contribution lena hai
        if (binary_form % 2 == 1){
            ans *= x;
        }

        // Next power ke liye x ko square kar do
        x *= x;

        // Binary right shift (divide by 2)
        binary_form /= 2;
    }

    return ans;
}

int main(){
    double x = 2.00000; // base number
    int n = 10;         // power

    // Expected output: 1024
    cout << myPow(x, n) << endl;
    return 0;
}
