#include "../data/dataset.h"

#ifndef ML_LOSS
#define ML_LOSS

class Loss{
    public:
        virtual double computeLoss(Datapoint)=0;
        virtual double computeLoss(Dataset) = 0;
};

#endif