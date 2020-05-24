#include "../data/datapoint.h"

#ifndef ML_MODEL
#define ML_MODEL

class Model {
    public:
        virtual bool readModel(string)=0;
        virtual bool saveModel(string)=0;
        virtual Data* evaluate(Datapoint*)=0;
        virtual void updateModel(Datapoint*)=0;
        virtual void printArgs()=0;
};

#endif