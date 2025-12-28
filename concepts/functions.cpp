#include<iostream>

using namespace std;


int add(int a, int b){
    return a + b;
}

int min_of_two(int a, int b){
    if (a > b){
        return b;
    }
    else{
        return a;
    }
}

int sum_of_n(int n){
    int res = 0;
    for(int i = 1; i <= n; i += 1){
        res += i;
    }
    return res;
}

// Time complexity for recursion is 
// 1. Recurrence Relation
// 2. TC = total no of each calls * work done in each calls
// Space Complexity = Dept of recursion tree * memory in each call

int fact(int n){
    if (n == 0){
        return 1;
    }
    return n * fact(n - 1);
}

int sum_of_digits(int n){
    int sum = 0;
    int val;
    while(n > 0){
        val = n % 10;
        n = n / 10;
        sum = sum + val;
    }
    return sum;
}

bool is_prime(int num){
    bool prime = true;
    for(int i = 2; i * i <= num; i += 1){
        if (num % i == 0){
            prime = false;
            break;
        } 
    }
    if (prime == true){
        return true;
    }
    else{
        return false;
    }
}

void print_prime_numbers_upto_n(int n){
    
    for(int i = 1; i <= n; i += 1){
        if (is_prime(i) == true){
            cout << i << " ";
        }
    }
    cout << endl;
}


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


int main(){
    // cout << add(5, 6) << endl;
    // cout << min_of_two(5, 5) << endl;
    // cout << sum_of_n(4) << endl;
    // cout << fact(5) << endl;
    // cout << sum_of_digits(2356) << endl;
    // int n = 154;
    // cout << n % 10 << endl;

    // cout << is_prime(3) << endl;
    // print_prime_numbers_upto_n(100);

    
        //   64 32 16 8 4 2 1
    // 50 => 0  1  1 0  0 1 0
    // cout << power(2, 4) << endl;
    // cout << decimal_to_binary(50) << endl;
    cout << binary_to_decimal(110010) << endl;

    return 0;
}