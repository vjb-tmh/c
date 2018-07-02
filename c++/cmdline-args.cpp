#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){

   cout << "Number of cmd line args: " << argc << endl;

   cout << "Executable name: " << argv[0] << endl;

   cout << "Arguments entered: ";
   for(int i = 1; i < argc; i++)
      cout << argv[i] << " ";
   cout << endl;

   return 0;
}
