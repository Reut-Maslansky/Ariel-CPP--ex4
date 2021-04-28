#include "doctest.h"

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include <iostream>
#include <stdexcept>

using namespace pandemic;
using namespace std;

Board board;

TEST_CASE("OperationsExpert Player")
{
    OperationsExpert player{board, City::Atlanta};
    player.take_card(City::Johannesburg)
        .take_card(City::Khartoum)
        .take_card(City::SaoPaulo)
        .take_card(City::BuenosAires)
        .take_card(City::HoChiMinhCity);

    CHECK(player.role() == string("OperationsExpert"));

    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.fly_direct(City::Khartoum));
    CHECK_NOTHROW(player.fly_direct(City::SaoPaulo));
    CHECK_THROWS(player.fly_direct(City::Khartoum));
    CHECK_NOTHROW(player.drive(City::Lagos));
    CHECK_THROWS(player.drive(City::Algiers));
}

TEST_CASE("Dispatcher Player")
{
    Dispatcher player{board, City::SanFrancisco};
    player.take_card(City::Essen)
        .take_card(City::Jakarta)
        .take_card(City::NewYork)
        .take_card(City::Washington)
        .take_card(City::Madrid);

    CHECK(player.role() == string("Dispatcher"));

    CHECK_NOTHROW(player.fly_direct(City::Washington));
    CHECK_NOTHROW(player.drive(City::Atlanta));
    CHECK_NOTHROW(player.fly_direct(City::Lagos));
    CHECK_THROWS(player.fly_direct(City::SaoPaulo));
    OperationsExpert op{board, City::SaoPaulo};
    CHECK_NOTHROW(op.build());
    CHECK_NOTHROW(player.fly_direct(City::SaoPaulo));
}

TEST_CASE("Scientist Player")
{
    board[City::Miami] = 4;

    Scientist player{board, City::Miami, 3}; //Yellow
    player.take_card(City::Bogota)           //Yellow
        .take_card(City::Atlanta)            //Blue
        .take_card(City::NewYork)            //Blue
        .take_card(City::Riyadh);            //Black

    CHECK(player.role() == string("Scientist"));
    CHECK_THROWS(player.discover_cure(Color::Yellow));
    OperationsExpert op{board, City::Miami};
    op.build();
    CHECK_THROWS(player.discover_cure(Color::Yellow));
    player.take_card(City::Delhi); //Yellow
    CHECK_NOTHROW(player.treat(City::Miami));
    CHECK(board[City::Miami] == 3);
    CHECK_NOTHROW(player.discover_cure(Color::Yellow));
    CHECK_NOTHROW(player.treat(City::Miami));
    CHECK_FALSE(!board.is_clean());
}

TEST_CASE("Researcher Player")
{
    board[City::HongKong] = 3;

    Researcher player{board, City::HongKong}; //Red
    player.take_card(City::Shanghai)          //Red
        .take_card(City::Osaka)               //Red
        .take_card(City::Tokyo)               //Red
        .take_card(City::Beijing);            //Red

    CHECK(player.role() == string("Researcher"));
    CHECK_NOTHROW(player.treat(City::HongKong));
    CHECK(board[City::HongKong] == 2);
    CHECK_NOTHROW(player.discover_cure(Color::Red));
    CHECK_NOTHROW(player.treat(City::HongKong));
    CHECK(board[City::HongKong] == 0);
    CHECK_THROWS(player.treat(City::HongKong));
}

TEST_CASE("Medic Player")
{
    board[City::SanFrancisco] = 5;

    Medic player{board, City::SanFrancisco};
    player.take_card(City::Shanghai)
        .take_card(City::Osaka)
        .take_card(City::Tokyo)
        .take_card(City::Beijing);

    CHECK(player.role() == string("Medic"));
    CHECK_NOTHROW(player.treat(City::SanFrancisco));
    CHECK(board[City::SanFrancisco] == 0);

    board[City::Tokyo] = 3;
    CHECK_NOTHROW(player.fly_direct(City::Tokyo));
    CHECK(board[City::Tokyo] == 0);

    board[City::Osaka] = 4;
    CHECK_NOTHROW(player.drive(City::Osaka));
    CHECK(board[City::Osaka] == 0);

    player.take_card(City::Osaka);
    board[City::Tehran] = 4;
    CHECK_NOTHROW(player.fly_charter(City::Tehran));
    CHECK(board[City::Tehran] == 0);

    board[City::Miami] = 7;
    CHECK_NOTHROW(player.fly_shuttle(City::Miami));
    CHECK(board[City::Miami] == 0);
}

TEST_CASE("Virologist Player")
{
    Virologist player{board, City::SanFrancisco};
    player.take_card(City::Essen)
        .take_card(City::Lima)
        .take_card(City::NewYork)
        .take_card(City::Lagos)
        .take_card(City::Madrid);

    CHECK(player.role() == string("Virologist"));

    board[City::Lagos] = 7;
    CHECK_NOTHROW(player.treat(City::Lagos));
    CHECK(board[City::Lagos] == 6);
}

TEST_CASE("GeneSplicer Player")
{
    GeneSplicer player{board, City::HoChiMinhCity};
    player.take_card(City::Essen)
        .take_card(City::Lima)
        .take_card(City::HoChiMinhCity)
        .take_card(City::Lagos);

    CHECK(player.role() == string("GeneSplicer"));

    board[City::HoChiMinhCity] = 6;
    CHECK_NOTHROW(player.fly_direct(City::HoChiMinhCity));
    CHECK_NOTHROW(player.treat(City::HoChiMinhCity));
    CHECK(board[City::HoChiMinhCity] == 5);

    CHECK_NOTHROW(player.build());
    player.take_card(City::HoChiMinhCity);

    CHECK_NOTHROW(player.discover_cure(Color::Red));
    CHECK_NOTHROW(player.treat(City::HoChiMinhCity));
    CHECK(board[City::HoChiMinhCity] == 0);
}

TEST_CASE("FieldDoctor Player")
{
    FieldDoctor player{board, City::Kolkata};
    player.take_card(City::Karachi)
        .take_card(City::HongKong)
        .take_card(City::Lagos);

    CHECK(player.role() == string("FieldDoctor"));

    board[City::Chennai] = 6;
    CHECK_NOTHROW(player.treat(City::Chennai));
    CHECK(board[City::Chennai] == 5);
}