#include "amoba_view.h"
#include "amoba_widget.h"

using namespace genv;
using namespace std;

amoba_view::amoba_view(int _pixel_w, int _pixel_h)
{
    //this->pixel_h=pixel_h;
    pixel_h=_pixel_h;
    pixel_w=_pixel_w;

    gout.open(_pixel_w, _pixel_h);
    amoba_w=new amoba_widget(0, 100, pixel_w, pixel_h-100, 20);
    amoba_w->draw();
}

amoba_view::~amoba_view(){}

///-------------------------------------------------------------------------------------------------------------------

void amoba_view::event_loop()
{
    event ev;

    while(gin>>ev)
    {
        amoba_w->handle(ev);
        gout<<refresh;
    }
}
