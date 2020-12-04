#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <array>

int move(const std::vector<std::string> &map, const int r_steps, const int d_steps) {
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
    return count_trees;
}

int main() {
    std::vector<std::string> map;
    std::fstream in_file;
    in_file.open("input.txt");
    std::string line;

    while(std::getline(in_file, line)) {
        map.emplace_back(line);
    }
    constexpr std::array<std::array<int, 2>, 5> slopes{{{1, 1}, {1, 3}, {1, 5}, {1, 7}, {2, 1}}};
    unsigned int result = 1;
    for (int i = 0; i < slopes.size(); i++) {
        result *= move(map, slopes[i][1], slopes[i][0]);
    }
    std::cout<<result<<"\n";
    return 0;
}