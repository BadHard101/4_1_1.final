#include "cl_application.h"

cl_application::cl_application(cl_base* parent = nullptr)
{
	cl_base::root->set_parent(parent);
	cl_base::root->set_name("root");
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
			child2 = new cl_base(name2, root->get_object_by_name(name1));
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
	string delimiter = "/", path, cur_path, name2;

	cin >> path;
	cl_base* root1 = new cl_base(path, nullptr);

	cl_base* child;
	cl_base* current = root1;

	while (true)
	{
		cin >> path;
		cur_path = path;
		if (path == "endtree")
		{
			return;
		}

		cin >> name2 >> num_class;
		
		size_t pos = 0;
		string token;

		if (cur_path == "/")
		{
			current = root1;
		}
		else {
			current = root1;
			while ((pos = cur_path.find(delimiter)) != string::npos) {
				token = cur_path.substr(0, pos);

				if (token != "") {
					current = current->get_child_by_name(token);
					if (current == nullptr) { return path; }
				}

				cur_path.erase(0, pos + delimiter.length());
			}
			current = current->get_child_by_name(cur_path);
			if (current == nullptr) { return path; }

		}

		switch (num_class)
		{
		case 1:
			child = new cl_base(name2, current);
			break;
		case 2:
			child = new cl_2(name2, current);
			break;
		case 3:
			child = new cl_3(name2, current);
			break;
		case 4:
			child = new cl_4(name2, current);
			break;
		case 5:
			child = new cl_5(name2, current);
			break;
		case 6:
			child = new cl_6(name2, current);
			break;
		default:
			break;
		}

		cout << "\nObject tree";
		root->children[0]->print_tree_format();
		cout << endl;
	}

	return "";
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

int cl_application::exec_app()
{
	cout << "Object tree";
	root->children[0]->print_tree_format();
	cout << endl;
	cout << "The tree of objects and their readiness";
	root->children[0]->print_tree_status();

	return 0;
}

void cl_application::build_tree()
{
	string coord = bild_tree_objects_by_path();
	if (coord != "")
		cout << "The head object " << coord << " is not found";
}