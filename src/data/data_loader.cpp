#include "data_loader.h"

int32_t headerToType(string header)
{
    char type_char = header[0];
    return type_char == 'x' ? data_type::in : data_type::out;
}

DataLoader::DataLoader(string filename)
{
    this->filename = filename;
    this->dataset = new Dataset();
    ifstream inputStream(filename);
    string headerLine;
    vector<string> headers;
    vector<int32_t> headerTypes;

    inputStream >> headerLine;
    istringstream ssHeader(headerLine);

    while (ssHeader.good())
    {
        string header;
        getline(ssHeader, header, ',');
        headers.push_back(header);
        headerTypes.push_back(headerToType(header));
    }

    while (inputStream.good())
    {
        string dataLine;
        inputStream >> dataLine;
        istringstream ssData(dataLine);

        vector<int32_t>::iterator it = headerTypes.begin();

        Data* input = new Data(0);
        Data* output = new Data(0);

        while (ssData.good())
        {
            string num_str;
            getline(ssData, num_str, ',');
            double num = stod(num_str);

            if ((*it) == data_type::in)
            {
                input->addElement(num);
            }
            else
            {
                output->addElement(num);
            }
            it++;
        }

        Datapoint* point = new Datapoint(input, output);
        this->dataset->addDatapoint(point);
    }

    inputStream.close();
}

Dataset* DataLoader::getDataset(){
    return this->dataset;
}