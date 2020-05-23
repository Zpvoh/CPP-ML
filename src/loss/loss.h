#include "../data/datapoint.h"

#ifndef ML_LOSS
#define ML_LOSS

class Loss{
    public:
        virtual double computeLoss(Datapoint)=0;
};

#endif