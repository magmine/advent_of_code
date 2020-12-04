#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <array>

int main() {
    std::vector<std::string> map;
    std::fstream in_file;
    in_file.open("input.txt");
    std::string line;

    while(std::getline(in_file, line)) {
        map.emplace_back(line);
    }

    const int r_steps = 3;
    const int d_steps = 1;
    std::array<int, 2> curr_pos{0, 0};
    int count_trees = 0;

    while (curr_pos[0] < map.size()) {
        curr_pos[1] = (curr_pos[1] + r_steps) % map[0].size();
        curr_pos[0] += d_steps;
        if (curr_pos[0] < map.size()) {
            if (map[curr_pos[0]][curr_pos[1]] == '#') count_trees++;
        } else {
            break;
        }
    }
    std::cout<<count_trees<<"\n";
    return 0;
}