#include "cl_application.h"

cl_application::cl_application(cl_base* parent = nullptr)
{
	cl_base::root->set_parent(parent);
	cl_base::root->set_name("root");
	cl_base::root->children.push_back(root);
}

void cl_application::bild_tree_objects()
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
			child1 = child2;
			break;
		case 2:
			child2 = new cl_2(name2, root->get_object_by_name(name1));
			child1 = child2;
			break;
		case 3:
			child2 = new cl_3(name2, root->get_object_by_name(name1));
			child1 = child2;
			break;
		case 4:
			child2 = new cl_4(name2, root->get_object_by_name(name1));
			child1 = child2;
			break;
		case 5:
			child2 = new cl_5(name2, root->get_object_by_name(name1));
			child1 = child2;
			break;
		case 6:
			child2 = new cl_6(name2, root->get_object_by_name(name1));
			child1 = child2;
			break;
		default:
			break;
		}
	}
}

int cl_application::exec_app()
{
	cout << root->children[1]->get_name();
	root->children[1]->print_tree1(1);
	return 0;
}