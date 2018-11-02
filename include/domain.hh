#ifndef DOMAIN_HH
#define DOMAIN_HH

#include <tuple>
#include "provider.hh"

class Domain {
   private:
    int m_items_per_page;
    int m_current_index;

   public:
    Domain();
    void first();
    void last();
    void next();
    void prev();
    std::pair<int, int> get_range();
};

#endif
