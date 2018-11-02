#include "provider.hh"

Provider::record Provider::get_header() {
    return m_header;
}

Provider::records Provider::get_records() {
    return m_records;
}

bool Provider::read_records(std::string file) {
    // file exists return false
    std::fstream filter;
    filter.open(file.c_str(), std::ios::in);
    std::string line;
    while (getline(filter, line)) {
        std::istringstream iss(line);
        std::string s;
        record r;
        while (getline(iss, s, ';')) {
            r.push_back(s);
        }
        m_records.push_back(r);
    }
    filter.close();

    m_header = m_records.at(0);
    m_records.erase(m_records.begin());
    return true;
}

Provider::records Provider::get(std::pair<int, int> range) {
    if (range.first > get_records().size()) {
        range.first = get_records().size() - range.second;
    }
    if (range.first < 0) {
        range.first = 0;
    }
    if (range.first + range.second > get_records().size()) {
        range.second = get_records().size() - range.first;
    }
    records result;
    for (int i = range.first; i < range.second + range.first; i++) {
        result.push_back(get_records().at(i));
    }
    return result;
}
