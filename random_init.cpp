#include <iostream>
#include <time.h>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <chrono>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    const int freqLengthInit = 1000;
    const int vectorLength = 500;
    const int WlengthInit = 3;

    int wordFrequencies[freqLengthInit][vectorLength];
    float W[WlengthInit][vectorLength];

    srand(time(0));
    ofstream freqsFile;
    freqsFile.open("F");
    for (int i = 0; i < freqLengthInit; ++i)
    {
        for (int j = 0; j < vectorLength; ++j)
        {
            wordFrequencies[i][j] = rand() % 100;
            freqsFile << wordFrequencies[i][j] << ", ";
        }
        freqsFile << endl;
    }
    freqsFile.close();
    cout<< "F file created"<<endl;

    ofstream Wfile;
    Wfile.open("W");
    for (int i = 0; i < WlengthInit; ++i)
    {
        for (int j = 0; j < vectorLength; ++j)
        {
            W[i][j] = float(rand() % 100000 - 50000) / 100;

            Wfile << W[i][j] << ", ";
        }
        Wfile << endl;
    }
    Wfile.close();
    cout<< "W file created"<<endl;

}
