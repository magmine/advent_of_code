#include <vector>
#include <iostream>
#include <algorithm>
#include <array>

bool ternarySearch(std::vector<int> &array, int start, int end, int rest, std::array<int, 2> &solution) {
    if(start <= end) {
        int midFirst = (start + (end - start) / 3);
        int midSecond = (midFirst + (end - start) / 3);
        if(array[midFirst] + array[midSecond] == rest) {
            solution[0] = array[midFirst];
            solution[1] = array[midSecond];
            return true;
        }
        if(rest < array[midFirst]) {
            return ternarySearch(array, start, midFirst - 1, rest, solution);
        }
        if (rest < array[midSecond]) {
            return ternarySearch(array, start, midSecond - 1, rest, solution);
        }
        
        if(array[midFirst] + array[midSecond] < rest) {
            return ternarySearch(array, start + 1, end, rest, solution);
        } else if (array[midFirst] + array[midSecond] > rest) {
            return ternarySearch(array, start, end - 1, rest, solution);
        }
    }
    return false;
}

int main() {
    std::vector<int> input;
    
    int number;
    while (std::cin>>number) {
        input.push_back(number);
    }
    
    std::sort(input.begin(), input.end());
    std::array<int, 2> solution{};
    for (int i = 0; i < input.size(); i++) {
        bool found = ternarySearch(input, i + 1, input.size(), 2020 - input[i], solution);
        if (found) {
            int result = input[i] * solution[0] * solution[1];
            std::cout<<"result: "<<result<<"\n";
            break;
        }
    }
    return 0;
}

