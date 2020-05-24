#include <vector>

using namespace std;
#ifndef ML_DATA
#define ML_DATA

class Data {
    protected:
        int32_t length;
        vector<double>* data_body;
    public:
        Data(int32_t);
        Data(vector<double>*);
        void addElement(double);
        double getElementByIndex(int32_t);
        bool setElementByIndex(int32_t, double);
        int32_t size();
};

#endif
