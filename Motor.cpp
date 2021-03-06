/*
  Motor.cpp - Librería para el uso de los motores
  Creado por Álvaro Palmero, 11 marzo 2018
 */

#include "Motor.h"

motor::motor(){
  pin_ad = 0;
  pin_at = 0;
  pin_pwm = 0;
  posicion = 0;
  avance = 0;
  velocidad = 0;
}

void motor::setTipo(bool a){
  tipo = a;
}

void motor::setPines(int a, int b, int c){
  pinMode (a, OUTPUT);
  pinMode (b, OUTPUT);
  pinMode (c, OUTPUT);
  pin_ad = a;
  pin_at = b;
  pin_pwm = c;
}

void motor::setAvance(float a){
  avance = a;
}

float motor::getFeedback(){
  if(!tipo){
    posicion = encod.getVueltas()*avance + (encod.getMemoria()-(encod.getVueltas()*32))*avance/32;
    return posicion;
  }
  else if(tipo){
    angulo = pot.getAngulo();
  }
}

void motor::setVelocidad(int a){
  velocidad = a;
  analogWrite(pin_pwm, velocidad);
}

void motor::avanzar(bool i){
  if (i){
    digitalWrite(pin_at, LOW);
    digitalWrite(pin_ad, HIGH);
  }
  else if(!i){
    digitalWrite(pin_at, HIGH);
    digitalWrite(pin_ad, LOW);
  }
}

void motor::imprimirFeedback(){
  if(!tipo){
    Serial.println(posicion);
  }
  else if(tipo){
    Serial.println(angulo);
  }
}

void motor::imprimirVel(){
  Serial.println(velocidad);
}

void motor::imprimirAv(){
  Serial.println(avance);
}

bool motor::getTipo(){
  return tipo;
}

