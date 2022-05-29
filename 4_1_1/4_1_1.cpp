#include "cl_application.h"
#include "cl_2.h"

int main()
{
	setlocale(LC_ALL, "ru");
	cl_application ob_cl_application(nullptr);
	ob_cl_application.bild_tree_objects();
	ob_cl_application.bild_tree_readiness();
	return ob_cl_application.exec_app();
}