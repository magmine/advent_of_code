#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<int> input;
    
    int number;
    while (std::cin>>number) {
        input.push_back(number);
    }
    
    std::sort(input.begin(), input.end());
    for (int i = 0; i < input.size(); i++) {
        bool found = std::binary_search(input.begin() + i + 1, input.end(), 2020 - input[i]);
        if (found) {
            return (input[i] * (2020 - input[i]));
        }
    }
    return 0;
}
