#define ARC_H 
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Sommet.h"
class Arc {
public:
	Arc(Sommet* sommetDepart, Sommet* sommetArrive, int distance) :sommetDepart_(sommetDepart),sommetArrive_(sommetArrive),distance_(distance) {};
	Sommet* getSommetDepart(){return sommetDepart_;};
	Sommet* getSommetArrive(){return sommetArrive_;};
	int getDistance() { return distance_; };
private:
	
	Sommet* sommetDepart_;
	Sommet* sommetArrive_;
	int distance_;
};
