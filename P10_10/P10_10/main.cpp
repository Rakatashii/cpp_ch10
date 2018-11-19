/*
Exercise P10.10. Implement a function vector<string> generate_substrings(string s)
that generates all substrings of a string. For example, the substrings of the string "rum" are the seven strings
"r", "ru", "rum", "u", "um", "m", ""
Hint: First enumerate all substrings that start with the first character. There are n of them if the string has length n. Then enumerate the substrings of the string that you obtain by removing the first character.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generate_substrings(string word); // this is the recursive function
void sort_unique(vector<string>& v); // sorts by size and removes duplicate values
// helpers:
void swap(vector<string>& v, int a, int b);
void remove(vector<string>&v, int idx);

int main(int argc, const char * argv[]) {
    
    string word = "coffee";
    vector<string> substrings = generate_substrings(word);
    for (int i = 0; i < substrings.size(); i++){
        cout << "substring[" << i << "] = " << substrings[i] << endl;
     }
    
    return 0;
}

vector<string> generate_substrings(string word){
    if (word.length() == 0) return {""};
    else if (word.length() == 1) return {word};
    
    vector<string> substrings;
    substrings.push_back(word);
    vector<string> sub1 = generate_substrings(word.substr(1));
    vector<string> sub2 = generate_substrings(word.substr(0, word.length()-1));

    substrings.insert(substrings.end(), sub1.begin(), sub1.end());
    substrings.insert(substrings.end(), sub2.begin(), sub2.end());
    
    sort_unique(substrings);
    return substrings;
}

void sort_unique(vector<string>& v){
    bool sorted = false;
    while (!sorted){
        int i = 1, correct_count = 0, size = v.size();
        do {
            if (i > size-1) break;
            
            if (v[i-1] == v[i]) { remove(v, i); break; }
            else if (v[i-1].length() < v[i].length()) swap(v, i-1, i);
            else correct_count++;
            
            if (v[i-1].length() == v[i].length()){
                int len = v[i].length();
                if ((int)v[i-1][0] > (int)v[i][0]) swap(v, i-1, i);
                else if ((int)v[i-1][0] == (int)v[i][0] && len > 1){
                    if ((int)v[i-1][1] > (int)v[i][1]) swap(v, i-1, i);
                }
            }
            
            if (correct_count >= size-1) sorted = true;
            
            size = v.size();
            i++;
        } while (i < v.size() && !sorted);
    }
}
void swap(vector<string>& v, int a, int b){
    string temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}
void remove(vector<string>&v, int idx){
    if (idx == v.size()-1) goto end;
    for (int i = idx; i < v.size()-1; i++){
        v[i] = v[i+1];
    }
    end: v.pop_back();
}
