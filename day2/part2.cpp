#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

struct info {
    int min;
    int max;
    char c;
    std::string pswd;

    info() : min(0), max(0), c(' '), pswd("") {}
};

std::ostream& operator<<(std::ostream& os, const info& pswd_info)
{
    return os<<"min: "<<pswd_info.min<<"\nmax: "<<pswd_info.max<<"\nchar: "<<pswd_info.c<<"\npassword: "<<pswd_info.pswd<<"\n";
}

info parse_pswd_policy(const std::string &str) {
    info pswd_info;
    std::size_t pswd_pos = str.find_last_of(' ');
    pswd_info.pswd = str.substr(pswd_pos + 1);
    
    std::string pswd_policy = str.substr(0, pswd_pos - 1);
    std::string char_pattern = pswd_policy.substr(str.find(' ') + 1);
    pswd_info.c = char_pattern[0];
    
    std::string length_info = pswd_policy.substr(0, str.find(' '));
    pswd_info.min = std::stoi(length_info.substr(0, length_info.find('-')));
    pswd_info.max = std::stoi(length_info.substr(length_info.find('-') + 1));
    //std::cout<<pswd_info;
    return pswd_info;
}

bool check_policy_compliance(const std::string &str) {
    info pswd_info = parse_pswd_policy(str);
    if (pswd_info.pswd[pswd_info.min - 1] == pswd_info.c ^ pswd_info.pswd[pswd_info.max - 1] == pswd_info.c){
        return true;
    }
    return false;
}

int main() {
    std::string line;
    std::ifstream myIn;
    myIn.open("input.txt");
    unsigned int counter = 0;  
    while(std::getline(myIn, line)) {
        if (check_policy_compliance(line)) {
            counter++;
        }
    }

    std::cout<<counter<<"\n";
    return 0;
}