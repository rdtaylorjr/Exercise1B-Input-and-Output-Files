/**
 * main.cpp
 * Exercise1_B
 *
 * @author Russell Taylor
 * @date 6/9/20
 * CSC 240 C++ Data Structures (Summer 2020)
 * Oakton Community College
 * Professor: Kamilla Murashkina
 *
 * Assignment: 5 Input Files, 5 Output Files
 *
 * "Each input file produces one output file. Write a mock program
 * and post it in Discussion 1. Rewrite your Exercise1_A in way
 * that reads input files named in#.txt and writes to corresponding
 * output files named out#.txt. For this exercise, assume that the
 * input is valid (one positive integer in each file)."
 *
 * Input: Reads from 5 input files, each containing one year as an integer
 * Output: Writes the equivalent Chinese year to 5 output files
 *
 * Given 5 files, each containing one year as an integer,
 * the output should be 5 files containing the equivalent Chinese years
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
 * Function prototypes
 */
void testFile(int);
void testYear(const string& ifname, const string& ofname);

/**
 * Main
 */
int main() {
    try {
        for (int i = 1; i <= 5; ++i)
            testFile(i);
    }

    catch (const exception& ex) {
        cout << "Exception:" << ex.what() << endl;
    }
}

/**
 * Generates file names
 * @param num the input/output files file number
 */
void testFile(int num) {
    const string& ifname = "in" + to_string(num) + ".txt";
    const string& ofname = "out" + to_string(num) + ".txt";
    
    cout << "*** Reading file " << ifname << " *** " << endl;
    testYear(ifname, ofname);
    cout << "*** OK ***" << endl << endl;
}

/**
 * Reads integer years from input file and writes Chinese years to output file
 * @param ifname input file name
 * @param ofname output file name
 */
void testYear(const string& ifname, const string& ofname) {
    ifstream fin;
    ofstream fout;
    int year;
    
    fin.open(ifname);
    if (!fin) throw runtime_error("Cannot open file " + ifname + " for reading");

    fout.open(ofname);
    if (!fout) throw runtime_error("Cannot open file " + ofname + " for writing");

    fin >> year;
    string yearName[] = { "Monkey", "Rooster", "Dog", "Pig", "Rat",
        "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Sheep" };
    
    cout << year << " is the year of the " << yearName[year % 12] << endl;
    fout << year << " is the year of the " << yearName[year % 12] << endl;

    fin.close();
    fout.close();
}
