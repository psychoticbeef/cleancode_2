#include "app.hh"

int main(int argc, char * argv[]) {
    Param p;
    p.parse(argc, argv);
    App app(p);
    app.start();
}
