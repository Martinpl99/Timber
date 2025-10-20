#pragma once
#include <SFML/System/Time.hpp>
using namespace sf;

class IMoveObjectRenderer
{
public:
	IMoveObjectRenderer() = default;
	virtual ~IMoveObjectRenderer() = default;
	virtual void render(const Time& A_time_dt) = 0;
};
