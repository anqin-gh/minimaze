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
	STDP::CambiaColor(A_BOLD, STDP_C_VERDE, STDP_C_NEGRO);
	STDP::PonCursor(2*x, 2*y);
	STDP::sout << "PP";
	STDP::PonCursor(2*x, 2*y+1);
	STDP::sout << "PP";
}

void RendSTDP2::draw_enemy_lr(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_AMARILLO, STDP_C_NEGRO);
	STDP::PonCursor(2*x, 2*y);
	STDP::sout << "EE";
	STDP::PonCursor(2*x, 2*y+1);
	STDP::sout << "EE";
}

void RendSTDP2::draw_enemy_wandering(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_ROJO, STDP_C_NEGRO);
	STDP::PonCursor(2*x, 2*y);
	STDP::sout << "WW";
	STDP::PonCursor(2*x, 2*y+1);
	STDP::sout << "WW";
}

void RendSTDP2::draw_enemy_chasing(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_ROJO, STDP_C_NEGRO);
	STDP::PonCursor(2*x, 2*y);
	STDP::sout << "CC";
	STDP::PonCursor(2*x, 2*y+1);
	STDP::sout << "CC";
}

void RendSTDP2::draw_wall_normal(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_VERDE, STDP_C_NEGRO);
	STDP::PonCursor(2*x, 2*y);
	STDP::sout << "##";
	STDP::PonCursor(2*x, 2*y+1);
	STDP::sout << "##";
}

void RendSTDP2::draw_wall_mortal(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_ROJO, STDP_C_NEGRO);
	STDP::PonCursor(2*x, 2*y);
	STDP::sout << "**";
	STDP::PonCursor(2*x, 2*y+1);
	STDP::sout << "**";
}

void RendSTDP2::draw_goal(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_BLANCO, STDP_C_NEGRO);
	STDP::PonCursor(2*x, 2*y);
	STDP::sout << "@@";
	STDP::PonCursor(2*x, 2*y+1);
	STDP::sout << "@@";
}

void RendSTDP2::draw_win(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_BLANCO, STDP_C_VERDE);
	STDP::PonCursor(2*x, 2*y);
	STDP::sout << "YOU WIN!";
}

void RendSTDP2::draw_game_over(int8_t x, int8_t y) const {
	STDP::CambiaColor(A_BOLD, STDP_C_AMARILLO, STDP_C_ROJO);
	STDP::PonCursor(2*x, 2*y);
	STDP::sout << "GAME OVER";
}

} // minimaze
