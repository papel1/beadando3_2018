#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

using namespace genv;
using namespace std;

class Widget
{
protected:
    int _x, _y, _size_x, _size_y;

public:
    bool _focus;

    Widget(int x, int y, int sx, int sy);

    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw() const;
    virtual void handle(event ev);
    virtual void pushb(string);
    //virtual void Remo();
    virtual string getData();
};

#endif // WIDGETS_HPP_INCLUDED
