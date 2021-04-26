#pragma once

namespace pandemic
{
    class Board
    {
    public:
        Board();
        bool is_clean();
        int &operator[](City c) const;
        int operator[](City c);
        friend std::ostream &operator<<(std::ostream &, const Board &);
    };
}