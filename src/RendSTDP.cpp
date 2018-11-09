#include <RendSTDP.h>
#include <StdPijo.h>

namespace minimaze {

RendSTDP::RendSTDP() {
	STDP::Inicializar();
	clear_screen();
}

RendSTDP::~RendSTDP() {
	refresh();
	STDP::Terminar();
}

void RendSTDP::clear_screen() const {
	STDP::BorraPantalla();
}

void RendSTDP::refresh() const {
	STDP::Refrescar();
}


void RendSTDP::draw_player(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_VERDE, STDP_C_NEGRO);
	STDP::PonCursor(x, y);
	STDP::sout << "P";
}

void RendSTDP::draw_enemy_lr(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_AMARILLO, STDP_C_NEGRO);
	STDP::PonCursor(x, y);
	STDP::sout << "E";
}

void RendSTDP::draw_enemy_wander(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_ROJO, STDP_C_NEGRO);
	STDP::PonCursor(x, y);
	STDP::sout << "W";
}

void RendSTDP::draw_wall_normal(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_VERDE, STDP_C_NEGRO);
	STDP::PonCursor(x, y);
	STDP::sout << "#";
}

void RendSTDP::draw_wall_mortal(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_ROJO, STDP_C_NEGRO);
	STDP::PonCursor(x, y);
	STDP::sout << "*";
}

void RendSTDP::draw_goal(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_BLANCO, STDP_C_NEGRO);
	STDP::PonCursor(x, y);
	STDP::sout << "@";
}

} // minimaze
