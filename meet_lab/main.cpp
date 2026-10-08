#include <map>
#include <string>
#include <list>
#include <fstream>

class WordFreq {
private:
    std::map<std::string, int> wordFreq;
    int count = 0;

    void parseLine(std::string line) {
        std::string word;

        for (int i = 0; i < line.length(); i++) {
            char let = line[i];

            if ((let >= 'a' && let <= 'z') || (let >= 'A' && let <= 'Z') || (let >= '0' && let <= '9')) {
                word += let;
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

public:
    void checkFrequency(std::string inp) {
        std::ifstream input(inp);
        std::string line;
        while (std::getline(input, line)) {
            parseLine(line);
        }
        input.close();
    }

    void printFrequency(std::string outp) {
        std::list<std::pair<std::string, int> > sort_freq;

        for (auto it: wordFreq) {
            sort_freq.push_back(it);
        }

        sort_freq.sort([](std::pair<std::string, int> x, std::pair<std::string, int> y) {
            return x.second > y.second;
        });


        std::ofstream output(outp);

        for (auto it: sort_freq) {
            double p = (double) it.second / count * 100;
            output << it.first << "," << it.second << "," << p << "\n";
        }

        output.close();
    }
};


int main(int argc, char *argv[]) {
    std::string inp = argv[1];
    std::string outp = argv[2];

    WordFreq wf;
    wf.checkFrequency(inp);
    wf.printFrequency(outp);

    return 0;
}
