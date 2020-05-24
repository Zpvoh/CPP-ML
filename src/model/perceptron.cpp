#include "perceptron.h"

Perceptron::Perceptron(int inputSize, double rate)
{
    this->weights = new Data(0);
    for (int i = 0; i < inputSize; i++)
    {
        this->weights->addElement(rand()%20-10);
    }

    this->rate = rate;
}

Perceptron::Perceptron(Data *weights, double rate)
{
    this->weights = weights;
    this->rate = rate;
}

Data *Perceptron::evaluate(Datapoint *point)
{
    if (point->outputSize() != 1 || this->weights->size() != point->inputSize())
    {
        return NULL;
    }

    Data *eval = new Data(0);

    double y = 0;
    for (int i = 0; i < point->inputSize(); i++)
    {
        double weight = this->weights->getElementByIndex(i);
        double x = point->getInput().getElementByIndex(i);
        y += (weight * x);
    }
    eval->addElement(y);

    point->evalOutput = eval;

    return eval;
}

void Perceptron::updateModel(Datapoint *point)
{
    if (point->outputSize() != 1 || this->weights->size() != point->inputSize())
    {
        return;
    }

    for (int i = 0; i < point->inputSize(); i++)
    {
        double weight = this->weights->getElementByIndex(i);
        double x = point->getInput().getElementByIndex(i);
        double y_eval = point->getEvalOutput().getElementByIndex(i);
        double y_real = point->getRealOutput().getElementByIndex(i);
        this->weights->setElementByIndex(i, weight + this->rate * (y_real - y_eval) * x);
    }
}