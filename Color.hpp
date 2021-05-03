#pragma once
#include <iostream>

namespace pandemic
{
    enum class Color
    {
        Blue,
        Yellow,
        Red,
        Black
    };

    static std::string getColor(Color c)
    {
        switch (c)
        {
        case Color::Red:
            return "Red";
            break;
        case Color::Black:
            return "Black";
            break;
        case Color::Blue:
            return "Blue";
            break;
        case Color::Yellow:
            return "Yellow";
            break;
        default:
            break;
        }
    }
}