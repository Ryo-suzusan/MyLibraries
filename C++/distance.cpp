#include <iostream> 
#include <cmath> 
#include <vector> 
#include <queue> 
#include <string> 
#include <sstream> 
#include <algorithm>  
#include <limits>  

#define M_PI 3.14159265358979323846

using namespace std;
using ll = long long;

struct Point {
	double x;
	double y;
	double z;
};

double twoPointsDistance(const Point& p1, const Point& p2) {
	double sum = pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2);
	return sqrt(sum);
}

double euclideanDistance(const vector<double>& v1, const vector<double>& v2) {
	double sum = 0;
	for (int i = 0; i < v1.size(); i++) {
		sum += pow(v1[i] - v2[i], 2);
	}
	return sqrt(sum);
}

double minkowskiDistance(const vector<double>& v1, const vector<double>& v2, int p) {
	if (p != numeric_limits<double>::max()) {
		double sum = 0;
		for (int i = 0; i < v1.size(); i++) {
			sum += pow(v1[i] - v2[i], p);
		}
		return pow(sum, 1.0 / p);
	}
	else {
		double max = numeric_limits<double>::min();
		for (int i = 0; i < v1.size(); i++) {
			if (max < abs(v1[i] - v2[i])) {
				max = abs(v1[i] - v2[i]);
			}
		}
		return max;
	}
}
