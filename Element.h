#pragma once
#include <vector>
#include <string>
#include "IIterator.h"
class Element
{
private:
	std::string str;
	std::vector<Element*>children;
	class ElementIterator 
		:public IIterator
	{
	private:
		Element* element;
		int currentChild;
	public:
		ElementIterator(Element* e) { element = e; };
		void reset() { currentChild = 0; };
		void moveNext() { ++currentChild; };
		Element* getCurrent() { return element->children[currentChild]; };
		bool isDone() { return currentChild == element->children.size() ? true : false; };
	};
public:
	Element(std::string s) { str = s; };
	~Element() { for (auto ch : children)delete ch; };
	std::string getStr() { return str; };
	ElementIterator* createIterator() { if (children.size() == 0)return nullptr; else return new ElementIterator(this); };
	void add(Element* e) { children.push_back(e); };
	//void remove(Element* e){}
};

