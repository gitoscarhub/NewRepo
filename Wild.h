#pragma once
#include "stdafx.h"


using namespace std;
using namespace sf;

class Wild
{
public:
	// Constructor de la clase 
	Wild();
	~Wild();
	void _Loop();

private:
	void _Actualizar(float deltaT);
	void _ProcesarEventos();
	void _Dibujar();
	void _ActualizarPuntaje();
	void _Disparar();
	RenderWindow* _wnd;
	mira* _disparo;
	enemigo* _enemigo;
	fondo* _fondo;
	Bombas* _bombardeo;
	class Replay* _reinicio;

	Text _puntaje;
	Font _fuente;
	Clock _reloj;
	Time dt;
	Sprite impacto;
	Texture Timpacto;
	Sprite inicio;
	Texture _inicio;
	Sprite Reinicio;
	Texture _replay;
	FloatRect bounds;
	Vector2i mousePosition;

	int _puntos = 0, derrotas = 0, aux = 0,x=0;
	int disparo = 0;
	bool Entrar = true;
	float deltaT = 0.0f;
	
	
};
