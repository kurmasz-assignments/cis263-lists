
#include <iostream>
#include "Vector.h"
#include "List.h"
#include "Merge.h"


int main(int argc, char* argv[]) {

 Vector<int> v1;
 v1.push_back(10);
 v1.push_back(20);
 v1.push_back(30);


 for (auto i = v1.begin(); i != v1.end(); ++i) {
   std::cout << *i << " ";
 }
 std::cout << std::endl;

 List<double> l1;
 l1.push_back(1.1);
 l1.push_back(2.2);
 l1.push_back(3.3);

  for (auto i = l1.begin(); i != l1.end(); ++i) {
    std::cout << *i << " ";
  }

  return 0;
}
