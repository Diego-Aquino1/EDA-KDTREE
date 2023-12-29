
#include "BruteForce.h"
#include <chrono>
#include <ctime>
int main()
{
    int vcount = 0;
    // double vlist[3000][3];
    //  double vlist[20000][3];
    //  double vlist[30000][3];
    double vlist[40000][3];
    
    // const char *filename = "1000.txt";
    //  const char* filename = "10000.txt";
    //   const char* filename = "20000.txt";
    const char *filename = "30000.txt";

    cout << "Opening " << filename << endl;
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "We cannot find your file " << filename << endl;
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
                { // k is 0,1,2 for x,y,z
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
    // Brute Force time measurement
    auto start = std::chrono::system_clock::now();

    // Bruteforce A(3000, 3);
    Bruteforce B(20000, 3);
    //  Bruteforce C (30000,3);
    // Bruteforce D(40000, 3);
    for (int i = 1; i <= vcount; i++)
    {
        // A.insert({vlist[i][0], vlist[i][1], vlist[i][2]});
        B.insert({vlist[i][0], vlist[i][1], vlist[i][2]});
        //  C.insert({vlist[i][0], vlist[i][1], vlist[i][2]});
        // D.insert({vlist[i][0], vlist[i][1], vlist[i][2]});
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration = end - start;
    cout << "Tiempo de insersion de " << vcount << " puntos en el KD-Tree - BF" << endl;
    cout << "Duracion -- " << duration.count() << " ms" << std::endl;

    return 0;
}