#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortIDAccordingToWeight(const std::vector<int>& weights) {
    
    std::vector<int> ids;
    for (int i = 0; i < weights.size(); i++) {
        ids.push_back(i);
    }

    std::sort(ids.begin(), ids.end(), [&weights](const int& l, const int& r){
        return weights[l] < weights[r];
    });

    return ids;
}

int main(int argc, char const *argv[])
{
    std::vector<int> testWeights = {30, 50, 10};
    std::vector<int> res = sortIDAccordingToWeight(testWeights);

    std::cout << "IDs of weights after sorting:\n";
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << "\n";
    }

    return 0;
}