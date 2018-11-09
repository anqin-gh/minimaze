#ifndef RENDERER_H
#define RENDERER_H

#include <cstdint>

namespace minimaze {

class Renderer {
public:
	Renderer() = default;
	virtual ~Renderer() = default;

	virtual void clear_screen() const = 0;
	virtual void refresh() 		const = 0;

	virtual void draw_player		(int8_t x, int8_t y) const = 0;
	virtual void draw_enemy_lr		(int8_t x, int8_t y) const = 0;
	virtual void draw_enemy_wander	(int8_t x, int8_t y) const = 0;
	virtual void draw_wall_normal	(int8_t x, int8_t y) const = 0;
	virtual void draw_wall_mortal	(int8_t x, int8_t y) const = 0;
	virtual void draw_goal			(int8_t x, int8_t y) const = 0;
};

} // minimaze

#endif // RENDERER_H
