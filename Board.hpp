#pragma once
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Board
    {
        std::map<City, int> diseaseLevel;
        std::map<City, Color> colors;
        std::map<City, bool> discoverCure;
        std::map<City, bool> researchStation;
        std::map<City, std::set<City>> neighbors;

    public:
        Board();

        bool is_clean();

        int &operator[](City c);

        const int operator[](City c) const;

        friend std::ostream &operator<<(std::ostream &, const Board &);
    };
}