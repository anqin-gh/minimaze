#include <RendSTDP2.h>
#include <StdPijo.h>

namespace minimaze {

RendSTDP2::RendSTDP2() {
	STDP::Inicializar();
	clear_screen();
}

RendSTDP2::~RendSTDP2() {
	refresh();
	STDP::Terminar();
}

void RendSTDP2::clear_screen() const {
	STDP::BorraPantalla();
}

void RendSTDP2::refresh() const {
	STDP::Refrescar();
}


void RendSTDP2::draw_player(int8_t x, int8_t y) const {
	STDP::PonCursor(x, y);
	STDP::CambiaColor(A_BOLD, STDP_C_VERDE, STDP_C_NEGRO);
	STDP::sout << "P";
}

void RendSTDP2::draw_enemy_lr(int8_t x, int8_t y) const {
	STDP::PonCursor(x, y);
	STDP::CambiaColor(A_BOLD, STDP_C_AMARILLO, STDP_C_NEGRO);
	STDP::sout << "E";
}

void RendSTDP2::draw_enemy_wander(int8_t x, int8_t y) const {
	STDP::PonCursor(x, y);
	STDP::CambiaColor(A_BOLD, STDP_C_ROJO, STDP_C_NEGRO);
	STDP::sout << "W";
}

void RendSTDP2::draw_wall_normal(int8_t x, int8_t y) const {
	STDP::PonCursor(x, y);
	STDP::CambiaColor(A_BOLD, STDP_C_VERDE, STDP_C_NEGRO);
	STDP::sout << "#";
}

void RendSTDP2::draw_wall_mortal(int8_t x, int8_t y) const {
	STDP::PonCursor(x, y);
	STDP::CambiaColor(A_BOLD, STDP_C_ROJO, STDP_C_NEGRO);
	STDP::sout << "*";
}

void RendSTDP2::draw_goal(int8_t x, int8_t y) const {
	STDP::PonCursor(x, y);
	STDP::CambiaColor(A_BOLD, STDP_C_BLANCO, STDP_C_NEGRO);
	STDP::sout << "@";
}

} // minimaze
