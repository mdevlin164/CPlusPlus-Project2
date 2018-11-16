#include "vecsim.h"
#include <cmath>
#include <iostream>
using namespace std;

vecsim::vecsim(double* v1, double* v2, int v_len) 
		: vec1(v1), vec2(v2), vec_len(v_len){
}

vecsim::vecsim() {
	vec1 = vec2 = NULL;
	vec_len = 0;
}

double vecsim::Euclidean() {
	if (!vec1 || !vec2 || vec_len <= 0) {
		cout << "Invalid vector(s)" << endl;
		return 0;
	}
	double dis = 0;
	for (int i = 0; i < vec_len; i++) {
		double d = vec1[i] - vec2[i];
		dis += d * d;
	}
	return sqrt(dis);
}

double vecsim::Cosine() {
	if (!vec1 || !vec2 || vec_len <= 0) {
		cout << "Invalid vector(s)" << endl;
		return 0;
	}
	double norm1 = 0.;
	double norm2 = 0.;
	double dot_product = 0.;
	for (int i = 0; i < vec_len; i++) {
		norm1 += vec1[i] * vec1[i];
		norm2 += vec2[i] * vec2[i];
		dot_product += vec1[i] * vec2[i];
	}
	norm1 = sqrt(norm1);
	norm2 = sqrt(norm2);

	if (norm1 <= 0. || norm2 <= 0) {
		cout << "Invalid vector(s)" << endl;
		return 0;
	}
	return dot_product / (norm1 * norm2);
}

double vecsim::Euclidean(double* v1, double* v2, int v_len) {
	vec1 = v1;
	vec2 = v2;
	vec_len = v_len;
	return Euclidean();
}

double vecsim::Cosine(double* v1, double* v2, int v_len) {
	vec1 = v1;
	vec2 = v2;
	vec_len = v_len;
	return Cosine();
}

