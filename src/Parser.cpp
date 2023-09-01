#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

#include "Parser.h"
#include "Trade.h"
#include "utility.h"
#include "../inc/json.hpp"

Parser::Parser()
{
    auto now = std::chrono::system_clock::now();

    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm timeInfo = *std::localtime(&time);

    char monthName[20]; // Buffer to store the month names
    std::strftime(monthName, sizeof(monthName), "%B", &timeInfo);
    m_filename = monthName + std::to_string(timeInfo.tm_year + 1900);
}

void Parser::testTrades()
{
	for (int i = 0; i < 4; i++)
	{
		Trade tmp;
		tmp.m_positionOpenTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		tmp.m_currency = "ADA";
		tmp.m_positionDirection = "long";
		tmp.m_entryPrice = 0.235;
		tmp.m_stopLoss = 0.23;
		tmp.m_takeProfit = 0.25;
		tmp.m_posSizeUSDT = 500;
		tmp.m_leverage = 5;
		tmp.m_PNLperc = 2;
		tmp.m_PNL = 200.5;
		tmp.m_whyOpen = "Cause btc hui pizda asdfhjklasdhfkl jashd fkljashd jklfhas dkljfh asjkldh fjklashd ljkfh askdjlhf aklsjdhf laksjdh flkasdh fkajsh ";
		tmp.m_whyResult = "Cause btc hui pizda asdfhjklasdhfkl jashd fkljashd jklfhas dkljfh asjkldh fjklashd ljkfh askdjlhf aklsjdhf laksjdh flkasdh fkajsh ";
		m_storage.push_back(tmp);
	}
}

void Parser::tradeCreate()
{
	Trade newTrade;
	std::string tmp;
	std::cout << "Creating new trade." << std::endl << "Why you open trade?" << std::endl;
	std::getline(std::cin, newTrade.m_whyOpen);
	std::cout << "If time now, type 1, or anything:" << std::endl;
	std::cin >> tmp;
	if (tmp == "1")
	{
		newTrade.m_positionOpenTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	}
	// TODO: write serialize user inp to time_t or just made in qt lately
	std::cout << "Currency name:" << std::endl;
	std::cin >> newTrade.m_currency;
	std::cout << "Long\\short:" << std::endl;
	std::cin >> newTrade.m_positionDirection;
	std::cout << "Entry price:" << std::endl;
	std::cin >> tmp;
	newTrade.m_entryPrice = std::stod(tmp);
	std::cout << "Stop loss:" << std::endl;
	std::cin >> tmp;
	newTrade.m_stopLoss = std::stod(tmp);
	std::cout << "Take profit:" << std::endl;
	std::cin >> tmp;
	newTrade.m_takeProfit = std::stod(tmp);
	std::cout << "Position size:" << std::endl;
	std::cin >> tmp;
	newTrade.m_posSizeUSDT = std::stod(tmp);
	std::cout << "Leverage:" << std::endl;
	std::cin >> tmp;
	newTrade.m_leverage = std::stoi(tmp);
	m_storage.push_back(newTrade);
}

void Parser::createJson()
{
	for (auto a : m_storage)
	{
		nlohmann::json data;
		data["date_open"] = a.m_positionOpenTime;
		data["symbol"] = a.m_currency;
		data["long\\short"] = a.m_positionDirection;

	}
}

void Parser::showAllTrades()
{
	for (size_t i = 0; i < m_storage.size(); i++)
	{
		std::cout << std::left << std::setw(ID_W) << "ID";
		std::cout << std::setw(DATE_W) << "Date open" ;
		std::cout << std::setw(SYMB_W) << "Symbol" ;
		std::cout << std::setw(LS_W) << "Long\\Short" ;
		std::cout << std::setw(EP_W) << "Entry price" ;
		std::cout << std::setw(SL_W) << "Stop loss" ;
		std::cout << std::setw(TP_W) << "Take profit" ;
		std::cout << std::setw(PS_W) << "Position size" ;
		std::cout << std::setw(LEV_W) << "Leverage" ;
		std::cout << std::setw(PNL_P_W) << "PNL %" ;
		std::cout << std::setw(PNL_W) << "PNL" ;
		std::cout << std::endl << std::setw(ID_W) << i + 1 << m_storage[i] << std::endl;
	}
}