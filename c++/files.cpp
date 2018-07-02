#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

bool hasQuark(string str){
   if(str.find("quark") != string::npos)
      return true;
   return false;
}

int main(){

   // open file
   ifstream in("foo.txt");
   if(!in.is_open()){
      cout << "Couldn't open file" << endl;
      return 1;
   }

   // read file
   string str;
   vector<string> vStr;
   vStr.reserve(10);
   while(in){
      getline(in,str);
      vStr.push_back(str);
   }
   in.close();

   // print file contents
   copy(vStr.begin(),vStr.end(),ostream_iterator<string>(cout,"\n"));

   // replace_if() to delete quarks
   string s1 = "quark 10 11.4";
   string s2 = "xxx";
   replace_if(vStr.begin(),vStr.end(),hasQuark,s2);

   // output contents to new file
   ofstream out("bar.txt");
   copy(vStr.begin(),vStr.end(),ostream_iterator<string>(out,"\n"));
   out << "graviton " << 9 << " " << 4.3 << "\n";
   out.close();

   return 0;
}
