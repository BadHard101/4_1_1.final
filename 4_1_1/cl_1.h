#ifndef CL_1_H
#define CL_1_H
#include "cl_base.h"
class cl_1 : public cl_base {

public:
	cl_1(string object_name, cl_base* parent) :cl_base(object_name, parent) 
	{
		this->cl_num = 1;
	};
	void signal(string& message) ////
	{
		cout << endl << "Signal from " << this->get_address();
		message += "(class: 1)";
	}
	void handler(string message) ////
	{
		cout << endl << "Signal to " << this->get_address() << " Text: " << message;
	}
};
#endif