#include "WordFrequency.h"
#include <fstream>
#include <list>
#include <string>
#include <map>

void WordFrequency::parseLine(std::string line) {
    std::string word;

    for (int i = 0; i < line.length(); i++) {
        char lettter = line[i];

        if ((lettter >= 'a' && lettter <= 'z') || (lettter >= 'A' && lettter <= 'Z') || (
                lettter >= '0' && lettter <= '9')) {
            word += lettter;
        } else {
            if (!word.empty()) {
                wordFreq[word]++;
                count++;
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        wordFreq[word]++;
        count++;
    }
}


void WordFrequency::checkFrequency(std::string inputFile) {
    std::ifstream input(inputFile);
    std::string line;
    while (std::getline(input, line)) {
        parseLine(line);
    }
    input.close();
}

void WordFrequency::printFrequency(std::string outputFile) {
    std::list<std::pair<std::string, int> > sort_freq;

    for (auto it: wordFreq) {
        sort_freq.push_back(it);
    }

    sort_freq.sort([](std::pair<std::string, int> x, std::pair<std::string, int> y) {
        return x.second > y.second;
    });


    std::ofstream output(outputFile);

    for (auto it: sort_freq) {
        double frequency = (double) it.second / count * 100;
        output << it.first << "," << it.second << "," << frequency << "\n";
    }

    output.close();
}
