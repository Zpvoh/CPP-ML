#include "data.h"

#ifndef ML_DATAPOINT
#define ML_DATAPOINT

class Datapoint {
    protected:
        int inputLength;
        int outputLength;
        Data* input;
        Data* realOutput;
        Data* evalOutput;
        friend class Perceptron;
    public:
        Datapoint(int, int);
        Datapoint(Data*, Data*);
        Data getInput();
        Data getRealOutput();
        Data getEvalOutput();
        int inputSize();
        int outputSize();
};

#endif