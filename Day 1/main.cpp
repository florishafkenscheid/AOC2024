#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>


struct list {
    std::vector<int> left, right;
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
            list.left.push_back(std::stoi(left));
            list.right.push_back(std::stoi(right));
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

class Part1 {
public:
    void part_1_distance(List list) {
        std::sort(list.left.begin(), list.left.end());
        std::sort(list.right.begin(), list.right.end());

        int distance = 0;
        for (int i = 0; i < std::min(list.left.size(), list.right.size()); i++) {
            distance += std::abs(list.left[i] - list.right[i]);
        }
        std::cout << "Part one: " << distance << std::endl;
    }
};

class Part2 {
public:
    void part_2_sscore(List list) {
        int sscore = 0;

        for (int i = 0; i < std::max(list.left.size(), list.right.size()); i++) {
            int occurrences = find_occurrences_left_in_right(list.left[i], list.right);
            int sscore_addition = list.left[i] * occurrences;
            
            sscore += sscore_addition;
        }

        std::cout << "Part two: " << sscore << std::endl;
    }

    int find_occurrences_left_in_right(int value, std::vector<int> list) {
        auto it = find(list.begin(), list.end(), value);
        std::vector<int> occurrences;

        while (it != list.end()) {
            occurrences.push_back(it - list.begin());

            it = find(it + 1, list.end(), value);
        }
        
        return occurrences.size();
    }
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    
    List input = read_file(argv[1]);

    Part1 part1;
    Part2 part2;

    part1.part_1_distance(input);
    part2.part_2_sscore(input);

    return 0;
}


