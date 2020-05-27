#include "square_loss.h"

double SquareLoss::computeLoss(Datapoint point){
    Data real = point.getRealOutput(), eval = point.getEvalOutput();
    if(real.size()!=eval.size()) {
        return -1;
    } else {
        int32_t size = real.size();
        double loss = 0;
        for(int32_t i=0; i<size; i++){
            double diff = real.getElementByIndex(i) - eval.getElementByIndex(i);
            loss += (diff * diff);
        }
        return loss;
    }
}

double SquareLoss::computeLoss(Dataset batch){
    double sum = 0;

    for(int i=0; i<batch.size(); i++){
        double loss = this->computeLoss(*(batch.getDatapointByIndex(i)));
        sum+=loss;
    }
    return sum/batch.size();
}