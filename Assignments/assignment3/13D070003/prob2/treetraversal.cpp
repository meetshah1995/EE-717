/*DO NOT EDIT THIS FILE*/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
#include "bst.h"

int main(int argc, char **argv)
{
	if(argc != 3){
		cout << "Pass <input file> <outputfile> as arguments when you run the executable" << endl;
		std::exit(-1);
	}
		

	std::ifstream fp;
	std::ofstream fp1;
	fp.open(argv[1]);
	fp1.open(argv[2]);

	if(!fp){
		cout << "Input file " << argv[1] << " not present" << endl;
		exit(1);
	}

	int num, i;
	BinSearchTree *T;
	
	fp >> num;
	
	char *str = new char[num];
	fp >> str[0];

	T = new BinSearchTree(str[0]);
	for(i=1; i<num; i++){
		fp >> str[i];
		T->buildTree(T,str[i]);
	}
	fp1 << "(";
	T->printTreePreOrder(T,fp1);
	fp1 << ")";
	fp1 << "(";
	T->printTreeInOrder(T,fp1);
	fp1 << ")";
	return(0);
}
















