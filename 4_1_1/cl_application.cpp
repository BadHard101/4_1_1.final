#include <string>
#include <iostream>
#include <vector>
#include "cl_base.h"
#include "cl_application.h"
#include "cl_1.h"
#include "cl_3.h"
#include "cl_2.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
#include <stdlib.h>

cl_base::TYPE_SIGNAL cl_application::get_signal_method(int cl_num)
{
	switch (cl_num)
	{
	case 1: return SIGNAL_D(cl_1::signal);
	case 2: return SIGNAL_D(cl_2::signal);
	case 3: return SIGNAL_D(cl_3::signal);
	case 4: return SIGNAL_D(cl_4::signal);
	case 5: return SIGNAL_D(cl_5::signal);
	case 6: return SIGNAL_D(cl_6::signal);
	}
	return nullptr;
}


cl_base::TYPE_HANDLER cl_application::get_handler_method(int cl_num)
{
	switch (cl_num)
	{
	case 1: return HANDLER_D(cl_1::handler);
	case 2: return HANDLER_D(cl_2::handler);
	case 3: return HANDLER_D(cl_3::handler);
	case 4: return HANDLER_D(cl_4::handler);
	case 5: return HANDLER_D(cl_5::handler);
	case 6: return HANDLER_D(cl_6::handler);
	}
	return nullptr;
}

cl_application::cl_application(cl_base* parent = nullptr)
{
	cl_base::root->set_parent(parent);
	cl_base::root->set_name("__root__");
	cl_base::root->children.push_back(root);
}

void cl_application::bild_tree_objects_by_names()
{
	int num_class;
	string name1, name2;
	cin >> name1;
	cl_base* child1 = new cl_base(name1, nullptr);
	cl_base* child2;
	while (true)
	{
		cin >> name1;
		if (name1 == "endtree")
		{
			return;
		}
		cin >> name2 >> num_class;
		switch (num_class)
		{
		case 1:
			child2 = new cl_1(name2, root->get_object_by_name(name1));
			break;
		case 2:
			child2 = new cl_2(name2, root->get_object_by_name(name1));
			break;
		case 3:
			child2 = new cl_3(name2, root->get_object_by_name(name1));
			break;
		case 4:
			child2 = new cl_4(name2, root->get_object_by_name(name1));
			break;
		case 5:
			child2 = new cl_5(name2, root->get_object_by_name(name1));
			break;
		case 6:
			child2 = new cl_6(name2, root->get_object_by_name(name1));
			break;
		default:
			break;
		}
	}
}

string cl_application::bild_tree_objects_by_path()
{

	int num_class;
	string path, new_obj_name;

	cin >> path;
	cl_base* root1 = new cl_1(path, nullptr);
	current = root1;

	cl_base* child;

	while (true)
	{
		cin >> path;
		if (path == "endtree")
			return "";

		cin >> new_obj_name >> num_class;
		
		current = get_object_by_coord(path);
		if (current == nullptr) { return path; }

		switch (num_class)
		{
		case 1:
			child = new cl_1(new_obj_name, current);
			break;
		case 2:
			child = new cl_2(new_obj_name, current);
			break;
		case 3:
			child = new cl_3(new_obj_name, current);
			break;
		case 4:
			child = new cl_4(new_obj_name, current);
			break;
		case 5:
			child = new cl_5(new_obj_name, current);
			break;
		case 6:
			child = new cl_6(new_obj_name, current);
			break;
		default:
			break;
		}

		/*cout << "\nObject tree";
		root->children[0]->print_tree_format();
		cout << endl;*/
	}

	return "";
}

bool cl_application::build_tree() //CL_3_2
{
	string coord = bild_tree_objects_by_path();
	if (coord != "") {
		cout << "Object tree";
		root->children[0]->print_tree_format();
		cout << "\nThe head object " << coord << " is not found";
		return false;
	}
	return true;
}

