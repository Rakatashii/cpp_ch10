/*
 Exercise P10.3.
 Redo Exercise P10.2 with a recursive helper function that reverses a substring of the message text.
*/

#include <iostream>
#include <string>
using namespace std;

void reverse(string& str);
void reverse_substring(string& sub);

int main(int argc, const char * argv[]) {
    string s = "hello world!";
    reverse(s);
    cout << "s = " << s << endl;
    return 0;
}

void reverse(string& str){
    if (str.size() == 1) str = str;
    else {
        char c = str[0];
        string sub = str.substr(1);
        reverse_substring(sub);
        str = sub + c;
    }
}
void reverse_substring(string& sub){
    if (sub.size() == 1) sub = sub;
    else {
        char c = sub[0];
        sub = sub.substr(1);
        reverse_substring(sub);
        sub = sub + c;
    }
}
