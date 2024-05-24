#include "Item.h"

Item::Item(void) :
	id_(0),
	count_(0) {

}

Item::Item(int id, int count) :
	id_(id),
	count_(count) {

}

void Item::SetID(int id) {
	id_ = id;
}

int Item::GetID(void) const {
	return id_;
}

void Item::AddCount(int count) {
	count_ += count;
}

void Item::SetCount(int count) {
	count_ = count;
}

int Item::GetCount(void) const {
	return count_;
}
