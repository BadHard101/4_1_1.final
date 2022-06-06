#include "cl_application.h"

int main()
{
	setlocale(LC_ALL, "ru");
	cl_application ob_cl_application(nullptr);
	return ob_cl_application.exec_app();
}