#define ARC_H 
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Sommet.h"
class Arc {
public:
	Arc(std::string sommetDepart, std::string sommetArrive, int distance) :sommetDepart_(sommetDepart),sommetArrive_(sommetArrive),distance_(distance) {};
	std::string getSommetDepart(){return sommetDepart_;};
	std::string getSommetArrive(){return sommetArrive_;};
	int getDistance() { return distance_; };
private:
	
	std::string sommetDepart_;
	std::string sommetArrive_;
	int distance_;
};
