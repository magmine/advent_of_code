#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <array>
#include <bitset>

int process_col_id(const std::string &seat) {
    int col_id = 7;
    int rhs = 7;
    int lhs = 0;
    for (int i = 7; i < seat.size(); i++) {
        if (seat[i] == 'R') {
            lhs = ((lhs + rhs) / 2) + 1;
        } else {
            rhs = ((lhs + rhs) / 2);
        }
    }
    return ((lhs + rhs) / 2);
}

int process_row_id(const std::string &seat) {
    int row_id = 7;
    int rhs = 127;
    int lhs = 0;
    for (int i = 0; i < 7; i++) {
        if (seat[i] == 'B') {
            lhs = ((lhs + rhs) / 2) + 1;
        } else {
            rhs = ((lhs + rhs) / 2);
        }
    }
    return (lhs + rhs) / 2;
}

int process_seat_id(const std::string &seat) {
    int row = process_row_id(seat);
    int col = process_col_id(seat);

    return (8 * row) + col;
}

int main() {
    std::vector<std::string> boarding_passes;
    std::fstream in_file;
    in_file.open("input.txt");
    std::string line;

    while(std::getline(in_file, line)) {
        boarding_passes.emplace_back(line);
    }

    int max_id = 0;
    int min_id = 1e9;
    std::string max_seat;
    std::vector<int> ids(boarding_passes.size());
    for (int i = 0; i < boarding_passes.size(); i++) {
        int seat_id = process_seat_id(boarding_passes[i]);
        max_id = max_id < seat_id ? seat_id : max_id;
        min_id = min_id > seat_id ? seat_id : min_id;
        ids[i] = seat_id;
        max_seat = boarding_passes[i];
    }

    std::sort(ids.begin(), ids.end());
    for (int i = min_id; i <= max_id; i++) {
        if (i - min_id < ids.size()) {
            if (i != ids[i - min_id]) {
                std::cout<<"sol: "<<i<<"\n";
                return 0;
            }
        }
    }
    return 0;
}