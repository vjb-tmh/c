#include "strmod.h"

// split a string
// fill vector<string> with parsed strings
// return: number of strings added to vector on success, -1 on failure
int StrMod::parse(string str, const string& delim, vector<string>& v){
   if(str.empty() || delim.empty()){
      return string::npos;
   }

   int pos, count = 0;
   while((pos = str.find(delim)) != string::npos){
      v.push_back(str.substr(0,pos));
      str.erase(0,pos+delim.length());
      ++count;
   }
   if(!str.empty()){
      v.push_back(str);
      ++count;
   }
   return count;
}

// replace all occurrences of fstr in str with rstr
// return: number of strings replaced on success, -1 on failure
int StrMod::replace(string& str,const string& fstr, const string& rstr){
   if(str.empty() || fstr.empty() ||  rstr.empty() || fstr == rstr)
      return string::npos;

   int pos, count = 0;
   while((pos = str.find(fstr)) != string::npos){
      str.replace(pos,fstr.length(),rstr);
      ++count;
   }
   return count;
}

// replace all occurrences of fstr in str with rstr n times
// return: number of strings replaced on success, -1 on failure
int StrMod::replace_n(string& str, const string& fstr, const string& rstr, int n){
   if(str.empty() || fstr.empty() ||  rstr.empty() || fstr == rstr)
      return string::npos;

   int pos, count = 0;
   while((pos = str.find(fstr)) != string::npos){
      str.replace(pos,fstr.length(),rstr);
      ++count;
      if(count == n)
         break;
   }
   return count;
}

// replace all occurrences of fstr in str with rstr
// return: 1 on success, -1 on failure
int StrMod::replace_first(string& str,const string& fstr, const string& rstr){
   if(str.empty() || fstr.empty() ||  rstr.empty() || fstr == rstr)
      return string::npos;

   int pos;
   if((pos = str.find(fstr)) != string::npos){
      str.replace(pos,fstr.length(),rstr);
      return 1;
   }
   return string::npos;
}

// replace all occurrences of fstr in str with rstr
// return: 1 on success, -1 on failure
int StrMod::replace_last(string& str,const string& fstr, const string& rstr){
   if(str.empty() || fstr.empty() ||  rstr.empty() || fstr == rstr)
      return string::npos;

   string blanks(fstr.length(),' ');

   int pos, lastpos = -1;
   string s = str;
   while((pos = s.find(fstr)) != string::npos){
      s.replace(pos,fstr.length(),blanks);
      lastpos = pos;
   }

   if(lastpos != string::npos){
      str.replace(lastpos,fstr.length(),rstr);
      return 1;
   }
   return string::npos;
}

// reverse a string
int StrMod::reverse(string& s){
   if(s.empty())
      return string::npos;
   std::reverse(s.begin(),s.end());
   return 1;
}

// check if string s contains string c
bool StrMod::contains(const string& s,const string& c) const{
   if(s.empty() || c.empty())
      return false;
   if(s.find(c) != string::npos)
      return true;
   return false;
}

// insert istr in front of fstr
int StrMod::insert_front(string& str,const string& fstr, const string& istr){
   if(str.empty() || fstr.empty() || istr.empty())
      return string::npos;

   int pos;
   if((pos = str.find(fstr)) != string::npos){
      str.insert(pos,istr);
      return 1;
   }
   return string::npos;
}

// insert istr in front of fstr n times
int StrMod::insert_front_n(string& str,const string& fstr, const string& istr, int n){
   if(str.empty() || fstr.empty() || istr.empty())
      return string::npos;

   int pos, spos = 0, count = 0;
   while((pos = str.find(fstr,spos)) != string::npos){
      str.insert(pos,istr);
      spos = pos + fstr.length() + istr.length();
      ++count;
      if(count == n)
         break;
   }
   return 1;
}

// insert istr in front of all fstr in str
int StrMod::insert_front_all(string& str,const string& fstr, const string& istr){
   if(str.empty() || fstr.empty() || istr.empty())
      return string::npos;

   int pos, spos = 0;
   while((pos = str.find(fstr,spos)) != string::npos){
      str.insert(pos,istr);
      spos = pos + fstr.length() + istr.length();
   }

   return 1;
}

// insert istr behind fstr
int StrMod::insert_back(string& str,const string& fstr, const string& istr){
   if(str.empty() || fstr.empty() || istr.empty())
      return string::npos;

   int pos;
   if((pos = str.find(fstr)) != string::npos){
      str.insert(pos+fstr.length(),istr);
      return 1;
   }
   return string::npos;
}

// insert istr in front of fstr n times
int StrMod::insert_back_n(string& str,const string& fstr, const string& istr, int n){
   if(str.empty() || fstr.empty() || istr.empty())
      return string::npos;

   int pos, spos = 0, count = 0;
   while((pos = str.find(fstr,spos)) != string::npos){
      str.insert(pos+fstr.length(),istr);
      spos = pos + fstr.length() + istr.length();
      ++count;
      if(count == n)
         break;
   }
   return 1;
}

// insert istr in front of fstr
int StrMod::insert_back_all(string& str,const string& fstr, const string& istr){
   if(str.empty() || fstr.empty() || istr.empty())
      return string::npos;

   int pos, spos = 0;
   while((pos = str.find(fstr,spos)) != string::npos){
      str.insert(pos+fstr.length(),istr);
      spos = pos + fstr.length() + istr.length();
   }
   return 1;
}

// join strings in a vector separated by sep
string StrMod::join(const vector<string>& v,const string& sep) const{
   string ret{""};
   for(int i = 0; i < v.size(); i++){
      if(i == v.size()-1)
         ret += v.at(i);
      else
         ret += v.at(i) + sep;
   }
   return ret;
}
