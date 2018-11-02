#include "portal.hh"
#include <iostream>

std::vector<int> Portal::get_max_len(Provider::records& r) {
}

void Portal::header(std::vector<int>& lengths) {
    for (const auto &l : lengths) {
        std::cout << "+";
        for (int i = 0; i < l; i++) {
            std::cout << "-";
        }
    }
    std::cout << "+" << std::endl;

}

void Portal::record(Provider::record r, std::vector<int> lengths) {
    for (int i = 0; i < r.size(); i++) {
        std::string s((lengths.at(i) - r.at(i).length()), ' ');
        std::cout << "|" << r.at(i) << s;
    }
    std::cout << "|" << std::endl;
}

void Portal::render(Provider::record h, Provider::records &r) {
    std::vector<int> lengths;
    for (const auto &p : h) {
        lengths.push_back(p.length());
    }
    for (const auto &p : r) {
        for (int i = 0; i < p.size(); i++) {
            if (lengths.at(i) < p.at(i).length()) {
                lengths.at(i) = p.at(i).length();
            }
        }
    }
    header(lengths);
    record(h, lengths);
    header(lengths);
    for (const auto &rs : r) {
        record(rs, lengths);
    }
    header(lengths);
}

void Portal::render_input() {
    std::cout << "F)irst N)ext P)rev L)ast E)xit: " << std::endl;
}

Portal::Action Portal::get_input() {
    auto key = getch();

    switch (key) {
    case 'f': return Action::first;
    case 'n': return Action::next;
    case 'p': return Action::prev;
    case 'l': return Action::last;
    case 'g': return Action::goto_page;
    case 'e': return Action::exit;
    default: return Action::none;
    }
}
