#include "model.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

#ifndef ML_PERCEPTRON
#define ML_PERCEPTRON

class Perceptron: public Model{
    protected:
        double rate;
        Data* weights;
        double b;
    public:
        Perceptron();
        Perceptron(string, double);
        Perceptron(int32_t, double);
        Perceptron(Data*, double, double);
        bool readModel(string);
        bool saveModel(string);
        Data* evaluate(Datapoint*);
        void updateModel(Datapoint*);
        void train(Dataset*, int);
        void printArgs();
};

#endif