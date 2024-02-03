#include <iostream>
#include <fstream>
#include <sstream>

const int kArgumentCount = 4;
const int kFileNameIndex = 1;
const int kSearchStringIndex = 2;
const int kReplaceStringIndex = 3;

int main(int argc, char **argv) {
    if (argc != kArgumentCount) {
        std::cout << "Error: Invalid number of arguments. Usage: " << argv[0] << " <input_file> <search_string> <replace_string>" << std::endl;
        return (1);
    }

    const std::string inputFileName = argv[kFileNameIndex];
    const std::string searchString = argv[kSearchStringIndex];
    const std::string replaceString = argv[kReplaceStringIndex];

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cout << "Error: Unable to open input file '" << inputFileName << "'" << std::endl;
        return (1);
    }

    const std::string outputFileName = inputFileName + ".replace";
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cout << "Error: Unable to create output file '" << outputFileName << "'" << std::endl;
        return (1);
    }

    std::stringstream ss;
    ss << inputFile.rdbuf();


    std::string result = ss.str();
    size_t pos = result.find(searchString);

    while (pos != std::string::npos) {
        result = result.substr(0, pos) + replaceString + result.substr(pos + searchString.length());
        pos = result.find(searchString, pos + searchString.length());
    }

    outputFile << result;

    outputFile.close();
    inputFile.close();

    std::cout << "Replacement completed. Output written to '" << outputFileName << "'" << std::endl;
    return (0);
}
