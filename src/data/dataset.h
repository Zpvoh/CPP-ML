#include "datapoint.h"
#include <cstdlib>

class Dataset{
    protected:
        int32_t dataSize;
        vector<Datapoint*> dataset;
    public:
        Dataset();
        Dataset(vector<Datapoint*>);
        void shuffle();
        Datapoint* getDatapointRandom();
        Datapoint* getDatapointByIndex(int32_t);
        void addDatapoint(Datapoint*);
        int32_t size();
};