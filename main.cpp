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

template <typename T>
vector<vector<T>> readFile(string fileName)
{
    vector<vector<T>> result;
    vector<T> tempLine;

    ifstream file(fileName);

    string line;
    int row = 0;
    while (getline(file, line, '\n'))
    {
        cout << line << endl;
        stringstream ss(line);
        T i;
        while (ss >> i)
        {
            tempLine.push_back(i);
            if (ss.peek() == ',')
                ss.ignore();
        }
        for (i = 0; i < tempLine.size(); i++)
        {
            std::cout << tempLine.at(i) << " ";
        }
        cout << endl;
        result.push_back(tempLine);
        row++;
        tempLine.clear();
    }
    file.close();
    return result;
}

int main()
{
    vector<vector<int>> F = readFile<int>("F");
    const int Fsize = F.size();
    cout << "F length: " << Fsize << endl;
    vector<vector<float>> W = readFile<float>("W");
    const int Wsize = W.size();
    cout << "W length: " << Wsize << endl;
    int i, k;
    char c;
    float results[Fsize];
    while (true)
    {

        cout << "Enter query(example: i,k). Ctrl+C to break: ";
        cin >> i >> c >> k;
        while (!cin || k > 9 || i < 1 || i > Wsize)
        {
            cin.clear(); 
            cin.ignore();
            cout << "Wrong input. i's range should be 1 to " << Wsize << ", k's should be < 10" << endl;
            cin >> i >> c >> k;
        }
        cout << "i: " << i << " k: " << k << endl;
        i--;

        auto start = chrono::steady_clock::now();

        for (int j = 0; j < Fsize; ++j)
        {
            // cout << inner_product(W[i].begin(), W[i].end(), F[j].begin(), 0.0) << " " << endl;
            results[j] = inner_product(W[i].begin(), W[i].end(), F[j].begin(), 0.0);
        }
        vector<int> indices(Fsize);
        int x = 0;
        iota(indices.begin(), indices.end(), x++); 
        sort(indices.begin(), indices.end(), [&](int i, int j) { return results[i] > results[j]; });
        cout << "First k elements: ";
        for (int i = 0; i < k; ++i)
        {
            cout << vector<int>(indices.begin(), indices.begin() + k)[i] << " ";
        }
        cout << endl;

        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << "Exhaustive search duration: ";
        cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    }

    return 0;
}