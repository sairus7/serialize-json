#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <nlohmann/json.hpp>

#define DIF_NAME    "my_dif.json"
#define MEAN_NAME   "my_mean.json"

using json = nlohmann::json;
using namespace std;
using namespace std::chrono;

namespace mean {
    class SlideMeanFilter {
    public:
    	vector<int32_t>     buf;
    	int32_t             k;
    	bool                need_restart;
    	int                 window;
    	int                 mean_SUM;

    	SlideMeanFilter(int window) {
    		this->window        = window;
    		this->buf.resize(window, 0);
    		this->k             = 123;
    		this->need_restart  = true;
            this->mean_SUM      = 456;
    	}

        SlideMeanFilter() {
    		this->window        = 0;
    		this->buf           = {};
    		this->k             = 987;
    		this->need_restart  = false;
            this->mean_SUM      = 654;
    	}

        void printSMF() {
            std::cerr << endl;
            std::cerr << "k:\t\t" <<this->k << std::endl;
            std::cerr << "window:\t\t" <<this->window << std::endl;
            std::cerr << "mean_sum:\t" <<this->mean_SUM << std::endl;
            std::cerr << "need_rest:\t" <<this->need_restart << std::endl;
            std::cerr << "buf:\t\t";
            for (int i = 0; i < this->buf.size(); i++) {
                std::cerr << this->buf[i] << " ";
            }
            std::cerr << "\n\n";
        }
    };
    
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SlideMeanFilter, buf, k, need_restart,
                                        window, mean_SUM);
}

namespace dif {
    class DifFilter {
    public:
        int         mama;
        int         papa;
        vector<int> iog_satot;
        string      dworf;

        DifFilter() {
            this->mama = 0;
            this->papa = 1;
            this->iog_satot = {123, 456, 888, 5560046};
            this->dworf = "Gimly";
        }

        void printDIF() {
            cerr << "mama:\t" << mama << endl;
            cerr << "papa:\t" << papa << endl;
            cerr << "dworf:\t" << dworf << endl;
            cerr << "iog_satot:\t";
            for (int i = 0; i < iog_satot.size(); i++) {
                cerr << iog_satot[i] << " ";
            }
            cerr << "\n\n";
        }
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(DifFilter, mama, papa,
                                        iog_satot, dworf);
}

using namespace mean;
using namespace dif;

json                    mean_to_json_convert(mean::SlideMeanFilter smf) {
    json flt;

    flt["buf"]          = smf.buf;
    flt["k"]            = smf.k; 
    flt["need_restart"] = smf.need_restart;
    flt["window"]       = smf.window;
    flt["mean_SUM"]     = smf.mean_SUM;

    return flt;
}

mean::SlideMeanFilter   json_to_mean_convert(json j) {
    mean::SlideMeanFilter flt;
    
    flt.k               = j["k"];
    flt.mean_SUM        = j["mean_SUM"];
    flt.window          = j["window"];
    flt.need_restart    = j["need_restart"];
    flt.buf             = {};
    
    for (int i = 0; i < j["buf"].size(); i++) {
        flt.buf.push_back(j["buf"][i]);
    }

    return flt;
}

void                    serealize_json(json j, std::string fname) {
    std::ofstream out(fname);

    out << j.dump(4) << std::endl;
}

json                    deserealize_json(std::string fname) {
    std::ifstream inp(fname);
    json ji;
    
    inp >> ji;
    return ji;
}

template<typename T>
void serialize(T state, string fname) {
    json j;
    to_json(j, state);
    std::ofstream out(fname);

    out << j.dump(4) << std::endl;
}