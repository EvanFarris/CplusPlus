/*
	Author: Evan Farris
	File: Stock.h
	Date: 05/01/2017
	Descr:
	Header file for the Stock Abstract Data type
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#ifndef STOCK_H
#define STOCK_H

enum Sector { Technology = 10, Health = 20, Financial = 30, CGoods = 40, Utilities = 50 };
enum Status { Gain, Loss, Breakeven};

class Stock
{
private:
	string tSym;
	string cName;
	Sector sec;
	int numShare;
	float purPrice;
	float curPrice;
	//Static constant for TaxGainAmt()
	static const float TAX;
public:
	Stock();
	Stock(string, string, Sector, int, float, float);
	//mutators
	void setTSym(string s) { tSym = s; }
	void setCName(string c) { cName = c; }
	void setSector(Sector s) { sec=s; }
	void setNumShare(int n) { numShare = n; }
	void setPurPrice(float p) { purPrice = p; }
	void setCurPrice(float curp) { curPrice = curp; }
	//accessors
	string getTSym() { return tSym; }
	string getCName() { return cName; }
	Sector getSector() { return sec; }
	int getNumShare() { return numShare; }
	float getPurPrice() { return purPrice; }
	float getCurPrice() { return curPrice; }
	//static accessor
	static float getTax();
	//behavior
	float CurrValue() const;
	Status CurrStatus()const;
	float GainAmt()const;
	float TaxGainAmt() const;
	//overloaded operator
	Stock & operator =(const Stock& rhs);
	//friend a function to access private data easier
	friend int ReadStkData(Stock stcks[], int maxSize);
	
};

#endif