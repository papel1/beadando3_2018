#include "amoba_widget.h"
#include "graphics.hpp"

#include <iostream>

using namespace genv;
using namespace std;

amoba_widget::amoba_widget(int x, int y, int sx, int sy, int table_size):Widget(x, y, sx, sy)
{
    this->table_size=table_size;
    logic=new amoba_logic(table_size, table_size);

    for(int i_y=0; i_y<table_size; i_y++)
    {
        int pixel_y=(_size_y/table_size)*i_y+_y;
        vector<square_widget> line;

        for(int i_x=0; i_x<table_size; i_x++)
        {
            int pixel_x=(_size_x/table_size)*i_x;
            square_widget sw(pixel_x, pixel_y, _size_x/table_size, _size_y/table_size);
            line.push_back(sw);
        }

        square_matrix.push_back(line);
    }
}

amoba_widget::~amoba_widget()
{
    delete logic;
}

///---------------------------------------------------------------------------------------------------------------------

void amoba_widget::draw()
{
    for(int i=0; i<table_size; i++)
    {
        for(int j=0; j<table_size; j++)
        {
            if(logic->get_value(i, j)==0)
            {
                square_matrix.at(i).at(j).draw();
            }else if(logic->get_value(i, j)==1)
            {
                square_matrix.at(i).at(j).set_text("X", color(255,0,0));
            }else if(logic->get_value(i, j)==2)
            {
                square_matrix.at(i).at(j).set_text("O", color(0,200,255));
            }else if(logic->get_value(i, j)==3)
            {
                square_matrix.at(i).at(j).set_textcolor(color(0,255,0));
            }
        }
    }
}

void amoba_widget::handle(event ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left)
    {
        for(int i=0; i<table_size; i++)
        {
            for(int j=0; j<table_size; j++)
            {
                if(square_matrix.at(i).at(j).is_selected(ev.pos_x, ev.pos_y))
                {
                    logic->set_value(i, j);
                    draw();
                }
            }
        }

        if(logic->is_fulltable() && !logic->is_win())
        {
            logic->set_matrix_defvalue();
            draw();
        }else if(logic->is_win())
        {
            draw();
        }
    }
}
