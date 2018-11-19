/*
 Exercise P10.12.
 The following program generates all permutations of the numbers
 0, 1, 2, ... , n – 1, without using recursion.
 
 The algorithm uses the fact that the set to be permuted consists of distinct numbers.
 Thus, you cannot use the same algorithm to compute the permutations of the characters in a string.
 You can, however, use this technique to get all permutations of the character positions and then compute a string whose ith character is s[a[i]].
 Use this approach to reimplement the generate_permutations function without recursion.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> get_permutations(string word);
bool next_permutation(vector<int>& a);
void swap(int& x, int& y);
void reverse(vector<int>& a, int i, int j);
void print(const vector<int>& a);

int main() {
    string word = "coffee";
    vector<string> permutations = get_permutations(word);
    for (int i = 0; i < permutations.size(); i++){
        cout << "permuation[" << i << "] = " << permutations[i] << endl;
    }
    
    cout << "\n";
    return 0;
}

vector<string> get_permutations(string word){
    int len = word.length();
    vector<int> indices(len);
    for (int i = 0; i < word.length(); i++){
        indices[i] = i;
    }
    vector<string> permutations;
    while (next_permutation(indices)){
        string s;
        for (int i = 0; i < indices.size(); i++){
            s.push_back(word[indices[i]]);
        }
        permutations.push_back(s);
    }
    return permutations;
}

bool next_permutation(vector<int>& a) {
    for (int i = a.size()-1; i > 0; i--) {
        if (a[i-1] < a[i]) {
            int j = a.size() - 1;
            while (a[i - 1] > a[j]) j--;
            swap(a[i - 1], a[j]);
            reverse(a, i, a.size() - 1);
            return true;
        }
    }
    return false;
}
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
void reverse(vector<int>& a, int i, int j) {
    while (i < j) {
        swap(a[i], a[j]); i++; j--;
    }
}
void print(const vector<int>& a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}










