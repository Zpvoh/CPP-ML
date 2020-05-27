#include "loss.h"

#ifndef ML_SQUARE_LOSS
#define ML_SQUARE_LOSS

class SquareLoss: public Loss {
    public:
        double computeLoss(Datapoint);
        double computeLoss(Dataset);
};

#endif