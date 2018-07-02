#include <iostream>
#include <fstream>
#include  <deque>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

void alterParticle(string&);

int main(){

   string tmp_str;
   deque<string> d;
   list<string> l;

   ifstream in("foo.txt");
   if(!in.is_open()){
      cout << "Error opening file" << endl;
      return 1;
   }
   while(in){
      getline(in,tmp_str);
      d.push_back(tmp_str);
   }

   for_each(d.begin(),d.end(),alterParticle);

   copy(d.begin(),d.end(),ostream_iterator<string>(cout,"\n"));

   ostream_iterator<string> out(cout,"\n");
   copy_if(d.begin(),d.end(),out,
         [](const string& s){
            if(s.find("fooparticle")!= string::npos)
               return true;
            return false;
         });

   copy_if(d.begin(),d.end(),back_inserter(l),
      [](const string& s){
         if(s.find("fooparticle")!= string::npos)
            return true;
         return false;
      });

   copy(l.begin(),l.end(),out);

   return 0;
}

void alterParticle(string& s){
   int fpos = s.find("quark");
   string rep_str{"quark"};
   if(fpos != string::npos){
      s.replace(s.find(rep_str),rep_str.length(),"fooparticle");
   }
}
