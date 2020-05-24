#include "data.h"

Data::Data(int32_t length){
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

bool Data::setElementByIndex(int32_t index, double value){
    if(index >= this->length) {
        return false;
    } else {
        vector<double>::iterator it = this->data_body->begin();
        for(int32_t i = 0; i < index; i++) it++;
        this->data_body->erase(it);
        this->data_body->insert(it, value);
        return true;
    }
}

double Data::getElementByIndex(int32_t index){
    if(index >= this->length) {
        return 0; // if out of length, return default value 0
    } else {
        return this->data_body->operator[](index);
    }
}

int32_t Data::size(){
    return this->length;
}