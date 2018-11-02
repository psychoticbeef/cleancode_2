#ifndef PROVIDER_HH
#define PROVIDER_HH

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

class Provider {
   public:
    typedef std::vector<std::string> record;
    typedef std::vector<record> records;

    record get_header();
    records get_records();

    bool read_records(std::string file);
    records get(std::pair<int, int>);

   private:
    record m_header;
    records m_records;
};

#endif
