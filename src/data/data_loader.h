#include "dataset.h"
#include <string>
#include <list>
#include <fstream>
#include <sstream>

namespace data_type{
    enum dataType{
        in,
        out
    };
}


class DataLoader {
    protected:
        string filename;
        Dataset dataset;
    public:
        DataLoader(string);
        Dataset getDataset();
};