#ifndef AMOBA_LOGIC_H_INCLUDED
#define AMOBA_LOGIC_H_INCLUDED

#include <vector>

using namespace std;

class amoba_logic
{
public:
    amoba_logic(int _height, int _width);
    virtual ~amoba_logic();

    void set_value(int x, int y);
    int get_value(int x, int y);
    bool is_fulltable();
    void set_matrix_defvalue();
    void check_row();
    void check_column();
    void check_diagonal();
    void check_win();
    bool is_win();

protected:
    int height, width;
    vector<vector<int> > matrix;
    int curr_value;
    bool win;
};

#endif // AMOBA_LOGIC_H_INCLUDED
