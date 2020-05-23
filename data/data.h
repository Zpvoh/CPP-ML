#include <vector>

using namespace std;
#ifndef ML_DATA
#define ML_DATA

class Data {
    protected:
        int length;
        vector<double>* data_body;
    public:
        Data(int);
        Data(vector<double>*);
        void addElement(double);
        double getElementByIndex(int);
        bool setElementByIndex(int, double);
        int size();
};

#endif
