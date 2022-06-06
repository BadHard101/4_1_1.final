#ifndef CL_2_H
#define CL_2_H
#include "cl_base.h"
class cl_2 : public cl_base {

public:
	cl_2(string object_name, cl_base* parent) :cl_base(object_name, parent) 
	{
		this->cl_num = 2;
	};
	void signal(string& message)
	{
		cout << endl << "Signal from " << this->get_address();
		message += " (class: 2)";
	}
	void handler(string message)
	{
		cout << endl << "Signal to " << this->get_address() << " Text: " << message;
	}
};
#endif