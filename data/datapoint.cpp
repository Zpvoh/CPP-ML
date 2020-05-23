#include "datapoint.h"

Datapoint::Datapoint(int sizeInput, int sizeOutput){
    this->input = new Data(sizeInput);
    this->realOutput = new Data(sizeOutput);
    this->evalOutput = new Data(sizeOutput);
    this->inputLength = sizeInput;
    this->outputLength = sizeOutput;
}

Datapoint::Datapoint(Data* input, Data* output){
    this->input = input;
    this->realOutput = output;
    this->inputLength = input->size();
    this->outputLength = output->size();
    this->evalOutput = new Data(this->outputLength);
}

Data Datapoint::getInput(){
    return *(this->input);
}

Data Datapoint::getRealOutput(){
    return *(this->realOutput);
}

Data Datapoint::getEvalOutput(){
    return *(this->evalOutput);
}

int Datapoint::inputSize(){
    return this->inputLength;
}

int Datapoint::outputSize(){
    return this->outputLength;
}