
#include "BruteForce.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

struct less_than_key
{
    inline bool operator()(const Distance &struct1, const Distance &struct2)
    {
        return (struct1.dist < struct2.dist);
    }
};

double distancia(int x1, int y1, int z1, int x2, int y2, int z2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

vector<vector<double>> KNN(int k, vector<double> targed, vector<vector<double>> points)
{
    vector<Distance> A;
    for (auto a : points)
    {
        A.push_back(Distance(a, distancia(targed[0], targed[1], targed[2], a[0], a[1], a[2])));
    }
    sort(A.begin(), A.end(), less_than_key());
    vector<vector<double>> RPTA;
    for (int i = 0; i < k; i++)
    {
        RPTA.push_back(A[i].point);
    }
    return RPTA;
}

int main()
{
    vector<vector<double>> points;
    vector<Distance> dists;
    vector<double> target;

    int vcount = 0;
    // double vlist[3000][3];
    // double vlist[20000][3];
    // double vlist[30000][3];
    double vlist[40000][3];

    // const char *filename = "1000.txt";
    // const char *filename = "10000.txt";
    // const char *filename = "20000.txt";
    const char *filename = "30000.txt";

    cout << "Opening " << filename << endl;
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "File not found" << filename << endl;
        exit(1);
    }

    string line;
    int i, j;
    bool firstVertex = 1;
    double currCood;

    while (getline(inFile, line))
    {
        if ((line[0] == 'v' || line[0] == 'f') && line[1] == ' ')
        {
            if (line[0] == 'v')
            {
                vcount++;
                i = 1;
                const char *linec = line.data();
                for (int k = 0; k < 3; k++)
                {
                    while (linec[i] == ' ')
                        i++;
                    j = i;
                    while (linec[j] != ' ')
                        j++;
                    currCood = vlist[vcount][k] = atof(line.substr(i, j - i).c_str());
                    i = j;
                }

                firstVertex = 0;
            }
        }
    }

    // Bruteforce A(3000, 3);
    // Bruteforce B(20000, 3);
    // Bruteforce C(30000, 3);
    Bruteforce D(40000, 3);
    for (int i = 1; i <= vcount; i++)
    {
        // A.insert({vlist[i][0], vlist[i][1], vlist[i][2]});
        // B.insert({vlist[i][0], vlist[i][1], vlist[i][2]});
        // C.insert({vlist[i][0], vlist[i][1], vlist[i][2]});
        D.insert({vlist[i][0], vlist[i][1], vlist[i][2]});
    }
    int k = 5;
    auto start = std::chrono::system_clock::now();
    vector<vector<double>> UBER = KNN(k, {588.00, 683.00, 367.00}, D.points);

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    cout << "Tiempo de insersion de " << vcount << " puntos en el KD-Tree" << endl;
    cout << "Duracion -- " << duration.count() << " ms" << std::endl;

    for (auto a : UBER)
    {
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }

    return 0;
}