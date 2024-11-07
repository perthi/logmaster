// -*- mode: c++ -*-
#pragma once

#ifdef _WIN32
#include <Windows.h>
#endif

/***************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                     ****
****************************************************************************/

/****************************************************************************
*** Copyright(C) 2018  Per Thomas Hille, pth@embc.no                      ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later.See.cpp file for details     ***
*****************************************************************************/


/** @todo the color definitions should be enumerators */

/*Color Definitions using Ansi colors*/
#define A_WHITE        97
#define A_BLACK        30
#define A_GREEN        92
#define A_DARK_GREEN   32
#define A_YELLOW       93
#define A_ORANGE       33
#define A_RED          31
#define A_BLUE         34 
#define A_LIGHT_BLUE   36
#define A_CYAN         96
#define A_PURPLE       95
#define A_GRAY         37

/* Color definitions using RGB format*/
#define C_WHITE        0xFFFFFF
#define C_BLACK        0x000000
#define C_GREEN        0x28ED4D
#define C_DARK_GREEN   0x256E53
#define C_YELLOW       0xF0F70C
#define C_ORANGE       0xEDAF28
#define C_RED          0xED3C28
#define C_BLUE         0x1313F0 
#define C_LIGHT_BLUE   0x6ABCE6
#define C_CYAN         0x28EDE0
#define C_PURPLE       0x7E28ED
#define C_GRAY         0xCFCFCF
#define C_LIGHT_GRAY   0xD8D8D8

/*color definitions for the windows terminal/console
* Here we dont have much resolution/bits to play with, but lets give it a try */
#ifdef _WIN32
#define T_DARK_GREEN  ( FOREGROUND_GREEN )
#define T_GREEN       ( FOREGROUND_GREEN | FOREGROUND_INTENSITY )
//#define T_ORANGE      ( FOREGROUND_GREEN | FOREGROUND_RED  | FOREGROUND_INTENSITY )
#define T_ORANGE      ( FOREGROUND_GREEN | FOREGROUND_RED )
#define T_RED         ( FOREGROUND_RED   | FOREGROUND_INTENSITY ) 
#define T_PURPLE      ( FOREGROUND_BLUE  | FOREGROUND_RED | FOREGROUND_INTENSITY )
#define T_WHITE       ( FOREGROUND_BLUE  | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY )
#define T_YELLOW      ( FOREGROUND_GREEN | FOREGROUND_RED |  FOREGROUND_INTENSITY )
#define T_BLUE        ( FOREGROUND_BLUE  | FOREGROUND_INTENSITY )
#define T_GRAY          ( FOREGROUND_INTENSITY )
#define T_LIGHT_GRAY  ( FOREGROUND_RED  | FOREGROUND_BLUE | FOREGROUND_GREEN )
#define T_CYAN        ( FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY )
#define T_PURPLE      ( FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY )
#else
#define T_DARK_GREEN C_DARK_GREEN
#define T_GREEN      C_GREEN
#define T_ORANGE     C_ORANGE
#define T_RED        C_RED
#define T_PURPLE     C_PURPLE
#define T_WHITE      C_WHITE
#define T_YELLOW     C_YELLOW
#define T_BLUE       C_BLUE
#define T_GRAY         C_GRAY    
#define T_LIGHT_GRAY C_LIGHT_GRAY 
#define T_CYAN       C_CYAN
#define T_PURPLE     C_PURPLE

#endif


#define CONSOLE_DEFAULT T_LIGHT_GRAY


inline int 
Rgb2Ansi(int rgb_code)
{
    switch (rgb_code)
    {
    case C_WHITE :
        return A_WHITE;
    case C_BLACK:    
        return  A_BLACK;
        break;
    case C_GREEN:
        return   A_GREEN;
        break;
    case C_DARK_GREEN:
        return   A_DARK_GREEN;
        break; 
    case C_YELLOW:
        return   A_YELLOW;
        break; 
    case C_ORANGE:
        return   A_ORANGE;
        break; 
    case C_RED:
        return   A_RED;
        break; 
    case C_BLUE:
        return   A_BLUE;
        break; 
    case C_LIGHT_BLUE:
        return   A_LIGHT_BLUE;
        break; 
    case C_CYAN:
        return   A_CYAN;
        break; 
    case C_PURPLE:
        return   A_PURPLE;
        break; 
    case C_GRAY:
        return   A_GRAY;
        break; 
    default:
        return 0;
        break;
    }

}

inline int 
Ansi2Rgb(int rgb_code)
{
    switch (rgb_code)
    {
    case A_WHITE :
        return C_WHITE;
    case A_BLACK:    
        return  C_BLACK;
        break;
    case A_GREEN:
        return   C_GREEN;
        break;
    case A_DARK_GREEN:
        return   C_DARK_GREEN;
        break; 
    case A_YELLOW:
        return   C_YELLOW;
        break; 
    case A_ORANGE:
        return   C_ORANGE;
        break; 
    case A_RED:
        return   C_RED;
        break; 
    case A_BLUE:
        return   C_BLUE;
        break; 
    case A_LIGHT_BLUE:
        return   C_LIGHT_BLUE;
        break; 
    case A_CYAN:
        return   C_CYAN;
        break; 
    case A_PURPLE:
        return   C_PURPLE;
        break; 
    case A_GRAY:
        return   C_GRAY;
        break; 
    default:
        return 0;
        break;
    }

}

