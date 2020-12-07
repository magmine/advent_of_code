#include <vector>
#include <iostream>
#include <fstream>
#include <array>
#include <bitset>

int main() {
    std::fstream in_file;
    in_file.open("input.txt");
    std::string line;

    std::bitset<'z' - 'a' + 1> questions{};
    unsigned int count = 0;
    while(std::getline(in_file, line)) {
        if (line.size() > 0) {
            for (auto ch : line) {
                if (!questions.test(ch - 'a')) {
                    count++;
                    questions.set(ch - 'a');
                }
            }
        } else {
            questions.reset();
        }
    }
    std::cout<<count<<"\n";
    return 0;
}