//Computer Programming Midterm
//Mucahid Mutluer
//Student ID: 152120191072
#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
using namespace std;

int main()
{
	ifstream infile1;
	ifstream infile2;
	ofstream outfile;

	string firstname;
	string lastname;


	infile1.open("group1.TXT"); 
	infile2.open("group2.TXT");
	outfile.open("bargraph.txt");
	int t1 = 0;
	int t2 = 0;
	int i1 = 0;
	int i2 = 0;
	int k1, k2;
	int h1 = 0;
	int h2 = 0;
	int b1, b2;
	int star1, star2;
	string line1, line2;
	string name1, name2;
	double sum1, sum2;
	double amount1, amount2;
	double av1, av2;
	double totalsum1 = 0.0;
	double totalsum2 = 0.0;
	double totalav1, totalav2;

	if (!infile1)
	{
		cout << "Can not open the input file.!" << endl;
		cout << "Program Terminates!!!" << endl;
		return 1;
	}
	if (!infile2)
	{
		cout << "Can not open the input file.!" << endl;
		cout << "Program Terminates!!!" << endl;
		return 1;
	}

	//cout << "Processing Data" << endl;
	outfile << setw(27) << right << "Bar Graph" << endl;
	outfile << setw(9) << left << "Course" << setw(9) << "Course";
	outfile << setw(5) << left << "0" << setw(5) << left << "10" << setw(5) << left << "20" << setw(5) << left << "30" << setw(5) << left << "40";
	outfile << setw(5) << left << "50" << setw(5) << left << "60" << setw(5) << left << "70" << setw(5) << left << "80" << setw(5) << left << "90";
	outfile << setw(5) << left << "100" << endl;
	outfile << setw(9) << left << "ID" << setw(9) << "Average";
	outfile << setfill('.');
	outfile << setw(5) << left << "|" << setw(5) << left << "|" << setw(5) << left << "|" << setw(5) << left << "|" << setw(5) << left << "|";
	outfile << setw(5) << left << "|" << setw(5) << left << "|" << setw(5) << left << "|" << setw(5) << left << "|" << setw(5) << left << "|";
	outfile << setfill(' ') << setw(5) << left << "|" << endl;

	
	infile1 >> name1;
	infile2 >> name2;

	while (infile1 && infile2)
	{
		outfile << setw(9) << left;
		outfile << name1;



		sum1 = 0.0;
		sum2 = 0.0;
		infile1 >> amount1;

		infile2 >> amount2;

		sum1 = sum1 + amount1;
		sum2 = sum2 + amount2;

		i1++;
		i2++;
		while ((infile1) && (amount1 != -999))
		{

			infile1 >> amount1;
			sum1 = sum1 + amount1;
			i1++;

		}
		h1++;
		sum1 = sum1 + 999.0;
		i1 = i1 - 1;
		k1 = i1;
		i1 = 0;
		av1 = sum1 / static_cast<double>(k1);
		totalsum1 = totalsum1 + av1;

		outfile << setw(9) << left << fixed << showpoint << setprecision(2) << av1;
		star1 = static_cast<int>(av1) / 2;
		for (b1 = 0; b1 < star1; b1++)
		{
			outfile << "*";
		}
		outfile << endl;

		infile1 >> name1;

		outfile << setw(9) << left;
		outfile << " ";

		//þimdi diger dosyaya gecelim

		while ((infile2) && (amount2 != -999))
		{

			infile2 >> amount2;
			sum2 = sum2 + amount2;
			i2++;

		}
		h2++;
		sum2 = sum2 + 999.0;
		i2 = i2 - 1;
		k2 = i2;
		i2 = 0;
		av2 = sum2 / static_cast<double>(k2);
		totalsum2 = totalsum2 + av2;

		outfile << setw(9) << left << fixed << showpoint << setprecision(2) << av2;
		star2 = static_cast<int>(av2) / 2;
		for (b2 = 0; b2 < star2; b2++)
		{
			outfile << "#";
		}
		outfile << endl << endl;

		infile2 >> name2;


	}//end of outer while

	outfile << "Group 1 -- ****" << endl << "Group 2 -- ####" << endl;

	totalav1 = totalsum1 / static_cast<double>(h1);
	outfile << "Avg for group 1: " << fixed << showpoint << setprecision(2) << totalav1 << endl;

	//ikincinin genel ortalamasý geliyor simdi

	totalav2 = totalsum2 / static_cast<double>(h2);
	outfile << "Avg for group 2: " << fixed << showpoint << setprecision(2) << totalav2 << endl;


	infile1.close();
	infile2.close();
	outfile.close();

	system("pause");
	return 0;
}