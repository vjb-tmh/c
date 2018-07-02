#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class myFunctor {
   public:
      void operator()(T x) { cout << x << " "; }
};

int main(){

   srand(time(0));

   vector<int> vec;
   for(int i = 0; i < 10; i++)
      vec.push_back(rand()%100);

   for_each(vec.begin(),vec.end(),myFunctor<int>());

   cout << endl;

   sort(vec.begin(),vec.end(),[](int i, int j) -> bool {return i < j;});
   for_each(vec.begin(),vec.end(),[](int i){cout << i << " ";});

   cout << endl;

   return 0;
}
