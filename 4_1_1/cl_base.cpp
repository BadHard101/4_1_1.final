#include "cl_base.h"
#include <string>

cl_base* cl_base::root = new cl_base();

cl_base::cl_base()
{
	parent = nullptr;
	status = 1;
}

cl_base::cl_base(string object_name, cl_base* parent)
{
	this->object_name = object_name;
	if (parent == nullptr)
	{
		set_parent(root);
		(this->parent)->children.push_back(this);
	}
	else
	{
		this->parent = parent;
		parent->children.push_back(this);
	}
	children.push_back(this);
	index = (this->parent)->children.size() - 1;
}

void cl_base::set_name(string name)
{
	this->object_name = name;
}

void cl_base::set_parent(cl_base* parent)
{
	this->parent = parent;
}

cl_base* cl_base::get_parent()
{
	return parent;
}

string cl_base::get_name()
{
	return object_name;
}

int cl_base::get_status()
{
	return this->status;
}

void cl_base::set_status(int status)
{
	if (parent->get_status() != 0)
		this->status = status;
	if (this->status == 0) {
		this->status = 1;
		for (int i = 1; i < this->children.size(); i++)
			children[i]->set_status(0);
		this->status = 0;
	}
}

cl_base* cl_base::get_object_by_name(string name)
{
	cl_base* val = nullptr;
	for (int i = 0; i < this->children.size(); i++)
	{
		val = children[i];
		if (children[i]->get_name() == name)
			return children[i];
	}

	for (int i = 1; i < children.size(); i++) {
		val = (children[i]->get_object_by_name(name));
		if ((children[i]->get_object_by_name(name))->get_name() == name)
			return (children[i]->get_object_by_name(name));
	}
	return val;
}

cl_base* cl_base::get_child_by_name(string name)
{
	cl_base* val = nullptr;
	for (int i = 0; i < this->children.size(); i++)
	{
		val = children[i];
		if (children[i]->get_name() == name)
			return children[i];
	}
	return nullptr;
}

void cl_base::print_tree()
{
	cout << root->children[1]->get_name();
	for (int i = 1; i < children.size(); i++)
	{
		cout << "    ";
		cout << children[i]->get_name();
		if (children[i]->children.size() > 1)
		{
			cout << endl << "    ";
			children[i]->print_tree();
		}
		if (i + 1 < children.size())
			cout << endl;
	}

	for (int i = 1; i < children.size(); i++)
	{
		if (children[i]->children.size() > 1)
		{
			children[i]->print_tree();
		}
	}
}

void cl_base::print_tree_format(int k)
{
	for (int i = 1; i < children.size(); i++)
	{
		cout << endl;
		for (int i = 0; i < k; i++)
			cout << "    ";
		cout << children[i]->get_name();
		if (children[i]->children.size() > 1) {
			children[i]->print_tree_format(k + 1);
		}
		for (int j = 0; j < k; j++)
			cout << "    ";
	}
}

void cl_base::print_tree_status(int k)
{
	for (int i = 1; i < children.size(); i++)
	{
		cout << endl;
		for (int i = 0; i < k; i++)
			cout << "    ";
		cout << children[i]->get_name();

		if (children[i]->get_status() != 0)
			cout << " is ready";
		else
			cout << " is not ready";

		if (children[i]->children.size() > 1) {
			children[i]->print_tree_status(k + 1);
		}
		for (int j = 0; j < k; j++)
			cout << "    ";
	}
}

cl_base::~cl_base()
{
}