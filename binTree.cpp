//
//Binary Tree
//
//Gregory C. Tacker gctacker
//
#include "binTree.h"
#include "Scanner.h"
#include "Print.h"
#include "common.h"
#include "Token.h"


binTree::binTree()//set pointers to null when a bintree is created
{
	this->line = NULL;
	this->left = NULL;
	this->right = NULL;

}

binTree:: ~binTree()//desconstruct bintree
{
	if(this->right != NULL)
	{
		this->right->~binTree();
	}


	if(this->left != NULL)
	{	
		this->left->~binTree();
	}
	
	delete this;

}

void binTree::setName(string str)//set the name 
{
	this->name = str;
}

void binTree::addLine(string str)//add line number in linked list
{
	Token *temp = new Token();//use token for linked list 
	temp->setLiteral(str);
	Token *temp1 = NULL;
	temp->next = NULL;

	
	if(this->line == NULL)//test if first element
	{

		this->line = temp;
	}
	else
	{

		temp1 = this->line;
		while(temp1->next != NULL)// find the end
			{

				temp1 = temp1->next;
			}
		temp1->next = temp;//add the line number
	}


}

binTree* binTree::addRoot(binTree *head, string str, string ln)
{

//initialize temp variables
	binTree *temp;
	temp = new binTree();
	temp->setName(str);
	if(head->name.empty())//test if head is empty
	{	

		head->name = str;
	}
	
	if(head->name.compare(str) == 0)//test if element is already in the tree
		{	
			head->addLine(ln);
		}
	else
	{

		
		if(head->name.compare(str) > 0)//sort the element out before adding it
			{

				if(head->right != NULL)
				{
					head->right = head->addRoot(head->right, str,ln);
				}
				else
				{
					head->right = temp;//add the element and line number
					temp->addLine(ln);

				}
			}
		
		if(head->name.compare(str) < 0)
			{

				if(head->left != NULL)
				{
					
					head->left = head->addRoot(head->left, str,ln);
				}
				else
				{
					
					head->left = temp;//add the element and line number
					temp->addLine(ln);

				}
			}
		}
	return head;
}

void binTree::printTree()//go through the tree and print it in order
{
	string str1;
	Token *temp;
	temp = this->line;
	if(this->right != NULL)
	{
		this->right->printTree();
	}
cout<<" ";
str1 = this->name;
str1.resize(7);
cout<<str1;


if(this->name.compare(0, 7, str1) !=0)
{
	cout<<"\t\t";
}
else
cout<<"\t";
	while(temp != NULL)
	{
				
			cout<< "\t";
			cout<<temp->getStringLiteral();
			temp = temp->next;
	}
cout<<"\n";
	if(this->left != NULL)
	{	
		this->left->printTree();
	}
	
	
	

}
