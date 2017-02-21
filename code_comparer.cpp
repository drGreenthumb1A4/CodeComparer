#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[]) {
    if(argc < 3) {
        std::cerr << "Not enough files provided" << "\n";
        return 0;
    }
    if(argc > 3){
        std::cout << "Too many files provided" << "\n";
        std::cout << "Comparing first and second" << "\n";
    }
    ifstream a (argv[1], ifstream::in), b (argv[2], ifstream::in);
    stringstream prvi, drugi;
    string f;
    if (a.is_open()){
        while(getline(a, f)){
            f.erase(remove_if(f.begin(), f.end(),  static_cast<int(*)(int)>(isspace)),f.end());
            prvi << f;
        }
        a.close();
    }
    else
        cout << "First file empty or not available" << endl;

    if (b.is_open()){
        while(getline(b, f)){
            f.erase(remove_if(f.begin(), f.end(),  static_cast<int(*)(int)>(isspace)),f.end());
            drugi << f;
        }
        b.close();
    }
    else
        cout << "Second file empty or not available" << endl;


    string fst = prvi.str();
    string snd = drugi.str();

    unsigned int fC = fst.size() - 1;
    unsigned int sC = snd.size() - 1;

    int total = min(fC, sC);
    int counter1 = 0, counter2 = 0;

    for(unsigned int i = 0; i<fC && i<sC; i++){
        if(fst[i] == snd[i]) counter1++;
    }

    while(fC > 0 && sC > 0){
        if(fst[fC] == snd[sC]) counter2++;
        fC--, sC--;
    }

    double rjesenje = ((max((double)counter1, (double)counter2) / (double)total)*100.);

    cout << "Similarity: " << rjesenje << "%" << endl;

    return 0;
}
