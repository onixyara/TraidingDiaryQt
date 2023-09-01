#pragma once

#include "Trade.h"
#include <vector>
#include <string>

class Parser {
public:
    Parser(); // create new DB
    Parser(std::string filename); // open and serialize new DB
    ~Parser() = default; // save everything to file

	void testTrades();
    void tradeCreate();
    void deleteTrade();
    void showAllTrades();
	void createJson();
private:
    std::string m_filename;
    std::vector<Trade> m_storage;
};
