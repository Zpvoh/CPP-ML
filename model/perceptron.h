#include "model.h"

#ifndef ML_PERCEPTRON
#define ML_PERCEPTRON

class Perceptron: public Model{
    protected:
        double rate;
        Data* weights;
    public:
        Perceptron(int, double);
        Perceptron(Data*, double);
        Data* evaluate(Datapoint*);
        void updateModel(Datapoint*);
};

#endif