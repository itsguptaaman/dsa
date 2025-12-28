#include<iostream>
#include<vector>

using namespace std;

int main(){
    // vec(size, value)
    // vector<int> vec(3, 0)
    // vector<int> vec;
    vector<int> marks = {1, 3, 5};
    marks.push_back(7);
    cout << "size " << marks.at(2) << endl;
    marks.pop_back();

    cout << "size " << marks.capacity() << endl;

    for(int val: marks){ // for each loop
        cout << val << endl;
    }

    return 0;
}