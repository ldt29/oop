#pragma once
#include <list>
#include <iostream>
#include <vector>
#include <memory>
#include "CustomClass.h"
class Object;

class Content
{
public:
	virtual void output(std::ostream& out) { //virtual function for output
		std::cout << "the operator is not supported for this type." << std::endl;
	}
	virtual Content& operator+=(int y) { return *this; }
	virtual Content& operator+=(std::string y) { return *this; }
	virtual Object& operator[](int pos);
	virtual ~Content() {};
};

class IntContent : public Content
{
private:
	int x;
public:
	IntContent(int _x) : x(_x) {}
	void output(std::ostream& out) { //???
		out << x;
	}
	virtual Content& operator+=(int y) {
		x += y;
		return *this;
	}
};

class StringContent : public Content
{
private:
	std::string x;
public:
	StringContent(std::string _x) : x(_x) {}
	void output(std::ostream& out) {  //???
		out << x;
	}
	virtual Content& operator+=(std::string y) {
		x += y;
		return *this;
	}

};
// The following codes are not working

class VectorContent : public Content
{
private:
	std::vector<Object> x; //Object is not defined???
public:
	VectorContent(const std::vector<Object>& _x) : x(_x) {}
	Object& operator[](int pos) {
		return x[pos];
	}
};

class CustomContent : public Content
{
private:
	CustomClass x;
public:
	CustomContent(const CustomClass& _x) : x(_x) {}
};

class Object
{
private:
	std::shared_ptr<Content> pt = nullptr;

public:
	Object() {}
	Object(int x) {
		
		pt = std::shared_ptr<Content>(new IntContent(x)); // where to delete? maybe use std::shared_ptr?
	}
	Object(const std::string& x) {
		pt = std::shared_ptr<Content>(new StringContent(x));
	}
	// The following codes are not working
	Object(const std::vector<Object>& x) {
		pt = std::shared_ptr<Content>(new VectorContent(x));
	}
	Object(const CustomClass& x) {
		pt = std::shared_ptr<Content>(new CustomContent(x));
	}
	
	friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
		obj.pt->output(out);
		return out;
	}
	Object& operator=(const Object& other) {
		pt = other.pt;
		return *this;
	}

	Object& operator+=(int y) {
		pt->operator+=(y);
		return *this;
	}
	Object& operator+=(const std::string& y) {
		pt->operator+=(y);
		return *this;
	}
	Object& operator[](int pos) {
		return pt->operator[](pos);
	}
	//need more operators......
};

Object& Content::operator[](int pos) {
	Object a(1);
	return a;
}