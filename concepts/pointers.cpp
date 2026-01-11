#include<iostream>
using namespace std;

// --------------------------------------------------
// POINTERS & REFERENCES — NOTES (IN COMMENTS)
//
// Pointer  = variable jo kisi aur variable ka ADDRESS store karta hai
// Reference = ek existing variable ka ALIAS (dusra naam)
//
// --------------------------------------------------


// --------------------------------------------------
// PASS BY REFERENCE USING POINTER
//
// int* a  → a ek pointer hai jo kisi int ka address hold karta hai
// *a     → dereference operator (address pe rakhi value)
//
// Function ke andar change ki hui value
// original variable ko directly modify karti hai
// --------------------------------------------------
void change_a(int* a){
    *a = 20;   // jis address pe a point kar raha hai, waha value change
}


// --------------------------------------------------
// PASS BY REFERENCE USING REFERENCE VARIABLE
//
// int &b → b ek reference hai
// b koi naya variable nahi hai
// b = original variable ka hi dusra naam
//
// Internally compiler pointer jaisa hi treat karta hai
// Syntax simple hota hai
// --------------------------------------------------
void change_a_with_refrence(int &b){
    b = 20;    // directly original variable change
}


int main(){

    // --------------------------------------------------
    // BASIC POINTER CONCEPT
    //
    // int a = 10;
    // int* ptr = &a;
    //
    // ptr   → a ka address
    // &ptr  → ptr ka khud ka address
    // &a    → a ka address
    // --------------------------------------------------
    // cout << ptr << endl;
    // cout << &ptr << endl;
    // cout << &a << endl;


    // --------------------------------------------------
    // POINTER TYPE MUST MATCH VARIABLE TYPE
    //
    // float b = 10.211;
    // float* fptr = &b;   // correct
    //
    // int* ptr = &b;      // ❌ wrong (type mismatch)
    // --------------------------------------------------
    // cout << fptr << endl;
    // cout << &fptr << endl;
    // cout << &b << endl;


    // --------------------------------------------------
    // POINTER TO POINTER
    //
    // int c = 10;
    // int* cptr = &c;
    // int** ptr_to_ptr = &cptr;
    //
    // c           → value
    // cptr        → address of c
    // ptr_to_ptr  → address of cptr
    // --------------------------------------------------
    // cout << &c << endl;          // address of c
    // cout << cptr << endl;        // address of c
    // cout << &cptr << endl;       // address of cptr
    // cout << ptr_to_ptr << endl;  // address of cptr
    // cout << &ptr_to_ptr << endl; // address of ptr_to_ptr


    // --------------------------------------------------
    // DEREFERENCE OPERATOR (*)
    //
    // * means "value at address"
    //
    // *cptr         → value of c
    // **ptr_to_ptr  → value of c
    // --------------------------------------------------
    // cout << *cptr << endl;
    // cout << **ptr_to_ptr << endl;


    // --------------------------------------------------
    // NULL POINTER
    //
    // NULL pointer ka matlab:
    // Pointer kisi valid memory location ko point nahi kar raha
    //
    // Safety ke liye pointer initialize karo
    // Uninitialized pointer = dangerous (garbage address)
    // --------------------------------------------------
    // int* ptr = NULL;
    // cout << ptr << endl;


    // --------------------------------------------------
    // PASS BY REFERENCE DEMO
    //
    // int a = 10;
    //
    // change_a(&a);              // pointer based
    // change_a_with_refrence(a); // reference based
    //
    // Dono cases mein original 'a' change hota hai
    // --------------------------------------------------
    // cout << "Value of a = " << a << endl;


    // --------------------------------------------------
    // ARRAY & POINTER RELATION
    //
    // Array ka naam ek constant pointer hota hai
    // Uska address change nahi kar sakte
    //
    // int arr[] = {1, 2, 3, 4};
    // int a = 15, b = 10;
    //
    // int* ptr = &a;
    // ptr = &b;   // ✔ allowed
    //
    // arr = &a;   // ❌ error (array pointer constant)
    // --------------------------------------------------


    // --------------------------------------------------
    // POINTER ARITHMETIC
    //
    // Allowed operations:
    // 1) ++ , --
    // 2) ptr + n / ptr - n
    // 3) comparison (<, <=, >=, ==)
    //
    // Example:
    // int arr[] = {10, 20, 30};
    // int* p = arr;
    //
    // p       → arr[0]
    // p + 1   → arr[1]
    // p + 2   → arr[2]
    //
    // *(p + 1) = 20
    // --------------------------------------------------

    // --------------------------------------------------
    // POINTER ARITHMETIC — DETAILED EXAMPLES
    //
    // Allowed operations:
    // 1) Increment / Decrement (++, --)
    // 2) Add / Subtract number (ptr + n, ptr - n)
    // 3) Comparison (<, <=, >=, ==)
    //
    // --------------------------------------------------

    // -------- Example 1: ++ and --
    //
    // int arr[] = {10, 20, 30, 40};
    // int* p = arr;
    //
    // p        → points to arr[0] (10)
    // p++      → now points to arr[1] (20)
    // p++      → now points to arr[2] (30)
    // p--      → back to arr[1] (20)
    //
    // cout << *p;   // prints 20
    //
    // NOTE:
    // Pointer increment DOES NOT add 1 byte
    // It adds sizeof(datatype)
    // For int → usually 4 bytes
    // --------------------------------------------------


    // -------- Example 2: ptr + n / ptr - n
    //
    // int arr[] = {5, 15, 25, 35, 45};
    // int* p = arr;
    //
    // *(p + 0) → 5
    // *(p + 1) → 15
    // *(p + 2) → 25
    //
    // int* q = p + 3;
    // *q → 35
    //
    // q - p → 3   (distance between pointers)
    //
    // IMPORTANT:
    // Pointer subtraction gives number of elements,
    // not bytes
    // --------------------------------------------------


    // -------- Example 3: Traversing array using pointer
    //
    // int arr[] = {1, 2, 3, 4};
    // int* p = arr;
    //
    // for(int i = 0; i < 4; i++){
    //     cout << *(p + i) << " ";
    // }
    //
    // Same as:
    // cout << arr[i]
    // --------------------------------------------------


    // -------- Example 4: Pointer comparison
    //
    // int arr[] = {10, 20, 30};
    // int* p = &arr[0];
    // int* q = &arr[2];
    //
    // p < q   → true
    // p == q  → false
    //
    // Common use:
    // while(p <= q){
    //     cout << *p << " ";
    //     p++;
    // }
    // --------------------------------------------------


    // -------- Example 5: Invalid / Dangerous cases
    //
    // int* p;
    // p++;          // ❌ garbage address + arithmetic
    //
    // int arr[] = {1,2,3};
    // int* q = arr + 3;
    // *q;           // ❌ out of bounds (undefined behavior)
    //
    // Rule:
    // Pointer arithmetic sirf valid memory range mein
    // --------------------------------------------------

    return 0;
}
