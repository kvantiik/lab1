#include "WordFrequency.h"
#include <string>

int main(int argc, char *argv[]) {
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    WordFrequency wf;
    wf.checkFrequency(inputFile);
    wf.printFrequency(outputFile);

    return 0;
}
