#ifndef CL_5_H
#define CL_5_H
#include "cl_base.h"
class cl_5 : public cl_base {

public:
	cl_5(string object_name, cl_base* parent) :cl_base(object_name, parent) 
	{
		this->cl_num = 5;
	};
	void signal(string& message)
	{
		cout << endl << "Signal from " << this->get_adress();
		message += " (class: 5)";
	}
	void handler(string message)
	{
		cout << endl << "Signal to " << this->get_adress() << " Text: " << message;
	}
};
#endif