// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++:
// From control structures through objects. Pearson. 

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw, setprecision for output width
#include <fstream>  // To utilize ifstream, ofstream, fstream
using namespace std;

// Global Constant Initialization
const string TITLE = "Sales Report Structure Program";
const string AUTHOR_LINE = "By Forrest Moulin";

struct SalesRecord
{
	double capitalEquip, expensedEquip, smallParts;
};

// Function prototypes to notify compiler
void accumulate(SalesRecord& report, double capVal, 
	double expensedVal, double smallPartsVal);

void writeReport(SalesRecord report, ofstream& fout);

// Create out file stream object
// cout to print to console
// fout to print to file
ofstream fout;

int main()
{
	// Dynamic Variable Initialization
	SalesRecord report;
	ifstream fin;
	string invoiceNumber;
	char equipCode;
	double invoiceCost, capVal, expensedVal, smallPartsVal;

	report.capitalEquip = 0;
	report.expensedEquip = 0;
	report.smallParts = 0;

	// Open input/output files using file path strings
	string inputFilePath =
		"C:\\Users\\Forrest\\OneDrive\\Desktop\\11.13sales.txt";
	fin.open(inputFilePath);

	string outputFilePath =
		"C:\\Users\\Forrest\\OneDrive\\Desktop\\inventoryReport.txt";
	fout.open(outputFilePath);

	// End program in event of file read/write failures
	if (fin.fail())
	{
		cout << "File open failure:" << endl
			<< inputFilePath << endl;
		fin.close();
		fout.close();
		return 0;
	}
	if (fout.fail())
	{
		cout << "File output failure:" << endl
			<< outputFilePath << endl;
		fin.close();
		fout.close();
		return 0;
	}

	cout << fixed << setprecision(2) << TITLE << endl
		<< AUTHOR_LINE << endl << endl;

	fout << fixed << setprecision(2) << TITLE << endl
		<< AUTHOR_LINE << endl << endl;

	// While getline is still reading data
	// from file input stream
	while (fin >> invoiceNumber >> equipCode >> invoiceCost)
	{
		capVal = 0;
		expensedVal = 0;
		smallPartsVal = 0;
		// equipCode is A
		if (equipCode == 'a' || equipCode == 'A')
		{
			capVal += invoiceCost;
		}
		// equipCode is B
		else if (equipCode == 'b' || equipCode == 'B')
		{
			expensedVal += invoiceCost;
		}
		// equipCode is C
		else if (equipCode == 'c' || equipCode == 'C')
		{
			smallPartsVal += invoiceCost;
		}
		// Call function to add values extracted from line to report
		accumulate(report, capVal, expensedVal, smallPartsVal);
	}
	writeReport(report, fout);
	fin.close();
	fout.close();
}
// Updates report structure values in main
void accumulate(SalesRecord& report, double capVal, 
	double expensedVal, double smallPartsVal)
{	// Add values to report, which is updated
	// via reference param
	report.capitalEquip += capVal;
	report.expensedEquip += expensedVal;
	report.smallParts += smallPartsVal;
}
// Reference param fout is used to update fout
// in main
void writeReport(SalesRecord report, ofstream& fout)
{
	// Calculate values
	double totalSales = report.capitalEquip + 
		report.expensedEquip + report.smallParts;
	double capPercentage = 100.0 * report.capitalEquip / totalSales;
	double expPercentage = 100.0 * report.expensedEquip / totalSales;
	double smallPercentage = 100.0 * report.smallParts / totalSales;

	// Print to console
	cout << "Sales Report" << endl
		<< left << setw(22) << "Capital Equipment"
		<< "$" << right << setw(10)
		<< report.capitalEquip << right
		<< setw(8) << capPercentage << "%" << endl

		<< left << setw(22) << "Expensed Equipment"
		<< "$" << right << setw(10)
		<< report.expensedEquip << right
		<< setw(8) << expPercentage << "%" << endl

		<< left << setw(22) << "Small Parts"
		<< "$" << right << setw(10)
		<< report.smallParts << right
		<< setw(8) << smallPercentage << "%" << endl

		<< setw(22) << "" << setw(20) << setfill('-')
		<< "" << setfill(' ') << endl << left << setw(22)

		<< "Total Sales" << "$" << right << setw(10)
		<< totalSales << endl;

	// Print to inventoryReport.txt
	fout << "Sales Report" << endl
		<< left << setw(22) << "Capital Equipment"
		<< "$" << right << setw(10)
		<< report.capitalEquip << right
		<< setw(8) << capPercentage << "%" << endl

		<< left << setw(22) << "Expensed Equipment"
		<< "$" << right << setw(10)
		<< report.expensedEquip << right
		<< setw(8) << expPercentage << "%" << endl

		<< left << setw(22) << "Small Parts"
		<< "$" << right << setw(10)
		<< report.smallParts << right
		<< setw(8) << smallPercentage << "%" << endl

		<< setw(22) << "" << setw(20) << setfill('-')
		<< "" << setfill(' ') << endl << left << setw(22)

		<< "Total Sales" << "$" << right << setw(10)
		<< totalSales << endl;
}
/*
* SALES.TXT INPUT FILE
* 2013-1003		B	120.00
* 2013-2123  	A  	500.87
* 2014-2223  	C 	2199.65
* 2013-1005		B	9120.00
* 2013-2125  	A  	5043.87
* 2014-2243  	C	3299.65
* 2013-3203		B	2150.00
* 2013-4423  	A  	5060.83
* 2014-2493  	C	 2199.65
* 2013-1325		C	9120.00
* 2013-9125  	A  	3333.86
* 2014-2255  	C 	3739.48
* 2014-2623  	C	2876.11
* 2013-1075		B	4102.50
* 2013-2125  	A  	5043.87
* 2014-3243  	C 	10000.65
* 2013-3703		B	1430.90
* 2015-2621  	C 	1376.16
* 2014-1066		B	3198.50
* 2015-2835  	A  	5109.88
* 2012-5543  	C 	10440.63
* 2015-1003		B	2100.90
*/

/*
* CONSOLE/INVENTORYREPORT.TXT FILE OUTPUT
* Sales Report Structure Program
* By Forrest Moulin
*
* Sales Report
* Capital Equipment     $  24093.18   26.31%
* Expensed Equipment    $  22222.80   24.27%
* Small Parts           $  45251.98   49.42%
*                       --------------------
* Total Sales           $  91567.96
*/
