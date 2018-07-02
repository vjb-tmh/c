#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){

   string s;

   cout << "Enter anything, or 'q' to quit" << endl;

   while(getline(cin,s)){
      cout << "Your input is:" << s << endl;
      if(s == "q")
         break;
   }

   return 0;
}
