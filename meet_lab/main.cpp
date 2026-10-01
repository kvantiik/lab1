#include <map>
#include <string>
#include <list>
#include <fstream>

bool cmp(std::pair<std::string, int> x, std::pair<std::string, int> y){
    return x.second > y.second;
}

int main(int argc, char* argv[]) {

    std::string inp = argv[1];
    std::string outp = argv[2];
    std::ifstream input(inp);

    std::string line;
    std::map<std::string, int> wordFreq;
    int  count = 0;

    while (std::getline(input, line)) {

        std::string word = "";

        for (int i = 0; i < line.length(); i++) {
            char let = line[i];

            if ((let >= 'a' && let <= 'z') || (let >= 'A' && let <= 'Z') || (let >= '0' && let <= '9')) {
                word += let;
            }

            else {
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

    input.close();

    std::list<std::pair<std::string, int>> sort_freq;

    for (auto it : wordFreq) {
         sort_freq.push_back(it);
    }

    sort_freq.sort(cmp);

    std::ofstream output(outp);

    for (auto it :  sort_freq) {
        double p = (double)it.second / count * 100;
        output << it.first <<  "," << it.second << "," << p << "\n";
    }

    output.close();

    return 0;
}