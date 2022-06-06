#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H

#include "cl_base.h"
#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
#include <string>
using namespace std;

class cl_application : public cl_base
{
public:
	cl_base::TYPE_SIGNAL get_signal_method(int);
	cl_base::TYPE_HANDLER get_handler_method(int);
	cl_application(cl_base* parent);
	bool build_tree(); //CL_3_2
	void bild_tree_objects_by_names();
	string bild_tree_objects_by_path(); //EDITED CL_3_2 (WAS bild_tree_objects)
	void bild_tree_readiness();
	void object_search(); //CL_3_2
	int exec_app(); //EDITED CL_3_3


	//CL_3_3
	
	void connector();
	void do_connect(string path_ob1, string path_ob2);
	void message_adapter();
	void do_emit(string path_ob);
	void do_del_connect(string path_ob1, string path_ob2);
	void do_condition(string path_ob);
};

#endif // !CL_APPLICATION_H