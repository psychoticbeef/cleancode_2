#include "app.hh"
#include <iostream>

App::App(Param p) : m_param(), m_domain(), m_portal(), m_provider() {
    m_param = p;
}

void App::perform(Portal::Action action) {
    switch (action) {
    case Portal::Action::first: m_domain.first(); break;
    case Portal::Action::next: m_domain.next(); break;
    case Portal::Action::prev: m_domain.prev(); break;
    case Portal::Action::last: m_domain.last(); break;
    case Portal::Action::goto_page: m_domain.goto_page(); break;
    default: return;
    }
}

void App::start() {
    auto csv_filename = m_param.get_csv_filename();
    m_provider.read_records(csv_filename);
    Portal::Action next_action = Portal::Action::first;
    while (next_action != Portal::Action::exit) {
        perform(next_action);
        auto range = m_domain.get_range();
        auto current_records = m_provider.get(range);
        m_portal.render(m_provider.get_header(), current_records);
        m_portal.render_input();
        next_action = m_portal.get_input();
    }
}
