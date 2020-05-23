#include <iostream>
#include "main.h"

int main(int argn, char** args){
    using namespace std;
    Data real_input = Data(2);
    real_input.setElementByIndex(0, 3.2);
    real_input.setElementByIndex(1, 5);
    Data real_output = Data(1);
    real_output.setElementByIndex(0, 16);
    Data eval_output = Data(1);
    eval_output.setElementByIndex(0, 12);

    Datapoint datapoint = Datapoint(&real_input, &real_output);

    Model* model = new Perceptron(datapoint.inputSize(), 1.0);
    Loss* loss = new SquareLoss();
    double loss_val = 100;

    while(loss_val>5){
        model->evaluate(&datapoint);
        model->updateModel(&datapoint);
        loss_val = loss->computeLoss(datapoint);
        cout<<loss_val<<endl;
    }

    return 0;
}