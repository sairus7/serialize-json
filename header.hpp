#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#define OFILE_NAME "my_son.json"
#define IFILE_NAME "test.json"

using json = nlohmann::json;

class SlideMeanFilter {
public:
	std::vector<int32_t> buf;
	int32_t k;
	bool need_restart;
	int window;
	int mean_SUM;

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
};

json mean_to_json_convert(SlideMeanFilter smf) {
    json flt;

    flt["buf"]          = smf.buf;
    flt["k"]            = smf.k; 
    flt["need_restart"] = smf.need_restart;
    flt["window"]       = smf.window;
    flt["mean_SUM"]     = smf.mean_SUM;

    return flt;
}

SlideMeanFilter json_to_mean_convert(json j) {
    SlideMeanFilter flt;
    
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

void serealize_json(json j, std::string fname) {
    std::ofstream out(fname);

    out << j.dump(4) << std::endl;
}

json deserealize_json(std::string fname) {
    std::ifstream inp(fname);
    json ji;
    
    inp >> ji;
    return ji;
}

std::string json_data_str(std::string before, std::vector<int> to_add) {
    for (int i = 0; i < to_add.size(); i++) {
        before += " ";
        before += std::to_string(to_add[i]);
    }

    return before;
}