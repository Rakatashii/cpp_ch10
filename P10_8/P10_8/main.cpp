/*
 Exercise P10.8.
 Using recursion, compute the sum of all values in an array.
*/

#include <iostream>

using namespace std;

int  get_sum(int arr[], int sz);

int main(int argc, const char * argv[]) {
    int sz = 7;
    int arr1[] = {1, 2, 3, 4, 5, 4, 3};
    int sum = 0;
    sum = get_sum(arr1, sz);
    cout << "get_sum(arr1 = " << sum << endl;
    int arr2[] = {-2, -6, 8, -3, 9, 4};
    sz = 6;
    sum = get_sum(arr2, sz);
    cout << "get_sum(arr2 = " << sum << endl;
    int arr3[] = {5, 5, 5, 5, 5};
    sz = 5;
    sum = get_sum(arr3, sz);
    cout << "get_sum(arr3 = " << sum << endl;
    
    return 0;
}

int get_sum(int arr[], int sz){
    if (sz == 0) return -1; // fail condition
    int total = *(arr+sz-1);
    if (sz <= 1) return total; // base case
    int* sub_arr = new int[--sz];
    sub_arr = arr;
    total += get_sum(sub_arr, sz); // recursion
    return total;
}
