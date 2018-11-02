#include "domain.hh"

Domain::Domain() : m_items_per_page(5) {
}

void Domain::first() {
    m_current_index = 0;
}
void Domain::last() {
    m_current_index = 0;
}
void Domain::next() {
    m_current_index += m_items_per_page;
}
void Domain::prev() {
    m_current_index -= m_items_per_page;
    if (m_current_index < 0) {
        m_current_index = 0;
    }
}

std::pair<int, int> Domain::get_range() {
    return std::make_pair(m_current_index, m_items_per_page);
}
