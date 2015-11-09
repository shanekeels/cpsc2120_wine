/*
 * wine.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: skeels
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

double N;
int D;
string readfile;
double quality;
double a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
double *input;



typedef pair<double,double> Point;
struct Node {


	double *key;
	double quality;
	Node *left, *right;
	Node(double q, double *k){quality = q; key = k; left = right = NULL;}
	Node(double *k){key = k; quality = 0; left = right = NULL;}
	Node(){key = NULL; quality = 0; left = right = NULL;}
};

Node **Points;

Node * insert(Node *T, int *val, int d){
	if(T == NULL) return Node(val);
	if(val[d] < T->key[d]) T->left = insert(T->left, val, (d+1)%D);
	else T->right = insert(T->right, val, (d+1)%D);
	return T;
}


int main(int argc, char *argv[]){
	vector<Node> v;
	/*
	if(argc != 3){
		cout <<"\n"<< argv[0] << " USAGE: <inputFile> <k>" <<"\n" << endl;
		exit(1);
	}
	 */

	//readfile = argv[1];
	//D = atoi(argv[2]);
	input = new double[11];

	ifstream inputStream("wine.txt");
	inputStream >> N >> D;
	Points = new Node*[3961];

	/*
	while(inputStream >> quality >> a0 >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> a10){


	input[0] = a0;
	input[1] = a1;
	input[2] = a2;
	input[3] = a3;
	input[4] = a4;
	input[5] = a5;
	input[6] = a6;
	input[7] = a7;
	input[8] = a8;
	input[9] = a9;
	input[10] =a10;
	v.push_back(Node(quality,input));

	}
	*/
	/*
	*/
	int i = 0;
	for(int i = 0; i < N; i++){
		inputStream >> quality;
		for(int j = 0; j < 11; j++){

			inputStream >> input[j];
		}
		Points[i]= new Node(quality,input);



	}
	cout << N << " " << D <<  endl;
	cout << "Quality: " << Points[0]->quality << " " << Points[0]->key[0] << " " <<  Points[0]->key[1] << " " << Points[0]->key[2] << " " << Points[0]->key[3] << " " << Points[0]->key[4] << " " << Points[0]->key[5] << "\n";
	//cout << "Quality: " << v[N-2].quality << " :: " << v[N-2].key[0] << " " << v[N-2].key[1] << " "<< v[N-2].key[2] << " "<< v[0].key[3] << " "<< v[0].key[4] << " "<< v[0].key[5] << " "<< v[0].key[6] << " "<< v[0].key[7] << " "<< v[0].key[8] << " "<< v[0].key[9] << " "<< v[0].key[10] << "\n";
}




