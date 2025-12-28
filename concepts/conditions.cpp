#include<iostream>

using namespace std;


int main(){
    // char inp = 'A';

    // if ((inp >= 'A') & (inp <= 'Z')){
    //     cout << "Upper Case" << endl;
    // }
    // else if ((inp >= 'a') & (inp <= 'z')){
    //     cout << "Lower Case" << endl;
    // }
    // else{
    //     cout << "Special symbol" << endl;
    // }
    // cout << (inp >= 0 ? "positive" : "negative") << endl;

    // int count = 1;
    // int n = 50;
    // while (count <= n)
    // {
    //     cout << count << " ";
    //     count += 1;
    // }
    // cout << endl;

    // int res = 0;
    // int n = 10;
    // for (int i = 1; i <= n; i += 2){
    //     cout << i << " ";
    //     res +=i;
    // }
    // cout << endl << res << endl;

    
    // Koi bhi number ke agar factor nikaloge tho vho ek point par
    // repeat hone lagenge vho point hai √n * √n matlab 1 se √n tak unique numbers hai
    // √n tak pauchne kae liye i ko square kar doh dono side square root loh tho √n mil jayega
    // i * i <= num jho √n ke equal hai 
    int num = 4;
    bool is_prime = true;
    for(int i = 2; i * i <= num; i += 1){
        if(num % i == 0){
            is_prime = false;
            break;
        }
    }
    if(is_prime == true){
        cout << num << " is a prime number" << endl;
    }
    else{
        cout << num << " is not a prime number" << endl;
    }

    return 0;
}