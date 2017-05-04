/*
Author: Evan Farris
Date: 05/02/2017
File: UseStock.cpp
Descr:
Main File for Program 4
*///
#include "Stock.h"

int ReadStkData(Stock stcks[], int maxSize);
void SortStks(Stock stcks[], int size);
void CalculatePortfolio(Stock stcks[], int size);

void main()
{	
	const int maxNum = 25;
	Stock stcks[maxNum];
	int numElems = ReadStkData(stcks, maxNum);
	SortStks(stcks, numElems);
	CalculatePortfolio(stcks, numElems);	
}

int ReadStkData(Stock stcks[], int maxSize)
{
	//local variables
	ifstream inpFile;
	string fName;
	int counter = 0,s;
	//prompt user for file location
	cout << "Please enter the input file location: ";
	getline(cin, fName);
	inpFile.open(fName);
	//check if file is valid 
	if (!inpFile)
	{
		cerr << "Error! File not found!" << endl;
		exit(-1);
	}
	//input data from file into sector array
	for (int i = 0; i < maxSize && !inpFile.eof(); i++)
	{
		//store data directly into the stock, except for the sector, as it needs
		//to be casted statically as a sector
		getline(inpFile, stcks[i].tSym, ' ');
		getline(inpFile, stcks[i].cName, '#');
		inpFile >> s;
		inpFile >> stcks[i].numShare;
		inpFile >> stcks[i].purPrice;
		inpFile >> stcks[i].curPrice;
		inpFile.ignore();
		//store data in Stock objects via public functions
		stcks[i].setSector(static_cast<Sector>(s));
		counter++;
	}
	//close input file
	inpFile.close();
	//returns num of elements read from file
	return counter;
}

void SortStks(Stock stcks[], int size)
{
	//sort the array by sector
	int minInd;
	Stock minStock;
	for (int i = 0; i < size; i++)
	{
		minInd = i;
		minStock = stcks[i];
		for (int j = i + 1; j < size; j++)
		{
			if (stcks[j].getSector() < stcks[minInd].getSector())
			{
				minStock = stcks[j];
				minInd = j;
			}
		}
		stcks[minInd] = stcks[i];
		stcks[i] = minStock;
	}
}

void CalculatePortfolio(Stock stcks[], int size)
{
	string oFName;	
	fstream oFile;
	double totSecGain = static_cast<double>(0.0), totSecTax = static_cast<double>(0.0);

	cout << "Please Enter a file name to output your portfolio: ";
	getline(cin, oFName, '\n');
	//create output file
	cout << "Preparing Output file . . ." << endl;
	oFile.open(oFName, ios::out);
	oFile << fixed << showpoint << setprecision(2);
	oFile << "Prepared Portfolio Analysis Summarized by Sector\nLong Term Capital Gain Tax Rate = " << Stock::getTax();

	for (int i = 0; i < size; i++)
	{
		//adds up the sector gains/tax if there is a gain
		if (stcks[i].CurrStatus() == Gain)
		{
			totSecGain += stcks[i].GainAmt();
			totSecTax += stcks[i].TaxGainAmt();
		}
		//writes the sector Header in the output file if it's the first object, or the previous object is in a different sector
		if (i == 0 || (stcks[i - 1].getSector() != stcks[i].getSector()))
		{
			oFile << "\n\n" << setw(10) << left << "Symbol" << setw(50) << left << "Company" << setw(10) << right << "Status" << endl;
			oFile << setw(10) << left << "======" << setw(50) << left << "=======" << setw(10) << right << "======" << endl;
		}
		//formatting for the file/display company symbols /name
		oFile << setw(10) << left << stcks[i].getTSym() << setw(50) << left << stcks[i].getCName();

		//switch statement to add the status(gain/loss/breakeven) to the file from the enumerated type
		switch (stcks[i].CurrStatus())
		{
		case Gain:
			oFile << setw(11) << right << "GAIN\n";
			break;
		case Loss:
			oFile << setw(11) << right << "LOSS\n";
			break;
		case Breakeven:
			oFile << setw(11) << right << "BREAKEVEN\n";
			break;
		}

		//if it's the last object in the initialized array, or the next object is in a different sector, it outputs the sector summary 
		if ((i + 1) == size || (stcks[i + 1].getSector() != stcks[i].getSector()))
		{
			oFile << "\n\n" << setw(35) << right << "Summary for Sector:";

			switch (stcks[i].getSector())
			{
			case Technology:
				oFile << setw(21) << right << "Technology\n";
				break;
			case Health:
				oFile << setw(21) << right << "Health\n";
				break;
			case Financial:
				oFile << setw(21) << right << "Financial\n";
				break;
			case CGoods:
				oFile << setw(21) << right << "Consumer Goods\n";
				break;
			case Utilities:
				oFile << setw(21) << right << "Utilities\n";
				break;

			}

			oFile << setw(35) << "Gain Amount:" << setw(20) << right << totSecGain << endl;
			oFile << setw(35) << "Tax on Gain:" << setw(20) << right << totSecTax << endl;
			//reset sector gains/tax
			totSecGain = 0.0;
			totSecTax = 0.0;
		}
	}

	//close the file
	oFile.close();
	cout << "File has been created." << endl;
}
/*
Please enter the input file location: C:\Users\tripo\Desktop\P4_stkPort.txt
Please Enter a file name to output your portfolio: P4_stkPortReport.txt
Preparing Output file . . .
File has been created.
Press any key to continue . . .

*/