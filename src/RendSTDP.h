#ifndef RENDSTDP_H
#define RENDSTDP_H

#include <Renderer.h>

namespace minimaze {

class RendSTDP : public Renderer {
public:
	RendSTDP();
	~RendSTDP() override;

	void clear_screen() const override;
	void refresh() 		const override;

	void draw_player			(int8_t x, int8_t y) const override;
	void draw_enemy_lr			(int8_t x, int8_t y) const override;
	void draw_enemy_wandering	(int8_t x, int8_t y) const override;
	void draw_wall_normal		(int8_t x, int8_t y) const override;
	void draw_wall_mortal		(int8_t x, int8_t y) const override;
	void draw_goal				(int8_t x, int8_t y) const override;
};

} // minimaze

#endif // RENDSTDP_H
