#include "HierarchicalStructure.h"


HierarchicalStructure::~HierarchicalStructure()
{
	/*Iterator* it = createIterator();
	it->reset();*/
}

void HierarchicalStructure::Iterator::moveNext()
{
	if (stack.size() == 0) {
		IIterator* it = pos->createIterator();
		it->reset();
		stack.push(it);
		pos = it->getCurrent();
		it->moveNext();
	}
	else {
		IIterator* it = pos->createIterator();
		if (it == nullptr) {
			pos = stack.top()->getCurrent();
			stack.top()->moveNext();
		}
		else {
			it->reset();
			stack.push(it);
			pos = it->getCurrent();
			it->moveNext();
		}
	}
}

bool HierarchicalStructure::Iterator::isDone()
{
	while (stack.size() != 0 && stack.top()->isDone()) {
		delete stack.top();
		stack.pop();
	}
	if (stack.size() != 0)return false;
	IIterator* it = pos->createIterator();
	if (it != nullptr) {
		delete it;
		return false;
	}
	else 
		return true;
}
