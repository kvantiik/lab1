#include <iostream>
#include "WordFrequency.h"
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << "  input.txt  output.csv" << std::endl;
        return 1;
    }
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    WordFrequency wf;
    wf.checkFrequency(inputFile);
    wf.printFrequency(outputFile);

    return 0;
}
