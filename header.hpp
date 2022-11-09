#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "nlohmann/json.hpp"

#include "msgpack.hpp"

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

    MSGPACK_DEFINE(k);
};
    
class B {
public:
    int x = 0;
    int y = 1;
    A* ptr = nullptr;

    B() {
        this->x = 0;
        this->y = 1;
        ptr = nullptr; //new A{3};
    }
    void printDIF() {
        cerr << "mama:\t" << x << endl;
        cerr << "papa:\t" << y << endl;
        cerr << "\n\n";
    }

    B(A* base) : x(base->k), y(base->k), ptr(base) {}
    //~B() { delete ptr; }

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(B, x, y); 
    //NLOHMANN_DEFINE_TYPE_INTRUSIVE(B, x, y, ptr); - error

    MSGPACK_DEFINE_MAP(x, y);
    //MSGPACK_DEFINE_ARRAY(x, y);
};


template<class T>
void serealize_json(T& a, std::string fname) {
    std::ofstream out(fname);
    json j;

    to_json(j, a);

    out << j.dump(4) << std::endl;
    out.close();
}

template<class T>
void deserealize_json(T& b, std::string fname) {
    std::ifstream inp(fname);
    json ji;
    
    inp >> ji;
    from_json(ji, b);
    return;
}

template<class T>
void serialize_msgpack(T& a, std::string fname) {
    std::ofstream out(fname, std::ios_base::out | std::ios_base::binary);
    msgpack::pack(out, a);
    out.close();
}

template<class T>
void deserialize_msgpack(T& b, std::string fname) {
    std::ifstream inp(fname, std::ios_base::in | std::ios_base::binary);
    std::stringstream ss;
    ss << inp.rdbuf();

    msgpack::unpacked unp;
    msgpack::unpack(unp, ss.str().data(), ss.str().size());
    msgpack::object deserialized = unp.get();
    
    deserialized.convert(b);
}