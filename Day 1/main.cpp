#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>


struct list {
    std::vector<std::string> left, right;
};

typedef struct list List;

list read_file(const std::string& filename) {
    std::ifstream file(filename);
    List list;
    std::string left, right;

    if (!file.is_open()) {
        std::cerr << "Error opening the file!\n";
        return list;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);

        if (std::getline(iss, left, ' ') && std::getline(iss, right)) {
            list.left.push_back(left);
            list.right.push_back(right);
        }
    }

    file.close();
    return list;
}

void print_list(const List& list) {
    for (int i = 0; i < list.right.size(); i++) {
        std::cout << list.left[i] << ":" << list.right[i] << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    
    List input = read_file(argv[1]);

    std::sort(input.left.begin(), input.left.end());
    std::sort(input.right.begin(), input.right.end());

    int distance = 0;
    for (int i = 0; i < std::min(input.left.size(), input.right.size()); i++) {
        distance += std::abs(stoi(input.left[i]) - stoi(input.right[i]));
    }
    
    print_list(input);

    std::cout << distance << std::endl;
    return 0;
}


