#include <iostream>
#include "main.h"

int main(int argn, char** args){
    using namespace std;
    Data real_input = Data(2);
    real_input.setElementByIndex(0, 3.2);
    real_input.setElementByIndex(1, 5);
    Data real_output = Data(1);
    real_output.setElementByIndex(0, 16);

    Datapoint datapoint = Datapoint(&real_input, &real_output);

    Model* model = new Perceptron(datapoint.inputSize(), 0.01);
    Loss* loss = new SquareLoss();
    double loss_val = 100;

    int epoch = 1;
    while(loss_val>1 && epoch<100){
        model->evaluate(&datapoint);
        model->updateModel(&datapoint);
        loss_val = loss->computeLoss(datapoint);
        cout<<epoch<<":"<<loss_val<<" "<<datapoint.getEvalOutput().getElementByIndex(0)<<endl;
        epoch++;
    }

    return 0;
}