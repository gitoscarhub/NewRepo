#pragma once
#include "stdafx.h";

using namespace std;
using namespace sf;

class Replay
{
	
private:
	Bombas* _bombardeo;
	float deltaT=0.0f; 
public:
	Replay() {
		_bombardeo = new Bombas;
		float deltaT = 0.0f;
		
	}
	~Replay() {};

void Reiniciar() 
{
	float deltaT = 0.0f;
	// Aplicar velocidad al objeto
	_bombardeo->AddAcceleration(Vector2f(0.0f, 9.8f));

	//porcentaje gravedad 
	float aux = _bombardeo->GetVelocity().y;
	aux = aux * (80.0f / 100.0f);

	// Chequea si el objeto ha salido de la ventana
	if (_bombardeo->GetPosition().y > 500.0f)
	{
		_bombardeo->SetVelocity(Vector2f(0.0f, -aux));
	}
	_bombardeo->Update(deltaT);

				
			
 }
 void Draw(RenderWindow* pWnd)
 {
	_bombardeo->Draw(pWnd);
	
 }
};