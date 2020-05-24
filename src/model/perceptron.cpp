#include "perceptron.h"

Perceptron::Perceptron()
{
    srand((u_int32_t)(time(NULL)));
    this->weights = new Data(0);
    this->b = rand() % 20 - 10;

    this->rate = 0.1;
}

Perceptron::Perceptron(string filename, double rate)
{
    this->readModel(filename);

    this->rate = rate;
}

Perceptron::Perceptron(int32_t inputSize, double rate)
{
    srand((u_int32_t)(time(NULL)));
    this->weights = new Data(0);
    for (int32_t i = 0; i < inputSize; i++)
    {
        this->weights->addElement(rand() % 20 - 10);
    }

    this->b = rand() % 20 - 10;

    this->rate = rate;
}

Perceptron::Perceptron(Data *weights, double b, double rate)
{
    this->weights = weights;
    this->b = b;
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
    for (int32_t i = 0; i < point->inputSize(); i++)
    {
        double weight = this->weights->getElementByIndex(i);
        double x = point->getInput().getElementByIndex(i);
        y += (weight * x);
    }
    y += this->b;
    y = y > 0 ? 1 : -1;

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

    double y_eval = point->getEvalOutput().getElementByIndex(0);
    double y_real = point->getRealOutput().getElementByIndex(0);
    double y_diff = y_eval * y_real < 0 ? y_real*2-1 : 0;
    for (int32_t i = 0; i < point->inputSize(); i++)
    {
        double weight = this->weights->getElementByIndex(i);
        double x = point->getInput().getElementByIndex(i);
        this->weights->setElementByIndex(i, weight + this->rate * y_diff * x);
    }

    this->b = this->b + this->rate * y_diff;
}

bool Perceptron::readModel(string filename)
{
    ifstream in(filename, ios::in|ios::binary);
    if(!in){
        cerr << "Model reading error!" << endl;
		return false; 
    }

    int32_t weights_size;
    in.read((char*)&weights_size, sizeof(int32_t));
    Data* weights = new Data(0);
    for(int i=0; i<weights_size; i++){
        double ele;
        in.read((char*)&ele, sizeof(double));
        weights->addElement(ele);
    }

    this->weights = weights;
    in.read((char*)&(this->b), sizeof(double));
    in.close();
    return true;
}

bool Perceptron::saveModel(string filename)
{
    ofstream os(filename, ios::out|ios::binary);
    if(!os){
        cerr << "Model saving error!" << endl;
		return false; 
    }

    Data weights_val = *(this->weights);
    int32_t size = weights_val.size();
    os.write((char*)&size, sizeof(int32_t));
    for(int i=0; i<size; i++){
        double ele = weights_val.getElementByIndex(i);
        os.write((char*)&ele, sizeof(double));
    }
    os.write((char*)&(this->b), sizeof(double));

    os.flush();
    os.close();

    return true;
}

void Perceptron::printArgs(){
    for(int32_t i=0; i<this->weights->size(); i++){
        cout<<"w_"<<(i+1)<<": "<<this->weights->getElementByIndex(i)<<endl;
    }

    cout<<"b: "<<this->b<<endl;
}