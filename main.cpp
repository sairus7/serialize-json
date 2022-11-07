#include "header.hpp"

int main(int argc, char* argv[]) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    A aaa(25);

    serealize_json(&aaa, FIRST_FILE);

    A aParse;

    deserealize_json(&aParse, FIRST_FILE);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << endl << endl;
    std::cout << "Time of working: "<< duration << endl;
}
