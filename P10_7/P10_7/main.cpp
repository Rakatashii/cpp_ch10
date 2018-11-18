/*
 Exercise P10.7.
 Using recursion, find the largest element in a vector of integer values. int maximum(vector<int> values)
 Hint: Find the largest element in the subset containing all but the last element. Then compare that maximum to the value of the last element.
*/

#include <iostream>
#include <vector>

using namespace std;

int maximum(vector<int>values);

int main(int argc, const char * argv[]) {
    vector<int> values1 = {1, 2, 3, 4, 5, 3, 4, 8, 7, 6, 5};
    vector<int> values2 = {};
    vector<int> values3 = {4, 4, 4, 4, 4};
    vector<int> values4 = {-3, -4, -2, -7, -6, -8};
    int max = maximum(values1);
    cout << "max = " << max << endl;
    max = maximum(values2);
    cout << "max = " << max << endl;
    max = maximum(values3);
    cout << "max = " << max << endl;
    max = maximum(values4);
    cout << "max = " << max << endl;
    
    return 0;
}

int maximum(vector<int>values){
    int max = -1;
    if (values.size() == 0) goto failure;
    
    max = values[values.size()-1];
    values.pop_back();
    
    if (values.size() <= 1) return max;
    else if (values.size() == 2){
        return max = (values[0] >= values[1]) ? values[0] : values[1];
    }
    else {
        if (values[0] < max) values[0] = max;
        max = maximum(values);
        return max;
    }
    failure: return max; // shouldn't get here.
}
