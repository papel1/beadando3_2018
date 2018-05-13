#ifndef SQUARE_WIDGET_H_INCLUDED
#define SQUARE_WIDGET_H_INCLUDED

#include "../widgets.hpp"

using namespace std;

class square_widget: public Widget
{
public:
    square_widget(int x, int y, int sx, int sy);
    virtual ~square_widget();

    void draw();
    void set_text(string v, color c);
    void set_textcolor(color c);

protected:
    string curr_text;
};

#endif // SQUARE_WIDGET_H_INCLUDED
