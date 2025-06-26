#include "cores.h"

// Default Constructor
DataCore::DataCore() : data(0) {;} 

// Constructor
DataCore::DataCore(int data): data(data) {;}

// Set Data
void DataCore::storeData(int data) {this->data = data;}

// Get Data
int DataCore::getData() {return data;}





