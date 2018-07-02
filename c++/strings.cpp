#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

int main(){

   string str{"Time is an illusion. Lunchtime doubly so."};
   string fstr = "doubly";

   // replace char
   replace(str.begin(),str.end(),'T','X');
   cout << str << endl;

   // find and replace char
   auto itr = find(str.begin(), str.end(), 'X');
   (*itr) = 'Y';
   cout << str << endl;

   // replace substr with regex
   string res = regex_replace(str,regex("illusion"),"orca");
   cout << res << endl;

   // reverse
   reverse(str.begin(),str.end());
   cout << str << endl;

   // copy
   string str2;
   str2 = str;
   cout << str2 << endl;

   // access string chars
   for(int i = 0; i < str.length(); ++i){
      if(i%2 == 0)
         str.at(i) = 'x';
   }
   cout << str << endl;

   // first and last char
   cout << str.front() << " " << str.back() << endl;

   // append
   str = str + " wombat";
   cout << str << endl;

   // str length
   str.clear();
   str = "four five six seven eight nine 10 11 12";
   cout << str.length() << endl;

   // test and clear
   if(!str.empty())
      str.clear();

   cout << str << endl;
   str += "1 2 3 4 five six seven";

   // insert behind
   string find_str = "seven";
   str.insert(str.find(find_str)+find_str.length()," wombats");
   cout << str << endl;

   // swap
   string s1 = "foo";
   string s2 = "bar";
   swap(s1,s2);
   cout << s2 << endl;

   // replace all occurrences
   s1 = "foo foo";
   find_str = "foo";
   int i;
   while((i = s1.find(find_str)) != string::npos){
      s1.replace(i,find_str.length(),"bar");
   }

   cout << s1 << endl;

   // substr
   s1 += "bar baz";
   find_str = "baz";
   string subs = s1.substr(s1.find(find_str),find_str.length());

   cout << subs << endl;

   // split string
   string split_str = "1|2|3|4|5";
   string delim = "|";
   string token;
   int pos;

   while((pos = split_str.find(delim)) != string::npos){
      token = split_str.substr(0,pos);
      split_str.erase(0,pos + delim.length());
      cout << token << " ";
   }
   cout << split_str << endl;

   int k = 77;
   cout << to_string(k) + " dragons\n";

   return 0;
}
