#include "Resource.h"

uint64_t Resource::getLog() { return log; }
void Resource::addLog(uint64_t count)
{
	uint64_t limit = UINT64_MAX - log;

	if ( limit > count ) {
		log += count;
	}
	else {
		log = UINT64_MAX;
	}
}
void Resource::reduceLog(uint64_t count)
{
	if (log > count) {
		log -= count;
	}
	else {
		log = 0;
	}
}
void Resource::setLog(uint64_t count)
{
	log = count;
}

uint64_t Resource::getWood() { return wood; }
void Resource::addWood(uint64_t count)
{
	uint64_t limit = UINT64_MAX - wood;

	if (limit > count) {
		wood += count;
	}
	else {
		wood = UINT64_MAX;
	}
}
void Resource::reduceWood(uint64_t count)
{
	if (wood > count) {
		wood -= count;
	}
	else {
		wood = 0;
	}
}
void Resource::setWood(uint64_t count)
{
	wood = count;
}

uint64_t Resource::getStone(){ return stone; }
void Resource::addstone(uint64_t count)
{
	uint64_t limit = UINT64_MAX - stone;

	if (limit > count) {
		stone += count;
	}
	else {
		stone = UINT64_MAX;
	}
}
void Resource::reduceStone(uint64_t count)
{
	if (stone > count) {
		stone -= count;
	}
	else {
		stone = 0;
	}
}
void Resource::setStone(uint64_t count)
{
	stone = count;
}

