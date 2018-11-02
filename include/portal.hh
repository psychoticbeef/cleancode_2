#ifndef PORTAL_HH
#define PORTAL_HH

#include "provider.hh"
#include <algorithm>
#include <iostream>
#include <termios.h>
#include <stdio.h>


class Portal {
   private:
    std::vector<int> get_max_len(Provider::records& r);
    void header(std::vector<int>& lengths);
    void record(Provider::record r, std::vector<int> lengths);

   public:
    enum class Action { first, last, prev, next, exit, goto_page, none };

    void render(Provider::record h, Provider::records& r);
    void render_input();
    Action get_input();

// TERMIOS SHIT

struct termios old, news;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  news = old; /* make new settings same as old settings */
  news.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      news.c_lflag |= ECHO; /* set echo mode */
  } else {
      news.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &news); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void)
{
  return getch_(0);
}
};

#endif
