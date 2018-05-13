#ifndef AMOBA_VIEW_H_INCLUDED
#define AMOBA_VIEW_H_INCLUDED

#include "graphics.hpp"
#include "amoba_logic.h"
#include "amoba_widget.h"

class amoba_view
{
    amoba_widget* amoba_w;

public:
    amoba_view(int _pixel_w, int _pixel_h);
    virtual ~amoba_view();

    void event_loop();

protected:
    int pixel_w, pixel_h;
};

#endif // AMOBA_VIEW_H_INCLUDED