void cl_application::object_search() //CL_3_2
{
	cl_base* ob;
	string command, path;
	current = root->children[1];
	while (true)
	{
		cin >> command;
		if (command == "END")
			return;

		cin >> path;
		cout << endl;

		if (command == "FIND")
		{
			ob = get_object_by_coord(path);
			if (ob == nullptr)
				cout << path << "     Object is not found";
			else
				cout << path << "     Object name: " << ob->get_name();
		}
		else if (command == "SET")
		{
			ob = get_object_by_coord(path);
			if (ob == nullptr)
				cout << "Object is not found: " << current->get_name() << " " << path;
			else {
				current = ob;
				cout << "Object is set: " << current->get_name();
			}
		}
	}
}

void cl_application::bild_tree_readiness()
{
	string name;
	int status_num;
	cl_base* ob;
	while (true)
	{
		cin >> name;
		if (name == "endtree")
		{
			return;
		}
		cin >> status_num;

		ob = root->get_object_by_name(name);
		ob->set_status(status_num);
	}
}

void cl_application::s_connect(string path_ob1, string path_ob2)
{
	cl_base* ob1;
	cl_base* ob2;

	ob1 = root->children[1]->get_object_by_coord(path_ob1);
	if (ob1 == nullptr)
	{
		cout << "Object " << path_ob1 << " not found" << endl;
		return;
	}
	ob2 = root->children[1]->get_object_by_coord(path_ob2);
	if (ob2 == nullptr)
	{
		cout << "Handler object " << path_ob2 << " not found" << endl;
		return;
	}
	ob1->set_connect(get_signal_method(ob1->get_num()), ob2, get_handler_method(ob2->get_num()));
}

void cl_application::do_emit(string path_ob)
{
	cl_base* ob;
	string message;
	getline(cin, message);
	ob = root->children[1]->get_object_by_coord(path_ob);
	if (ob == nullptr)
	{
		cout << "Object " << path_ob << " not found" << endl;
		return;
	}
	ob->emit(get_signal_method(ob->get_num()), message);
}

void cl_application::do_del_conect(string path_ob1, string path_ob2)
{
	cl_base* ob1;
	cl_base* ob2;
	ob1 = root->children[1]->get_object_by_coord(path_ob1);
	if (ob1 == nullptr)
	{
		cout << "Object " << path_ob1 << " not found" << endl;
		return;
	}
	ob2 = root->children[1]->get_object_by_coord(path_ob2);
	if (ob2 == nullptr)
	{
		cout << "Handler object " << path_ob2 << " not found" << endl;
		return;
	}
	ob1->delete_connect(get_signal_method(ob1->get_num()), ob2, get_handler_method(ob2->get_num()));
}

void cl_application::do_condition(string path_ob)
{
	cl_base* ob;
	int cond;
	cin >> cond;
	ob = root->children[1]->get_object_by_coord(path_ob);
	if (ob == nullptr)
	{
		cout << "Object " << path_ob << " not found" << endl;
		return;
	}
	//ob->readiness(cond);
	ob->set_status(cond);
}

void cl_application::connector() {
	string first_ob, second_ob;
	cin >> first_ob;
	while (first_ob != "end_of_connections")
	{
		cin >> second_ob;
		s_connect(first_ob, second_ob);
		cin >> first_ob;
	}
}

void cl_application::message_adapter() {
	//root->set_all();
	
	string command = "";
	string path_ob1, path_ob2;

	while (true)
	{
		cin >> command;
		if (command == "END")
			return;

		if (command == "EMIT")
		{
			cin >> path_ob1;
			do_emit(path_ob1);
		}
		else if (command == "DELETE_CONNECT")
		{
			cin >> path_ob1 >> path_ob2;
			do_del_conect(path_ob1, path_ob2);
		}
		else if (command == "SET_CONDITION")
		{
			cin >> path_ob1;
			do_condition(path_ob1);
		}
		else if (command == "SET_CONNECT")
		{
			cin >> path_ob1 >> path_ob2;
			s_connect(path_ob1, path_ob2);
		}
	}
}

int cl_application::exec_app() //EDITED CL_3_2
{
	if (build_tree())
	{
		cout << "Object tree";
		root->children[0]->print_tree_format();

		connector();
		message_adapter();
	}
	return 0;
}
