/*
 Exercise P10.6.
 Use recursion to implement a function int index_of(string s, string t) that returns the starting position of the first substring of the string s that matches t.
 Return –1 if t is not a substring of s. For example:
 int n = s.index_of("Mississippi!", "sip"); // Returns 6
 Hint: This is a bit trickier than Exercise P10.5, because you need to keep track of how far the match is from the beginning of the sentence. Make that value a parameter of a helper function.
*/

#include <iostream>
#include <string>

using namespace std;

int index_of(string sub, string full, int count = 0);
int track(string sub, string full, int count);

int main(int argc, const char * argv[]) {
    string full = "Mississippi";
    string sub1 = "sip";
    int index1 = index_of(sub1, full);
    cout << "index1 = " << index1 << endl;
    string sub2 = "sup";
    int index2 = index_of(sub2, full);
    cout << "index2 = " << index2 << endl;
    string sub3 = "ippi";
    int index3 = index_of(sub3, full);
    cout << "index3 = " << index3 << endl;
    
    return 0;
}

int index_of(string sub, string full, int count){
    int min = sub.length();
    if (min > full.length()) goto end;
    else if (sub == full.substr(0, min)) return count;
    else {
        count++;
        full = full.substr(1);
        count = index_of(sub, full, count);
        return count;
    }
end: return -1;
}
