#ifndef APP_HH
#define APP_HH

#include "domain.hh"
#include "param.hh"
#include "portal.hh"
#include "provider.hh"

class App {
    private:
     App();
     Domain m_domain;
     Param m_param;
     Portal m_portal;
     Provider m_provider;

     void perform(Portal::Action action);

    public:
     App(Param p);
     void start();
};

#endif
