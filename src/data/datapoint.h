#include "data.h"

#ifndef ML_DATApoint
#define ML_DATApoint

class Datapoint {
    protected:
        int32_t inputLength;
        int32_t outputLength;
        Data* input;
        Data* realOutput;
        Data* evalOutput;
        friend class Perceptron;
    public:
        Datapoint(int32_t, int32_t);
        Datapoint(Data*, Data*);
        Data getInput();
        Data getRealOutput();
        Data getEvalOutput();
        int32_t inputSize();
        int32_t outputSize();
};

#endif