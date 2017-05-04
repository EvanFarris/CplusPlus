/*
	Author: Evan Farris
	Date: 05/01/2017
	File: Stock.cpp
	Descr: 
	Implementation file for the stock header
*/

#include "Stock.h"

const float Stock::TAX = 0.15f;
float Stock::getTax() { return TAX; }

Stock::Stock()
{
	tSym = "";
	cName = "";
	sec = static_cast<Sector>(0);	
	numShare = 0;
	purPrice = 0;
	curPrice = 0;
}
Stock::Stock(string tName, string comName, Sector s, int sNum, float pp, float cp)
{
	tSym = tName;
	cName = comName;
	sec = s;
	numShare = sNum;
	purPrice = pp;
	curPrice = cp;
}

float Stock::CurrValue() const
{
	return (numShare * curPrice);
}

Status Stock::CurrStatus() const
{
	if (curPrice > (purPrice + .05))
		return Gain;
	else if (curPrice < (purPrice - .05))
		return Loss;
	else
		return Breakeven;
}

float Stock::GainAmt() const
{
	if (CurrStatus() != Gain)
		return 0.0;
	else
		return (numShare * (curPrice-purPrice));
}

float Stock::TaxGainAmt() const
{
	if (GainAmt() > 0.0)
		return (GainAmt() * TAX);
	else
		return 0.0;
}

Stock & Stock::operator =(const Stock&rhs)
{
	tSym = rhs.tSym;
	cName = rhs.cName;
	sec = rhs.sec;
	numShare = rhs.numShare;
	purPrice = rhs.purPrice;
	curPrice = rhs.curPrice;
	return *this;
}