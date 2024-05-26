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

bool Item::Equal(const std::shared_ptr<Item>& item1, const std::shared_ptr<Item>& item2) {
	// ƒAƒCƒeƒ€‚ÌID‚ðŒ©‚Ä“¯‚¶‚©‚Ç‚¤‚©‚ð”»’è‚·‚é
    return item1->GetID() == item2->GetID();
}
