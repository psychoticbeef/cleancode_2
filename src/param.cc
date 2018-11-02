#include "param.hh"

Param::Param() : m_csv_filename() {

}

void Param::parse(int argc, char * argv[]) {
    if (argc == 2) {
        m_csv_filename = std::string(argv[1]);
    }
}

std::string& Param::get_csv_filename() {
    return m_csv_filename;
}
