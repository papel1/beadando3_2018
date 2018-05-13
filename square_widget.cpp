#include "square_widget.h"

#include <iostream>

using namespace genv;
using namespace std;

square_widget::square_widget(int x, int y, int sx, int sy):Widget(x, y, sx, sy){}
square_widget::~square_widget(){}

///----------------------------------------------------------------------------------------------------------------------------------------

void square_widget::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y )
    <<move_to(_x+1, _y+1) << color(0,0,0) << box(_size_x-1, _size_y-1 );
}

void square_widget::set_text(string v, color c)
{
    curr_text=v;
    gout.load_font("LiberationSans-Regular.ttf",25,0);
    gout << move_to(_x+(_size_x/6), _y) << c << text(v);
}

void square_widget::set_textcolor(color c)
{
    set_text(curr_text, c);
}
