#include "datapoint.h"
#include <cstdlib>

class Dataset{
    protected:
        int dataSize;
        vector<Datapoint*> dataset;
    public:
        Dataset();
        Dataset(vector<Datapoint*>);
        void shuffle();
        Datapoint* getDatapointRandom();
        Datapoint* getDatapointByIndex(int);
        void addDatapoint(Datapoint*);
        int size();
};