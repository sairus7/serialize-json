#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "nlohmann/json.hpp"

#define FIRST_FILE   "num1.json"
#define SECOND_FILE   "num2.json"

using json = nlohmann::json;
using namespace std;
using namespace std::chrono;


class A {
public:
	int32_t k;
	A(int window) {
		this->k = window;
	}
    A() {
		this->k             = 987;
	}
    void printSMF() {
        std::cerr << endl;
        std::cerr << "k:\t\t" <<this->k << std::endl;
        std::cerr << "\n\n";
    }

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(A, k);
};
    
class DifFilter {
public:
    int x;
    int y;
    A* ptr;
    DifFilter() {
        this->x = 0;
        this->y = 1;
    }
    void printDIF() {
        cerr << "mama:\t" << x << endl;
        cerr << "papa:\t" << y << endl;
        cerr << "\n\n";
    }
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(DifFilter, x, y);
};


template<class T>
void serealize_json(T* a, std::string fname) {
    std::ofstream out(fname);
    json j;

    to_json(j, *a);

    out << j.dump(4) << std::endl;
    out.close();
}

template<class T>
void deserealize_json(T* b, std::string fname) {
    std::ifstream inp(fname);
    json ji;
    
    inp >> ji;
    from_json(ji, *b);
    return;
}
