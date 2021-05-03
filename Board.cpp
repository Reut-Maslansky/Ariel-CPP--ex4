#include "Board.hpp"
#include <iostream>

using namespace std;

namespace pandemic
{
    map<City, int> Board::diseaseLevel = {{City::Algiers, 0}, {City::Atlanta, 0}, {City::Baghdad, 0}, {City::Bangkok, 0}, {City::Beijing, 0}, {City::Bogota, 0}, {City::BuenosAires, 0}, {City::Cairo, 0}, {City::Chennai, 0}, {City::Chicago, 0}, {City::Delhi, 0}, {City::Essen, 0}, {City::HoChiMinhCity, 0}, {City::HongKong, 0}, {City::Istanbul, 0}, {City::Jakarta, 0}, {City::Johannesburg, 0}, {City::Karachi, 0}, {City::Khartoum, 0}, {City::Kinshasa, 0}, {City::Kolkata, 0}, {City::Lagos, 0}, {City::Lima, 0}, {City::London, 0}, {City::LosAngeles, 0}, {City::Madrid, 0}, {City::Manila, 0}, {City::MexicoCity, 0}, {City::Miami, 0}, {City::Milan, 0}, {City::Montreal, 0}, {City::Moscow, 0}, {City::Mumbai, 0}, {City::NewYork, 0}, {City::Osaka, 0}, {City::Paris, 0}, {City::Riyadh, 0}, {City::SanFrancisco, 0}, {City::Santiago, 0}, {City::SaoPaulo, 0}, {City::Seoul, 0}, {City::Shanghai, 0}, {City::StPetersburg, 0}, {City::Sydney, 0}, {City::Taipei, 0}, {City::Tehran, 0}, {City::Tokyo, 0}, {City::Washington, 0}};
    map<City, Color> Board::colors = {{City::Algiers, Color::Black}, {City::Atlanta, Color::Blue}, {City::Baghdad, Color::Black}, {City::Bangkok, Color::Red}, {City::Beijing, Color::Red}, {City::Bogota, Color::Yellow}, {City::BuenosAires, Color::Yellow}, {City::Cairo, Color::Black}, {City::Chennai, Color::Black}, {City::Chicago, Color::Blue}, {City::Delhi, Color::Black}, {City::Essen, Color::Blue}, {City::HoChiMinhCity, Color::Red}, {City::HongKong, Color::Red}, {City::Istanbul, Color::Black}, {City::Jakarta, Color::Red}, {City::Johannesburg, Color::Yellow}, {City::Karachi, Color::Black}, {City::Khartoum, Color::Yellow}, {City::Kinshasa, Color::Yellow}, {City::Kolkata, Color::Black}, {City::Lagos, Color::Yellow}, {City::Lima, Color::Yellow}, {City::London, Color::Blue}, {City::LosAngeles, Color::Yellow}, {City::Madrid, Color::Blue}, {City::Manila, Color::Red}, {City::MexicoCity, Color::Yellow}, {City::Miami, Color::Yellow}, {City::Milan, Color::Blue}, {City::Montreal, Color::Blue}, {City::Moscow, Color::Black}, {City::Mumbai, Color::Black}, {City::NewYork, Color::Blue}, {City::Osaka, Color::Red}, {City::Paris, Color::Blue}, {City::Riyadh, Color::Black}, {City::SanFrancisco, Color::Blue}, {City::Santiago, Color::Yellow}, {City::SaoPaulo, Color::Yellow}, {City::Seoul, Color::Red}, {City::Shanghai, Color::Red}, {City::StPetersburg, Color::Blue}, {City::Sydney, Color::Red}, {City::Taipei, Color::Red}, {City::Tehran, Color::Black}, {City::Tokyo, Color::Red}, {City::Washington, Color::Blue}};
    map<Color, bool> Board::discoverCure = {{Color::Black, false}, {Color::Red, false}, {Color::Blue, false}, {Color::Yellow, false}};
    map<City, bool> Board::researchStation = {{City::Algiers, false}, {City::Atlanta, false}, {City::Baghdad, false}, {City::Bangkok, false}, {City::Beijing, false}, {City::Bogota, false}, {City::BuenosAires, false}, {City::Cairo, false}, {City::Chennai, false}, {City::Chicago, false}, {City::Delhi, false}, {City::Essen, false}, {City::HoChiMinhCity, false}, {City::HongKong, false}, {City::Istanbul, false}, {City::Jakarta, false}, {City::Johannesburg, false}, {City::Karachi, false}, {City::Khartoum, false}, {City::Kinshasa, false}, {City::Kolkata, false}, {City::Lagos, false}, {City::Lima, false}, {City::London, false}, {City::LosAngeles, false}, {City::Madrid, false}, {City::Manila, false}, {City::MexicoCity, false}, {City::Miami, false}, {City::Milan, false}, {City::Montreal, false}, {City::Moscow, false}, {City::Mumbai, false}, {City::NewYork, false}, {City::Osaka, false}, {City::Paris, false}, {City::Riyadh, false}, {City::SanFrancisco, false}, {City::Santiago, false}, {City::SaoPaulo, false}, {City::Seoul, false}, {City::Shanghai, false}, {City::StPetersburg, false}, {City::Sydney, false}, {City::Taipei, false}, {City::Tehran, false}, {City::Tokyo, false}, {City::Washington, false}};
    map<City, set<City>> Board::neighbors = {{City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo}}, {City::Atlanta, {City::Chicago, City::Miami, City::Washington}}, {City::Baghdad, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}}, {City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}}, {City::Beijing, {City::Shanghai, City::Seoul}}, {City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}}, {City::BuenosAires, {City::Bogota, City::SaoPaulo}}, {City::Cairo, {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}}, {City::Chennai, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}}, {City::Chicago, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}}, {City::Delhi, {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}}, {City::Essen, {City::London, City::Paris, City::Milan, City::StPetersburg}}, {City::HoChiMinhCity, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila}}, {City::HongKong, {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}}, {City::Istanbul, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}}, {City::Jakarta, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}}, {City::Johannesburg, {City::Kinshasa, City::Khartoum}}, {City::Karachi, {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}}, {City::Khartoum, {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}}, {City::Kinshasa, {City::Lagos, City::Khartoum, City::Johannesburg}}, {City::Kolkata, {City::Delhi, City::Chennai, City::Bangkok, City::HongKong}}, {City::Lagos, {City::SaoPaulo, City::Khartoum, City::Kinshasa}}, {City::Lima, {City::MexicoCity, City::Bogota, City::Santiago}}, {City::London, {City::NewYork, City::Madrid, City::Essen, City::Paris}}, {City::LosAngeles, {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}}, {City::Madrid, {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}}, {City::Manila, {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}}, {City::MexicoCity, {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}}, {City::Miami, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}}, {City::Milan, {City::Essen, City::Paris, City::Istanbul}}, {City::Montreal, {City::Chicago, City::Washington, City::NewYork}}, {City::Moscow, {City::StPetersburg, City::Istanbul, City::Tehran}}, {City::Mumbai, {City::Karachi, City::Delhi, City::Chennai}}, {City::NewYork, {City::Montreal, City::Washington, City::London, City::Madrid}}, {City::Osaka, {City::Taipei, City::Tokyo}}, {City::Paris, {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}}, {City::Riyadh, {City::Baghdad, City::Cairo, City::Karachi}}, {City::SanFrancisco, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}}, {City::Santiago, {City::Lima}}, {City::SaoPaulo, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}}, {City::Seoul, {City::Beijing, City::Shanghai, City::Tokyo}}, {City::Shanghai, {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}}, {City::StPetersburg, {City::Essen, City::Istanbul, City::Moscow}}, {City::Sydney, {City::Jakarta, City::Manila, City::LosAngeles}}, {City::Taipei, {City::Shanghai, City::HongKong, City::Osaka, City::Manila}}, {City::Tehran, {City::Baghdad, City::Moscow, City::Karachi, City::Delhi}}, {City::Tokyo, {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}}, {City::Washington, {City::Atlanta, City::NewYork, City::Montreal, City::Miami}}};
    map<City, string> Board::getCity = {{City::Algiers, "Algiers"}, {City::Atlanta, "Atlanta"}, {City::Baghdad, "Baghdad"}, {City::Bangkok, "Bangkok"}, {City::Beijing, "Beijing"}, {City::Bogota, "Bogota"}, {City::BuenosAires, "BuenosAires"}, {City::Cairo, "Cairo"}, {City::Chennai, "Chennai"}, {City::Chicago, "Chicago"}, {City::Delhi, "Delhi"}, {City::Essen, "Essen"}, {City::HoChiMinhCity, "HoChiMinhCity"}, {City::HongKong, "HongKong"}, {City::Istanbul, "Istanbul"}, {City::Jakarta, "Jakarta"}, {City::Johannesburg, "Johannesburg"}, {City::Karachi, "Karachi"}, {City::Khartoum, "Khartoum"}, {City::Kinshasa, "Kinshasa"}, {City::Kolkata, "Kolkata"}, {City::Lagos, "Lagos"}, {City::Lima, "Lima"}, {City::London, "London"}, {City::LosAngeles, "LosAngeles"}, {City::Madrid, "Madrid"}, {City::Manila, "Manila"}, {City::MexicoCity, "MexicoCity"}, {City::Miami, "Miami"}, {City::Milan, "Milan"}, {City::Montreal, "Montreal"}, {City::Moscow, "Moscow"}, {City::Mumbai, "Mumbai"}, {City::NewYork, "NewYork"}, {City::Osaka, "Osaka"}, {City::Paris, "Paris"}, {City::Riyadh, "Riyadh"}, {City::SanFrancisco, "SanFrancisco"}, {City::Santiago, "Santiago"}, {City::SaoPaulo, "SaoPaulo"}, {City::Seoul, "Seoul"}, {City::Shanghai, "Shanghai"}, {City::StPetersburg, "StPetersburg"}, {City::Sydney, "Sydney"}, {City::Taipei, "Taipei"}, {City::Tehran, "Tehran"}, {City::Tokyo, "Tokyo"}, {City::Washington, "Washington"}};

    Board::Board() {}

    bool Board::is_clean()
    {
        for (auto it : diseaseLevel)
        {
            if (it.second != 0)
                return false;
        }
        return true;
    }

    int &Board::operator[](City c) { return diseaseLevel.at(c); }

    const int Board::operator[](City c) const { return diseaseLevel.at(c); }

    ostream &operator<<(ostream &os, const Board &b)
    {
        os << "Our Board:" << endl;
        os << "\t\t Disease Levels  |  Research Station:" << endl;
        os << boolalpha;
        for (auto elem : Board::getCity)
        {
            switch (Board::colors.at(elem.first))
            {
            case Color::Red:
                os << "\033[31m";
                break;
            case Color::Yellow:
                os << "\033[33m";
                break;
            case Color::Blue:
                os << "\033[34m";
                break;
            case Color::Black:
                os << "\033[30m";
                break;
            default:
                break;
            }
            os <<"\t" << elem.second << ": \t";
            if(elem.second.length()<6){
                os<<"\t";
            }
            os << Board::diseaseLevel.at(elem.first);
            os << "\t\t" << Board::researchStation.at(elem.first) << endl;
        }
        os << "\033[0m\nDiscovered Cures:" << endl;
        for (auto elem : Board::discoverCure)
        {
            switch (elem.first)
            {
            case Color::Red:
                os << "\033[31m";
                break;
            case Color::Yellow:
                os << "\033[33m";
                break;
            case Color::Blue:
                os << "\033[34m";
                break;
            case Color::Black:
                os << "\033[30m";
                break;
            default:
                break;
            }
            os << "\t" << Board::discoverCure.at(elem.first);
        }
        os << "\033[0m";
        return os;
    }

    void Board::remove_cures()
    {
        discoverCure.at(Color::Red) = false;
        discoverCure.at(Color::Blue) = false;
        discoverCure.at(Color::Black) = false;
        discoverCure.at(Color::Yellow) = false;
    }
};