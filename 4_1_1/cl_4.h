#ifndef CL_4_H
#define CL_4_H
#include "cl_base.h"
class cl_4 : public cl_base {

public:
	cl_4(string object_name, cl_base* parent) :cl_base(object_name, parent) 
	{
		this->cl_num = 4;
	};
	void signal(string& message)
	{
		cout << endl << "Signal from " << this->get_address();
		message += " (class: 4)";
	}
	void handler(string message)
	{
		cout << endl << "Signal to " << this->get_address() << " Text: " << message;
	}
};
#endif