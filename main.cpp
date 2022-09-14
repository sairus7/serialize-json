#include "header.hpp"

int main(int argc, char* argv[]) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    SlideMeanFilter my_mean(25);
    my_mean.buf = {123, 150243, 777, 666666};
    DifFilter       my_dif;

    serialize(my_mean, MEAN_NAME);
    serialize(my_dif, DIF_NAME);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << endl << endl;
    std::cout << "Time of working: "<< duration << endl;
}
