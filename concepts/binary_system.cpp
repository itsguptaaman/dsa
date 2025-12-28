#include<iostream>

using namespace std;

int power(int num, int pow){
    int ans = 1;
    for(int i = 0; i < pow; i += 1){
        ans = ans * num;
    }
    return ans;
}

int decimal_to_binary(int num){
    int ans = 0, rem = 0, pow = 1;
    while (num > 0)
    {
        rem = num % 2;
        num = num / 2;

        ans = ans + rem * pow;
        pow = pow * 10;
    }
    return ans;
}

int binary_to_decimal(int binary){
    int ans = 0, pow = 1, rem = 0;
    while (binary > 0)
    {
        rem = binary % 10;
        binary = binary / 10;

        ans = ans + rem * pow;
        pow = pow * 2;
    }
    return ans;
}

// Twos compliment steps decimal to binary
// 1. Binary form convert
// 2. Prefix with a 0     if -ve then 1 else 0 assume its postive with 0
// 3. 1's compliment => meaning flip the bits if 0 -> 1 else 1 -> 0
// 4 Add +1


// Binary to Decimal
// we need again 2's compliment
// 1. 1's compliment
// 2. Add +1  


// Bitwise left shift << When we do this a << b it means we are doing a*2^b
// right shift >> When we do this we are doing a / 2^b

bool number_is_power_of_2_(int num){
    int pow = 0, val = 0;
    while (val <= num)
    {
        val = power(2, pow);
        if (val == num){
            return true;
        }
        pow++;
    }
    return false;
}

bool number_is_power_of_2(int num) {
    if (num <= 0) return false;
    return (num & (num - 1)) == 0;
}


int main(){
     
        //   64 32 16 8 4 2 1
    // 50 => 0  1  1 0  0 1 0
    // cout << power(2, 4) << endl;
    // cout << decimal_to_binary(50) << endl;
    // cout << binary_to_decimal(110010) << endl;
    cout << number_is_power_of_2(50) << endl;
    return 0;
}