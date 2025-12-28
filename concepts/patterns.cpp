#include<iostream>

using namespace std;


int main(){
    // int m = 4;
    // int n = 4;
    // for(int i = 1; i <= m; i += 1){
    //     char ch = 'A';
    //     for(int j = 1; j <= m; j += 1){
    //         cout << ch << " ";
    //         ch++;
    //     }
    //     cout << "\n";
    // }
    // cout << endl;


    // int n = 4;
    // int num = 1;
    // for(int i = 0; i < n; i += 1){
    //     for(int j = 0; j < n; j += 1){
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << "\n";
    // }

    // int n = 4;
    // char ch = 'A';
    // for(int i = 0; i < n; i += 1){
    //     for(int j = 0; j < n; j += 1){
    //         if (j < i){
    //             cout << " ";
    //         }
    //         else{
    //         cout << ch;
    //         }
    //     }
    //     ch++;
    //     cout << "\n";
    // }

    int n = 4;
    for(int i = 0; i < n; i += 1){
        for(int s = 0; s < n - i; s++){
            cout << " ";
        }

        // increasing numbers
        for(int j = 1; j <= i; j++){
            cout << j;
        }

        // decreasing numbers
        for(int j = i - 1; j >= 1; j--){
            cout << j;
        }
        cout << endl;
    }

    return 0;
}