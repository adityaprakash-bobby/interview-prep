#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

void sortVectorFirstVal(std::vector<std::pair<int, int> >& A) {
    sort(A.begin(), A.end(), [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs){
        return lhs.first < rhs.first;
    });
}

void displayVectorPair(const std::vector<std::pair<int, int> >& A) {
    std::cout << "Pair vector:\n";
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i].first << " " << A[i].second << "\n";
    }
}

int main(int argc, char const *argv[])
{
    std::vector<std::pair<int, int> > testVector;
    testVector.push_back(std::make_pair(2, 1));
    testVector.push_back(std::make_pair(1 ,5));
    testVector.push_back(std::make_pair(6 ,3));
    testVector.push_back(std::make_pair(8 ,4));
    testVector.push_back(std::make_pair(3 ,2));

    std::cout << "(Before Sorting)\n";    
    displayVectorPair(testVector);
    std::cout << "\n";

    std::cout << "(After Sorting)\n";    
    sortVectorFirstVal(testVector);
    displayVectorPair(testVector);

    return 0;
}