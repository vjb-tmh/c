#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;

// replace all needles
void repNeedles(string& str){
   string find_str = "needle";
   if(str.find(find_str) != string::npos)
      str.replace(str.find(find_str),find_str.length(),"xxx");
}

int main(){

   deque<string> d;

   ifstream in("strtest.txt");
   if(!in.is_open()){
      cout << "File doesn't exist" << endl;
      return 1;
   }

   string s;
   while(in){
      getline(in,s);
      d.push_back(s);
   }

   // for each string, do the replacement
   for_each(d.begin(),d.end(),repNeedles);

   for(auto s : d)
      cout << s << endl;

   return 0;
}
