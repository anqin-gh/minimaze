#ifndef RENDSTDP2_H
#define RENDSTDP2_H

#include <Renderer.h>

namespace minimaze {

class RendSTDP2 : public Renderer {
public:
	RendSTDP2();
	~RendSTDP2() override;

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

#endif // RENDSTDP2_H
