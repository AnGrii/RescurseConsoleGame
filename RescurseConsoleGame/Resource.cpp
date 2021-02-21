#include "Resource.h"

uint64_t Resource::getLog() { return log; }
uint64_t Resource::addLog(uint64_t count)
{
	uint64_t limit = UINT64_MAX - log;

	if ( limit > count ) {
		log += count;
	}
	else {
		log = UINT64_MAX;
	}
}
uint64_t Resource::reduceLog(uint64_t count)
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

uint64_t Resource::getWood()
{
	return wood;
}
uint64_t Resource::addWood(uint64_t count)
{
	uint64_t limit = UINT64_MAX - wood;

	if (limit > count) {
		wood += count;
	}
	else {
		wood = UINT64_MAX;
	}
}
uint64_t Resource::reduceWood(uint64_t count)
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

uint64_t Resource::getStone()
{
	return stone;
}
uint64_t Resource::addstone(uint64_t count)
{
	uint64_t limit = UINT64_MAX - stone;

	if (limit > count) {
		stone += count;
	}
	else {
		stone = UINT64_MAX;
	}
}
uint64_t Resource::reduceStone(uint64_t count)
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

