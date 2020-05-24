#include "main.h"

int32_t main(int32_t argn, char** args){
    using namespace std;

    // string num_str(args[1]);
    // int32_t max_num = stoi(num_str);
    Model* model = new Perceptron("perceptron.model", 0.005);
    // Loss* loss = new SquareLoss();
    // double loss_val = 100;

    DataLoader dataloader("dataset/perceptron.csv");
    // int32_t epoch = 0;
    // while(epoch<max_num){
    //     Datapoint* datapoint = dataloader.getDataset().getDatapointRandom();
    //     model->evaluate(datapoint);
    //     model->updateModel(datapoint);
    //     loss_val = loss->computeLoss(*datapoint);
    //     cout<<epoch<<":"<<loss_val<<" "<<datapoint->getEvalOutput().getElementByIndex(0)<<endl;
    //     epoch++;
    // }

    cout<<"training completed"<<endl;
    for(int32_t i=0; i<dataloader.getDataset().size(); i++){
        Datapoint* point = dataloader.getDataset().getDatapointByIndex(i);
        cout<<model->evaluate(point)->getElementByIndex(0)<<endl;
    }

    model->printArgs();
    // model->saveModel("perceptron.model");

    return 0;
}