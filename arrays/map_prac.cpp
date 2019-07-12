#include <iostream>
#include <map>
#include <unordered_map>

int main() {

  std::cout << "Map:" << std::endl;
  //init map variable
  //map variable returns a pair type data
  //
  //pair<int,int> pair_data = make_pair(10,20);
  //
  //pair_data.first -> 10
  //pair_data,second -> 20
  std::map<int, int> map_int_int;

  //add some data into the map structure
  map_int_int[3] = 30;
  map_int_int[1] = 10;
  map_int_int.insert(std::make_pair(4, 40));
  map_int_int[2] = 20;

  //also we can overwrite the keys. This cannot be done 
  //by the insesrt function. It just discards the new value
  //since the key already exists.
  map_int_int[2] = 200;

  //iterate over the map (array of pairs)
  for(auto it = map_int_int.begin(); \
           it != map_int_int.end(); it++) {

    std::cout << it->first << "-->" << it->second << std::endl;

  }

  //you will observe that maps maintain the order of the keys
  std::cout << "\nMultimap:" << std::endl;
  //Now let's check the multimap structure. Similar to the map
  //but allows multiple values to a single key.
  std::multimap<int, int> mmap_int_int;

  //values can be added only using the insert function. It does not
  //support the subscript operator
  mmap_int_int.insert(std::make_pair(2,20));
  mmap_int_int.insert(std::make_pair(1,20));
  mmap_int_int.insert(std::make_pair(1,70));
  mmap_int_int.insert(std::make_pair(1,40));

  //print the multimap using the basic iterator
  for(auto it = mmap_int_int.begin(); \
           it != mmap_int_int.end(); it++) {

    std::cout << it->first << "-->" << it->second << std::endl;

  }

  std::cout << "\nUnordered Map:" << std::endl;
  //Unordered map struture stores data in an unordered fashion
  //like a hashtable. It does not sort the keys.
  std::unordered_map<int, int> umap_int_int;

  //add data into the unordered map
  umap_int_int.insert(std::make_pair(1,10));
  umap_int_int.insert(std::make_pair(2,30));
  umap_int_int[2] = 20;
  umap_int_int[9] = 80;
  umap_int_int[4] = 40;

  //print the unordered map
  for(auto it = umap_int_int.begin(); \
           it != umap_int_int.end(); it++) {

    std::cout << it->first << "-->" << it->second << std::endl;

  }

  std::cout << "\nUnorderd Multimap:" << std::endl;
  //similarly there are unordered multimaps. It's same as doing above.
  //Unordered maps are faster than just maps with time complexity
  //T(n) = O(1) since they are implementations of hashtables
  std::unordered_multimap<int, int> ummap_int_int;

  //insert few key value pairs
  ummap_int_int.insert(std::make_pair(2,20));
  ummap_int_int.insert(std::make_pair(2,200));
  ummap_int_int.insert(std::make_pair(3,30));
  ummap_int_int.insert(std::make_pair(1,10));

  //print the unordered multimap
  for(auto it = ummap_int_int.begin(); \
           it != ummap_int_int.end(); it++) {

    std::cout << it->first << "-->" << it->second << std::endl;

  }

  return 0;

}
