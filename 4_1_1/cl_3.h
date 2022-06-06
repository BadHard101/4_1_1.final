#ifndef CL_3_H
#define CL_3_H
#include "cl_base.h"
class cl_3 : public cl_base {

public:
	cl_3(string object_name, cl_base* parent) :cl_base(object_name, parent) 
	{
		this->cl_num = 3;
	};
	void signal(string& message)
	{
		cout << endl << "Signal from " << this->get_address();
		message += " (class: 3)";
	}
	void handler(string message)
	{
		cout << endl << "Signal to " << this->get_address() << " Text: " << message;
	}
};
#endif