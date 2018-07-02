#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

class Particle {

   private:
      int spin;
      float mass;
      string type;

   public:
      // constructor
      Particle() : spin(0), mass(0), type("blank"){}

      // parameterized constructor
      Particle(int s, float m, string t)
         : spin(s), mass(m), type(t)
      {}

      // copy constructor
      Particle(const Particle& p){
         this->spin = p.getSpin();
         this->mass = p.getMass();
         this->type = p.getType();
      }

      // assignment operator
      const Particle& operator=(const Particle& p){
         this->spin = p.getSpin();
         this->mass = p.getMass();
         this->type = p.getType();
      }

      // getters
      int getSpin() const {return spin;}
      float getMass() const {return mass;}
      string getType() const {return type;}

      // comparison
      bool operator==(const Particle &rhs) const {
         return (this->type == rhs.type);
      }
};

// overload << to print user defined objects with copy()
ostream& operator<<(ostream& os, const Particle& p){
   os << p.getType() << " " << p.getMass();
   return os;
}

// graviton generator
Particle genParticle(){
   Particle p(7,2.2,"graviton");
   return p;
}

// print deque
void printDeque(const deque<Particle>& d){
   for(auto itr = d.begin(); itr != d.end(); itr++) {
      cout << "Spin: " << itr->getSpin() << " Mass: "
         << itr->getMass() << " Type: " << itr->getType() << "\n";
   }
}

int main(){

   deque<Particle> d;
   Particle p1(3,4.5,"neutron");
   Particle p2(4,5.6,"proton");
   Particle p3(1,2.7,"electron");

   cout << endl << "[Initialize Deque]" << endl;
   d.insert(d.begin(),p1);
   d.push_back(p2);
   d.insert(d.begin()+1,p3);
   printDeque(d);

   // find and erase
   cout << endl << "[Find and Erase]" << endl;;
   auto fitr = find(d.begin(),d.end(),p3);
   d.erase(fitr);
   printDeque(d);

   // copy constructor
   cout << endl << "[Copy Constructor]" << endl;;
   Particle p5(p1);
   d.push_front(p1);
   printDeque(d);

   // assignment operator
   cout << endl << "[Assignment Operator]" << endl;;
   p1 = p2;
   d.push_back(p1);
   printDeque(d);

   // replace
   cout << endl << "[Replace]" << endl;
   replace(d.begin(),d.end(),p1,p3);
   printDeque(d);

   // copy
   cout << endl << "[Copy and Print]" << endl;
   int arr[] = {6,3,5,2,9};
   deque<int> dInt(5);
   copy(arr,arr+5,dInt.begin());

   // print contents using copy
   ostream_iterator<int> outItr(cout," ");
   copy(dInt.begin(),dInt.end(),outItr);
   cout << endl;

   // swap
   cout << endl << "[Swap]" << endl;
   deque<Particle> d2;
   Particle p4(7,8.8,"grizzly");
   d2.push_back(p4);

   swap(d,d2);
   for(auto p : d2)
      cout << p.getType() << endl;
   for(auto p : d)
      cout << p.getType() << endl;

   // sort
   cout << endl << "[Sort]" << endl;
   sort(d2.begin(),d2.end(),
         [](Particle p1, Particle p2)->bool
         {return p1.getType() < p2.getType();});
   for(auto x : d2)
      cout << x.getType() << endl;

   // max/min
   cout << endl << "[Max]" << endl;
   auto mitr = max_element(d2.begin(),d2.end(),
         [](const Particle& p1, const Particle& p2)->bool
         {
            return p1.getMass() < p2.getMass();
         });
   cout << mitr->getType() << " " << mitr->getMass() << endl;

   // fill
   cout << endl << "[Fill]" << endl;
   fill(d2.begin(),d2.end(),p4);
   copy(d2.begin(),d2.end(),ostream_iterator<Particle>(cout,"\n"));

   // generate
   cout << endl << "[Generate]" << endl;
   deque<Particle> d3(4);
   generate(d3.begin(),d3.end(),genParticle);

   // note you need to overload << for
   // printing user defined objects with copy
   copy(d3.begin(),d3.end(),
         ostream_iterator<Particle>(cout, "\n"));


   return 0;
}
