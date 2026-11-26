#include "parser.h"
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

class Parser {
public:
    std::vector<std::string> get_script_map(const std::vector<std::string>& script_reader_map) {
        std::string file_path = "main.xes";
        std::ifstream file(file_path);
        if (!file.is_open()) {
            std::cerr << "file does not exist" << std::endl;
            return {};  
        }

        std::vector<std::string> result;
        std::string line_analysis;
        while (std::getline(file, line_analysis)) {
            std::cout << line_analysis << std::endl;
            result.push_back(line_analysis);
        }
        file.close();

        return result;
    }
};

int main() {
    Parser parser;
    std::vector<std::string> dummy;
    parser.get_script_map(dummy);
    return 0;
}
