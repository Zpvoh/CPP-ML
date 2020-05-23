#include "../data/datapoint.h"

#ifndef ML_MODEL
#define ML_MODEL

class Model {
    public:
        virtual Data* evaluate(Datapoint*)=0;
        virtual void updateModel(Datapoint*)=0;
};

#endif