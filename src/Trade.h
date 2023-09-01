#pragma once

#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>

#include "utility.h"

struct Trade {
    std::time_t m_positionOpenTime;
    std::string m_currency;
    std::string m_positionDirection;
    double      m_entryPrice;
    double      m_stopLoss;
    double      m_takeProfit;
    float       m_posSizeUSDT;
    int         m_leverage;
    float       m_PNLperc;
    double      m_PNL;
    std::string m_whyOpen;
    std::string m_whyResult;

	friend std::ostream& operator<<(std::ostream& os, const Trade& obj) {
		char bufferTime[80];
		std::strftime(bufferTime, sizeof(bufferTime), "%Y-%m-%d %H:%M:%S", std::localtime(&obj.m_positionOpenTime));
		os << std::setw(DATE_W) << bufferTime
		<< std::setw(SYMB_W) << obj.m_currency
		<< std::setw(LS_W) << obj.m_positionDirection
		<< std::setw(EP_W) << obj.m_entryPrice
		<< std::setw(SL_W) << obj.m_stopLoss
		<< std::setw(TP_W) << obj.m_takeProfit
		<< std::setw(PS_W) << obj.m_posSizeUSDT
		<< std::setw(LEV_W) << obj.m_takeProfit
		<< std::setw(PNL_P_W) << obj.m_PNLperc
		<< std::setw(PNL_W) << obj.m_PNL
		<< std::endl << "Why open? : " << obj.m_whyOpen
		<< std::endl << "Why result? : " << obj.m_whyResult
		<< std::endl;

		return os;
	}
};
