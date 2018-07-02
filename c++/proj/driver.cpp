#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include "strmod.h"
using namespace strmod;
using namespace std;

int main(){

   string s = "1|2|3|4|5";
   string d = "|";
   vector<string> v;

   // split str
   StrMod sm;
   sm.parse(s,d,v);

   copy(v.begin(),v.end(),ostream_iterator<string>(cout, " "));

   cout << endl;

   // replace all
   string f = "3";
   string r = "7";
   sm.replace(s,f,r);
   cout << s << endl;

   // replace n
   s.clear();
   s = "1|2|3|4|4|4|4|5";
   f = "4";
   sm.replace_n(s,f,r,2);
   cout << s << endl;

   // reverse
   sm.reverse(s);
   cout << s << endl;

   // check for contains
   string c = "8";
   cout << sm.contains(s,c) << endl;
   c = "7";
   cout << sm.contains(s,c) << endl;

   // replace first
   f = "7";
   r = "99";
   sm.replace_first(s,f,r);
   cout << s << endl;

   // replace last
   f = "4";
   r = "88";
   sm.replace_last(s,f,r);
   cout << s << endl;

   // insert in front
   string i = "foo";
   f = "4";
   sm.insert_front(s,f,i);
   cout << s << endl;

   // insert behind
   i = "bar";
   f = "foo";
   sm.insert_back(s,f,i);
   cout << s << endl;

   // insert front all
   s = "1|2|2|2|2|3|4|5";
   i = "X";
   f = "2";
   sm.insert_front_all(s,f,i);
   cout << s << endl;

   // insert back all
   s = "1|2|2|2|2|3|4|5";
   i = "X";
   f = "2";
   sm.insert_back_all(s,f,i);
   cout << s << endl;

   // insert front n times
   s = "1|2|2|2|2|3|4|5";
   i = "X";
   f = "2";
   sm.insert_front_n(s,f,i,2);
   cout << s << endl;

   // insert front n times
   s = "1|2|2|2|2|3|4|5";
   i = "Y";
   f = "2";
   sm.insert_back_n(s,f,i,2);
   cout << s << endl;

   string sep = "*";
   string ret = sm.join(v,sep);
   cout << ret << endl;

   return 0;
}
