/*
 Exercise P10.11. Implement a function vector<string> generate_subsets(string s)
 that generates all subsets of characters of a string. For example, the subsets of char- acters of the string "rum" are the eight strings
 "rum", "ru", "rm", "r", "um", "u", "m", ""
 Note that the subsets don’t have to be substrings—for example, "rm" isn’t a sub-
 string of "rum".
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generate_subsets(string s);
// helpers:
void swap(vector<string>& v, int a, int b);
void remove(vector<string>&v, int idx);
void sort_unique(vector<string>& v);

int main(int argc, const char * argv[]) {
    string keyword = "coffee";
    vector<string> subsets = generate_subsets(keyword);
    for (int i = 0; i < subsets.size(); i++){
        cout << "subsets[" << i << "]: " << subsets[i] << endl;
    }
    cout << "\n";
    return 0;
}

vector<string> generate_subsets(string s){
    if (s.length() == 0) return {};
    else if (s.length() == 1) return { s };
    
    vector<string> subsets;
    subsets.push_back(s);
    
    for (int i = 0; i < s.size(); i++){
        string temp = s;
        vector<string> lesser_subsets = generate_subsets(temp.erase(i, 1));
        for (int j = 0; j < lesser_subsets.size(); j++){
            subsets.push_back(lesser_subsets[j]);
        }
    }
    sort_unique(subsets);
    return subsets;
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
