#ifndef CL_BASE_H
#define CL_BASE_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class cl_base
{
	string object_name = "";
	cl_base* parent;
	int index = 0;
	int status = 0;
public:
	static cl_base* root;
	vector <cl_base*> children;
	cl_base();
	cl_base(string object_name, cl_base* parent);
	void set_name(string name);
	void set_parent(cl_base* parent);
	cl_base* get_parent();
	string get_name();

	void set_status(int);
	int get_status();

	cl_base* get_object_by_name(string name);
	cl_base* get_child_by_name(string name);
	void print_tree(); 

	void print_tree_format(int k = 0);
	void print_tree_status(int k = 0);

	~cl_base();
};

#endif // !CL_BASE_H

/*
ro
ro o1
ro o2
o2 o4
o2 o5
o1 o7
endtree
*/