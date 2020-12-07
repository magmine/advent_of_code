#include <vector>
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

int main() {
    std::fstream in_file;
    in_file.open("input.txt");
    std::string line;

    std::array<int, 'z' - 'a' + 1> questions = {0};
    unsigned int count = 0;
    unsigned int num_pers = 0;
    while(std::getline(in_file, line)) {
        if (line.size() > 0) {
            num_pers++;
            for (auto ch : line) {
                questions[ch - 'a']++;
            }
        } else {
            for (auto val : questions) {
                if (val == num_pers) count++;
            }
            std::fill(questions.begin(), questions.end(), 0);
            num_pers = 0;
        }
    }

    for (auto val : questions) {
        if (val == num_pers) count++;
    }
    std::cout<<count<<"\n";
    return 0;
}