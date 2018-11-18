/*
 Exercise P10.2.
 Write a recursive function void reverse() that reverses a sentence.
 For example:
 Sentence greeting = new Sentence("Hello!");
 greeting.reverse();
 cout << greeting.get_text() << "\n";
 prints the string "!olleH". Implement a recursive solution by removing the first character, reversing a sentence consisting of the remaining text, and combining the two.
*/

#include <iostream>
#include <string>

using namespace std;

void reverse(string& str);

int main(int argc, const char * argv[]) {
    string x = "hello!";
    reverse(x);
    cout << "string: " << x << endl;
    return 0;
}

void reverse(string& str){
    if (str.size() == 1) str = str;
    else {
        char c = str[0];
        str = str.substr(1);
        reverse(str);
        str = str + c;
    }
}
