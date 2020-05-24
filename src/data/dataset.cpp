#include "dataset.h"

Dataset::Dataset(){
    this->dataSize=0;
}

Dataset::Dataset(vector<Datapoint*> dataset){
    this->dataset=dataset;
    this->dataSize=dataset.size();
}

int Dataset::size(){
    return this->dataSize;
}

void Dataset::addDatapoint(Datapoint* point){
    this->dataset.push_back(point);
    this->dataSize++;
}

Datapoint* Dataset::getDatapointByIndex(int index){
    return this->dataset[index];
}

Datapoint* Dataset::getDatapointRandom(){
    int index = rand()%this->dataSize;
    return this->dataset[index];
}