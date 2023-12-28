#include "stdafx.h"


using namespace sf;
using namespace std;
Wild::Wild()
{
	
	_wnd = new RenderWindow(VideoMode(800, 600), "Wild physics Benetti");
	_wnd->setFramerateLimit(60);

	_disparo = new mira;
	_enemigo = new enemigo;
	_fondo = new fondo;
	_bombardeo = new Bombas;
	_reinicio = new Replay;

	_fuente.loadFromFile("arial.ttf");
	_puntaje.setFont(_fuente);
	_puntaje.setPosition(0.0f, 0.0f);
	_puntaje.setCharacterSize(50);
	_puntaje.setFillColor(Color::Blue);

	_inicio.loadFromFile("fondo.png");
	inicio.setTexture(_inicio);
	Timpacto.loadFromFile("impacto.png");
	impacto.setTexture(Timpacto);
	
	_disparo;
	_disparo->Posicionar(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	_replay.loadFromFile("replay.png");
	Reinicio.setTexture(_replay);
	Reinicio.setPosition(600.0f, 100.0f);
	bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	
}
Wild::~Wild()
{
	delete _wnd;
	delete _disparo;
	delete _enemigo;
	delete _fondo;
	delete _bombardeo;
	delete _reinicio;
}

void Wild::_ActualizarPuntaje()
{
	
	char pts[100];
	_itoa_s((_puntos * 10), pts, 10);
	_puntaje.setString(pts);
}

void Wild::_ProcesarEventos() 
{
	Event evt;
	float deltaT = 0.0;
	while (_wnd->pollEvent(evt)) {
		switch (evt.type) {
		case Event::Closed:
			_wnd->close();
			break;

		case Event::MouseMoved:
			_disparo->Posicionar(evt.mouseMove.x, evt.mouseMove.y);
			break;

		case Event::MouseButtonPressed:
			if (evt.mouseButton.button == Mouse::Button::Left)
			{
				dt = _reloj.getElapsedTime();
				_Disparar();
				_disparo->FuegoPistola();
				
			}
		
			if (evt.type == Event::MouseButtonPressed) 
			{
				Vector2i mousePosition = Mouse::getPosition(*_wnd);
				FloatRect bounds = Reinicio.getGlobalBounds();
				if (bounds.contains(mousePosition.x, mousePosition.y))
				{
					_reinicio->Reiniciar();
					cout << "Se hizo clic en el sprite Reinicio" << std::endl;

				}
			
			
			}
			break;
		}
	}

}

void Wild::_Actualizar(float deltaT) 
{

	for (size_t i = 0; i < 1; i++) {

		_enemigo[i].ActualizarE(_wnd);
	}


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



void Wild::_Disparar() 
{
	
	//chequeamos colisiones con el disparo
	Vector2f playerPos = _disparo->ObtenerPosicion();
	
	for (int i = 0; i < 2; i++) {

		if (_enemigo[i].EstaActivo()) {

			_bombardeo[i].CambioTextura(playerPos.x, playerPos.y, false);
			if (_bombardeo[i].EstaEncima(playerPos.x, playerPos.y))
			{
				_puntos++; aux++;
				_ActualizarPuntaje();
			}
		}
		if (aux == _puntos) {
			_bombardeo[i].CambioTextura(playerPos.x, playerPos.y, true);
			
		}
		
		_reloj.restart();
		x = x + 1 * dt.asMilliseconds();
	}
}

void Wild::_Dibujar() 
{
	_wnd->clear();
	_wnd->draw(inicio);
	//_reinicio->Draw(_wnd);
	_wnd->draw(Reinicio);
	_bombardeo->Draw(_wnd);
	for (int i = 0; i < 1; i++) {
		if (_enemigo[i].EstaActivo())
		{
			_enemigo[i].Dibujar(_wnd);
		}
	}
	_disparo->Dibujar(_wnd);
	_wnd->draw(_puntaje);
	_wnd->display();
}


void Wild::_Loop() 
{
	while (_wnd->isOpen()) {
		// Calcula el tiempo transcurrido desde la última iteración del bucle
		float deltaT = _reloj.restart().asSeconds();
		_wnd->clear();

		_Actualizar(deltaT);
		_ProcesarEventos();
		_Dibujar();
	}
}
