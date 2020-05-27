#include "main.h"

int32_t main(int32_t argn, char** args){
    using namespace std;

    string type(args[1]);
    if(type=="--train"){
        string num_str(args[2]);
        int32_t max_num = stoi(num_str);
        Model* model = new Perceptron(2, 0.005);

        DataLoader dataloader("dataset/perceptron.csv");
        model->train(dataloader.getDataset(), max_num);
        cout<<"training completed"<<endl;

        model->printArgs();
        model->saveModel("perceptron.model");
    } else if(type=="--interfere"){
        Model* model = new Perceptron("perceptron.model", 0.005);
        DataLoader dataloader("dataset/perceptron.csv");

        for(int32_t i=0; i<dataloader.getDataset()->size(); i++){
            Datapoint* point = dataloader.getDataset()->getDatapointByIndex(i);
            cout<<model->evaluate(point)->getElementByIndex(0)<<endl;
        }

        model->printArgs();
    }

    return 0;
}