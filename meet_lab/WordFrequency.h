#ifndef WORDFREQUENCY_H
#define WORDFREQUENCY_H

#include <map>
#include <string>

class WordFrequency {
private:
    std::map<std::string, int> wordFreq;
    int count = 0;

    void parseLine(std::string line);

public:
    void checkFrequency(std::string inputFile);

    void printFrequency(std::string outputFile);
};

#endif //WORDFREQUENCY_H
