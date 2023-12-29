#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include<bits/stdc++.h>
using namespace std;

#define MS 10000
class Bruteforce{
private:
    int dim;
    int pos;
 
public:
    vector<vector<double>> points;
    Bruteforce(int max_size, int dim){
        this->pos = 0;
        this->dim = dim;
        this->points.resize(max_size, vector<double>(dim));        
    }

    //insert a point to the tree
    void insert(vector<double> point){
        points[pos++] = point;
    }

    //search a point in the tree
    bool search(vector<double> point){
        for(int i = 0; i < points.size(); i++){
            if(points[i] == point){
                return true;
            }
        }
        return false;
    }

   
};

class Distance
{
public:
    std::vector<double> point;
    double dist;

    Distance(std::vector<double> point, double dist)
    {
        this->point = point;
        this->dist = dist; 
    }
    
};

#endif