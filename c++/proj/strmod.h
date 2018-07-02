#ifndef STRMOD
#define STRMOD

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

namespace strmod {

class StrMod{

   public:
      int parse(string, const string&, vector<string>&);
      string join(const vector<string>&,const string&) const;
      int reverse(string&);
      bool contains(const string&,const string&) const;
      int replace(string&,const string&, const string&);
      int replace_n(string&, const string &, const string&, int n);
      int replace_first(string&,const string&, const string&);
      int replace_last(string&,const string&, const string&);
      int insert_front(string&,const string&, const string&);
      int insert_front_n(string&,const string&, const string&, int);
      int insert_front_all(string&,const string&, const string&);
      int insert_back(string&,const string&, const string&);
      int insert_back_n(string&,const string&, const string&, int);
      int insert_back_all(string&,const string&, const string&);
};

#include "strmod.hpp"

}

#endif
