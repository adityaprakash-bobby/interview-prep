#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  //init a vector to check out the erase function
  std::vector<int> v;

  //push few elements to the vector container
  v.push_back(10);
  v.push_back(20);
  v.push_back(15);
  v.push_back(100);
  v.push_back(25);
  v.push_back(40);

  //iterate over the container to check the elements
  std::cout << "Before erasing:" << std::endl;
  for(auto &val : v) {

    std::cout << "Value -> " << val << std::endl;

  }

  //erase few elements from the container
  v.erase(v.begin() + 3, v.end() - 1);

  //display container after erasing the elements
  std::cout << "\nAfter erasing:" << std::endl;
  for(auto &val : v) {

     std::cout << "Value -> " << val << std::endl;

  }

  return 0;

}
