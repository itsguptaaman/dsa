#include<iostream>

using namespace std;



void largest_smallest(){
    int marks[] = {99, 100, 54, -1, 46, 88};
    int size = sizeof(marks) / sizeof(int);
    int smallest_num = marks[0], smallest_idx;
    int largest_num = marks[0], largest_idx;
    for(int i = 1; i < size; i += 1){
        if (marks[i] < smallest_num){
            smallest_num = marks[i];
            smallest_idx = i;
        }
        if (marks[i] > largest_num)
        {
            largest_num = marks[i];
            largest_idx = i;
        }        
    }
    cout << "Smallest number in an array is " << smallest_num << " at index " << smallest_idx << endl;
    cout << "Largest number in an array is " << largest_num<< " at index " << largest_idx << endl;
    return;
}

// Linear Search Algorithm
int linear_search(int arr[], int size, int target){
    for(int i = 0; i < size; i += 1){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

// Reverse an array
void reverse_arr(int arr[], int size){
    int start = 0, end = size - 1, temp;
    while (start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    return;
}

void unique_values(int arr[], int size){
    int val, is_unique;
    for(int i = 0; i < size; i += 1){
        val = arr[i];
        is_unique = true;
        for(int j = 0; j < size; j += 1){
            if(i == j){
                continue;
            }
            if(arr[j] == val){
                is_unique = false;
            }
        }
        if(is_unique == true){
            cout << val << " ";
        }
    }

}

int main(){
    int values[] = {4, 2, 1, 8, 1, 2, 5};
    int size = sizeof(values) / sizeof(int);
    // int target = 8;
    // cout << linear_search(values, size, target) << endl;
    // reverse_arr(values, size);
    // for(int i = 0; i < size; i += 1){
    // cout << values[i] << " ";
    // }
    unique_values(values, size);
    cout << endl;
    return 0;
}