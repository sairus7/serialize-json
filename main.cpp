#include "header.hpp"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (int i = 0; i < 100; i++) {
        // std::cout << i << "-----------------------------" << std::endl;
        SlideMeanFilter my_flt(25);
        my_flt.buf = {123, 150243, 777, 666666};

        // std::cerr << my_flt.k << std::endl;
        // std::cerr << my_flt.window << std::endl;
        // std::cerr << my_flt.mean_SUM << std::endl;
        // std::cerr << my_flt.need_restart << std::endl;\
        // for (int i = 0; i < my_flt.buf.size(); i++) {
        //     std::cerr << my_flt.buf[i] << " ";
        // }
        // std::cerr << "\n\n";


        json j_flt = mean_to_json_convert(my_flt);

        serealize_json(j_flt, IFILE_NAME);

        json parsed = deserealize_json(IFILE_NAME);

        SlideMeanFilter flt_parsed = json_to_mean_convert(parsed);

        // std::cerr << flt_parsed.k << std::endl;
        // std::cerr << flt_parsed.window << std::endl;
        // std::cerr << flt_parsed.mean_SUM << std::endl;
        // std::cerr << flt_parsed.need_restart << std::endl;\
        // for (int i = 0; i < my_flt.buf.size(); i++) {
        //     std::cerr << flt_parsed.buf[i] << " ";
        // }
        // std::cerr << "\n\n";
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    std::cout << duration << endl;
}
