//
// Created by soumya on 1/15/18.
//
#include <string>
#include <iostream>

using namespace std;
class ReverseWordsinString {
public:
    void reverse(string &s, size_t begin, size_t end)
    {
      while(begin<end)
      {
          //swap(s[begin],s[end]);
          auto t=s[end]; s[end]=s[begin];s[begin]=t;
          begin++; end--;
      }
    }
    void reverseWords(basic_string<char> &s) {
        size_t beg = 0, end = s.length();
        if (end!=0)
            reverse(s, beg,end-1);

        while (beg < s.length())
        {
            if(s[beg]==' ')
            {
                s.erase(beg,1);
                continue;
            }
            end = s.find_first_of(" ",beg);
            end = end<s.length()?end:s.length();//handle reversing last word

            //end = end==0?end+1:end;// first char is space or empty string

            reverse(s,beg,end-1);
            beg=end+1;
        }
        s.erase(s.find_last_not_of(' ')+1);

        cout << s;
    }
};

int main() {
    ReverseWordsinString r;
    string s = "  ";
    //string s = string("This is a test");
    //string s = string("CC  DD");
    r.reverseWords(s);
    cout<<"*"<<s<<"*";
}

