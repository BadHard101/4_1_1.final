#ifndef CL_6_H
#define CL_6_H
#include "cl_base.h"
class cl_6 : public cl_base {

public:
	cl_6(string object_name, cl_base* parent) :cl_base(object_name, parent) 
	{
		this->cl_num = 6;
	};
	void signal(string& message)
	{
		cout << endl << "Signal from " << this->get_address();
		message += " (class: 6)";
	}
	void handler(string message)
	{
		cout << endl << "Signal to " << this->get_address() << " Text: " << message;
	}
};
#endif