#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::vector<int>> read_file(const std::string& filename) {
    std::fstream file(filename);
    std::vector<std::vector<int>> reports;
    std::vector<int> report;

    if (!file.is_open()) {
        std::cerr << "Error opening the file!\n";
        return reports;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);

        for (std::string level; std::getline(iss, level, ' ');) {
            report.push_back(std::stoi(level));
        }
        reports.push_back(report);
        report.clear();
    }

    file.close();
    return reports;
}

class Part1 {
    bool is_increasing(const std::vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i-1]) {
                return false;
            }
        }
    
        return true; 
    }

    bool is_decreasing(const std::vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] >= nums[i-1]) {
                return false;
            }
        }

        return true;
    }

    bool correct_steps(const std::vector<int>& nums) {
        // correct steps: 1, 2, 3
        for (size_t i = 1; i < nums.size(); i++) {
            if (std::abs(nums[i] - nums[i-1]) > 3) {
                return false;
            }
        }
    
        return true;
    }


    void how_many_safe(std::vector<std::vector<int>>& input) {
        int safe_count = 0;
        for (std::vector<int> report : input) {
            if (is_increasing(report) && correct_steps(report) || is_decreasing(report) && correct_steps(report)) {
                safe_count++;
            }
        }
        std::cout << safe_count << std::endl;
    }
};

class Part2 {
    
};

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> input = read_file(argv[1]);
    how_many_safe(input);
}
