/*
 Exercise P10.5.
 Use recursion to implement a function bool find(string s, string t)
 that tests whether a string t is contained in a string s:
 bool b = s.find("Mississippi!", "sip"); // Returns true
 Hint: If the text starts with the string you want to match, then you are done. If not, consider the sentence that you obtain by removing the first character.
*/

#include <iostream>
#include <string>

using namespace std;

bool find(string sub, string full);

int main(int argc, const char * argv[]) {
    string full = "Mississipi";
    string sub1 = "sip"; //T
    string sub2 = "pi"; //T
    string sub3 = "sup"; //F
    string sub4 = "ississipi"; //T
    string sub5 = "issi"; //T
    string sub6 = "Mis"; //T
    string sub7 = "ipo"; //F
    bool match1 = find(sub1, full);
    bool match2 = find(sub2, full);
    bool match3 = find(sub3, full);
    bool match4 = find(sub4, full);
    bool match5 = find(sub5, full);
    bool match6 = find(sub6, full);
    bool match7 = find(sub7, full);
    cout << "match1 = " << match1 << endl;
    cout << "match2 = " << match2 << endl;
    cout << "match3 = " << match3 << endl;
    cout << "match4 = " << match4 << endl;
    cout << "match5 = " << match5 << endl;
    cout << "match6 = " << match6 << endl;
    cout << "match7 = " << match7 << endl;
    
    return 0;
}

bool find(string sub, string full){
    int min = sub.length();
    if (full.length() < min) goto end;
    else if (sub == full.substr(0, min)) return true;
    else {
        full = full.substr(1);
        if (find(sub, full)) return true;
    }
end: return false;
}
