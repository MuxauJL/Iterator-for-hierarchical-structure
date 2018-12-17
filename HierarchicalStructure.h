#pragma once
#include "Element.h"
#include <stack>

class HierarchicalStructure
{
private:
	class Iterator
		:public IIterator
	{
	private:
		HierarchicalStructure* structure;
		Element* pos;
		std::stack<IIterator*>stack;
	public:
		Iterator(HierarchicalStructure* hs) { structure = hs; pos = structure->root; };
		void reset() { pos = structure->root; };
		void moveNext();
		Element* getCurrent() { return pos; };
		bool isDone();
	};
	Element* root;
public:
	HierarchicalStructure(std::string s) { root = new Element(s); };
	~HierarchicalStructure();
	Iterator* createIterator() { return new Iterator(this); };
	void add(Element* e) { root->add(e); };
};
