#ifndef PARAM_HH
#define PARAM_HH

#include <string>

class Param {
    private:
     std::string m_csv_filename;

    public:
     Param();
     void parse(int argc, char* argv[]);
     std::string& get_csv_filename();
};

#endif
