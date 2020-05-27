#include "dataset.h"
#include <string>
#include <list>
#include <fstream>
#include <sstream>

#ifndef ML_DATA_LOADER
#define ML_DATA_LOADER
namespace data_type{
    enum dataType{
        in,
        out
    };
}


class DataLoader {
    protected:
        string filename;
        Dataset* dataset;
    public:
        DataLoader(string);
        Dataset* getDataset();
};
#endif