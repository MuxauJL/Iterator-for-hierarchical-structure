#pragma once
//#include "Element.h"
class Element;
class IIterator {
public:
	virtual void reset() = 0;
	virtual void moveNext() = 0;
	virtual Element* getCurrent() = 0;
	virtual bool isDone() = 0;
};