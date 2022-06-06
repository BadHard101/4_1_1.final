#ifndef CL_BASE_H
#define CL_BASE_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(& signal_f) ////
#define HANDLER_D(handler_f)(TYPE_HANDLER)(& handler_f) ////

using namespace std;

class cl_base
{
public:
	typedef void (cl_base::* TYPE_SIGNAL)(string&); ////
	typedef void (cl_base::* TYPE_HANDLER)(string); ////

	string object_name = "";
	cl_base* parent;
	int status = 1;

	struct signal_handler_connection { ////
		cl_base* handler_ob;
		TYPE_SIGNAL signal_method;
		TYPE_HANDLER handler_method;
		signal_handler_connection(cl_base* handler_ob, TYPE_SIGNAL
			signal_method, TYPE_HANDLER handler_method) : handler_ob(handler_ob), signal_method(signal_method), handler_method(handler_method) {};
	};

protected:
	cl_base* current; //CL_3_2
	int cl_num; ////

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
	cl_base* get_child_by_name(string name); //CL_3_2
	void print_tree(); 

	cl_base* get_object_by_coord(string path); //CL_3_2

	void print_tree_format(int k = 0);
	void print_tree_status(int k = 0);

	string get_adress(); ////
	vector <signal_handler_connection*> connections; ////
	void set_connect(TYPE_SIGNAL, cl_base*, TYPE_HANDLER); ////
	void emit(TYPE_SIGNAL, string); ////
	void delete_connect(TYPE_SIGNAL, cl_base*, TYPE_HANDLER); ////
	int get_num(); ////

	//void set_all(); ////
	//void delete_connect(TYPE_SIGNAL, cl_base*, TYPE_HANDLER); ////
	//void emit(TYPE_SIGNAL, string); ////

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