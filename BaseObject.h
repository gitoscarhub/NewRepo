#pragma once
#include "stdafx.h"


using namespace std;
using namespace sf;

class Bombas
{
private:
    
    Sprite _pSpr;
    Sprite _pSpr1;
    Texture _pTex;
    Texture Timpacto;
    Vector2f _position, _position1;
    Vector2f _acceleration, _acceleration1;
    Vector2f _velocity, _velocity1;
   
    
public:
  

    // Funciones para configurar las propiedades del objeto
    void SetScale(float uniformScale) {_pSpr.setScale(uniformScale, uniformScale); }//Sprite escalado de manera uniforme
    void SetPosition(Vector2f pos) { _position = pos, _position1= pos; }
    void SetAcceleration(Vector2f acc) { _acceleration = acc, _acceleration1 = acc; }
    void SetVelocity(Vector2f vel) { _velocity = vel, _velocity1 = vel; }
   
    // Funciones para obtener las propiedades del objeto
    Vector2f GetPosition() { return _position, _position1; }
    Vector2f GetAcceleration() { return _acceleration, _acceleration1; }
    Vector2f GetVelocity() { return _velocity, _velocity1; }
  
    
    
    // Función para agregar una aceleración al objeto
    void AddAcceleration(Vector2f acc) {
        _acceleration.x += acc.x;
        _acceleration.y += acc.y;
        _acceleration1.x += acc.x;
        _acceleration1.y += acc.y;
    }

    // Constructor de la clase BaseObject que recibe el nombre del archivo de imagen como parámetro
    Bombas()
    {
        
        _pTex.loadFromFile("dinamita.png");
        Timpacto.loadFromFile("impacto.png");
        _pSpr.setTexture(_pTex);
        _pSpr.setScale(0.50f, 0.50f);
        _pSpr.setTexture(_pTex);
        _pSpr.setPosition(400.0f, 245.0f);
        _pSpr1.setTexture(_pTex);
        _pSpr1.setScale(0.50f, 0.50f);
        _pSpr1.setPosition(400.0f, 250.0f);
      
        // Inicialización de variables de posición, aceleración y velocidad
        _position.x = 400.0f; 
        _position.y = 245.0f;
        _position1.x = 400.0f;
        _position1.y = 250.0f;
        _acceleration.x = 0.0f;
        _acceleration.y = 0.0f;
        _acceleration1.x = 0.0f;
        _acceleration1.y = 0.0f;
        _velocity.x = 0.0f;
        _velocity.y = 0.0f;
        _velocity1.x = 0.0f;
        _velocity1.y = 0.0f;
    }

    // Destructor de la clase BaseObject
    ~Bombas(){}
   

    // Función para dibujar el objeto en una ventana RenderWindow
    void Draw(RenderWindow *pWnd)
    {
        // Se dibuja el Sprite en la ventana especificada
       
            pWnd->draw(_pSpr);
            pWnd->draw(_pSpr1); 
            
    }

    // Función para actualizar el objeto en la ventana en funcion del tiempo
    void Update(float dt)
    {
        
        // Actualización de la velocidad en función de la aceleración y el tiempo
        _velocity.x += _acceleration.x * dt;
        _velocity.y += _acceleration.y * dt;
        _velocity1.x += _acceleration1.x * dt;
        _velocity1.y += _acceleration1.y * dt;
        // Actualización de la posición en función de la velocidad y el tiempo
        _position.x += _velocity.x * dt;
        _position.y += _velocity.y * dt;
        _position1.x += _velocity1.x * dt;
        _position1.y += _velocity1.y * dt;
      
        // Se actualiza la posición del Sprite con la nueva posición calculada
       
            _pSpr.setPosition(_position);
            _pSpr1.setPosition(_position1);
        
        // Reinicio de las aceleraciones a 0 después de la actualización
        _acceleration.x = -7.0f;
        _acceleration.y = 8.0f;
        _acceleration1.x = 11.5f;
        _acceleration1.y =7.0f;
    }

    bool CambioTextura(float x, float y, bool cambio) {
        _pSpr.setTexture(_pTex);
        _pSpr1.setTexture(_pTex);
        if (cambio == true)
        {

            _pSpr.setTexture(Timpacto);
            _pSpr1.setTexture(Timpacto);
        }

        else  _pSpr.setTexture(_pTex); _pSpr1.setTexture(_pTex);
        Timpacto.swap(_pTex);
   
        return cambio;
    }
    bool EstaEncima(float x, float y) {
        FloatRect bounds = _pSpr.getGlobalBounds();
        FloatRect boundi = _pSpr1.getGlobalBounds();
        return bounds.contains(x, y);
        return boundi.contains(x, y);
    }
};

