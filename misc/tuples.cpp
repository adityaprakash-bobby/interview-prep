#include <iostream>
#include <tuple>

int main(int argc, char const *argv[])
{
    std::tuple<int, std::string> tuple1(1, "asdas");
    std::tuple<int, int, std::string> tuple2(1e7, 11, "asdasdas");

    std::cout << "tuple1: " << std::get<0>(tuple1) << " " << std::get<1>(tuple1) << "\n";
    std::cout << "tuple2: " << std::get<0>(tuple2) << " " << std::get<1>(tuple2) << " " << std::get<2>(tuple2) << "\n";

    std::cout << "Tuple size(tuple1): " << std::tuple_size<decltype(tuple1)>::value << "\n";
    std::cout << "Tuple size(tuple2): " << std::tuple_size<decltype(tuple2)>::value << "\n";

    // Concatenation
    auto concatenated_tuple = std::tuple_cat(tuple1, tuple2);
    std::cout << "concatenated_tuple (tuple1 + tuple2): "; 
    std::cout << std::get<0>(concatenated_tuple) << " ";
    std::cout << std::get<1>(concatenated_tuple) << " ";
    std::cout << std::get<2>(concatenated_tuple) << " ";
    std::cout << std::get<3>(concatenated_tuple) << " ";
    std::cout << std::get<4>(concatenated_tuple) << " ";
    std::cout << "\n";

    return 0;
}