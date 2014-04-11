//
//
//
//
//
//

#include <iostream>
#include "common.h"
#include "Token.h"

using namespace std;

#ifndef binTree_h
#define binTree_h

class binTree
{
	private:
		string name;
		Token *line;
		binTree *left;
		binTree *right;


	public:
		binTree();
		~binTree();
		void setName(string str);
		void addLine(string str);
		binTree* addRoot(binTree *head, string str, string ln);
		void printTree();
		binTree* deleteTree(binTree *head);


};



#endif
