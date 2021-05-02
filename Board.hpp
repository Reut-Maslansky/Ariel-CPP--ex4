#pragma once
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Board
    {
        static std::map<City, int> diseaseLevel;

        static std::map<City, Color> colors;

        static std::map<Color, bool> discoverCure;

        static std::map<City, bool> researchStation;

        static std::map<City, std::set<City>> neighbors;

    public:
        Board();

        bool is_clean();

        int &operator[](City c);

        const int operator[](City c) const;

        friend std::ostream &operator<<(std::ostream &, const Board &);

        void remove_cures();
    };
}