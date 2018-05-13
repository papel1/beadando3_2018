#ifndef AMOBA_WIDGET_H_INCLUDED
#define AMOBA_WIDGET_H_INCLUDED

#include "../widgets.hpp"
#include "graphics.hpp"
#include "square_widget.h"
#include "amoba_logic.h"

#include <vector>

using namespace std;

class amoba_widget:public Widget
{
    vector<vector<square_widget> > square_matrix;
    amoba_logic* logic;

public:
    amoba_widget(int x, int y, int sx, int sy, int table_size);
    virtual ~amoba_widget();

    void draw();
    void handle(genv::event ev);

protected:
    int table_size;
};

#endif // AMOBA_WIDGET_H_INCLUDED
