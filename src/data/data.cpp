#include "data.h"

Data::Data(int length){
    this->length = length;
    this->data_body = new vector<double>(length, 0.0);
}

Data::Data(vector<double>* data){
    this->length = data->size();
    this->data_body = data;
}

void Data::addElement(double element){
    this->length++;
    data_body->push_back(element);
}

bool Data::setElementByIndex(int index, double value){
    if(index >= this->length) {
        return false;
    } else {
        vector<double>::iterator it = this->data_body->begin();
        for(int i = 0; i < index; i++) it++;
        this->data_body->erase(it);
        this->data_body->insert(it, value);
        return true;
    }
}

double Data::getElementByIndex(int index){
    if(index >= this->length) {
        return 0; // if out of length, return default value 0
    } else {
        return this->data_body->operator[](index);
    }
}

int Data::size(){
    return this->length;
}