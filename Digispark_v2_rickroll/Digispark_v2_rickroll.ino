#include "DigiKeyboard.h"

void setup() {

  //pino do LED
  pinMode(1, OUTPUT); 

  //pisca pra mostrar que iniciou 
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(1000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(0); // Limpa teclas presas
  
  //Abre o Spotlight
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  //Chama o Navegador
  DigiKeyboard.print("Safari");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  // Espera o navegador abrir
  DigiKeyboard.delay(1000);
  
  //abrindo uma nova aba no navegador 
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  // Digita a URL do Rickroll
  DigiKeyboard.println("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  
  // Delay para dar tempo de carregar 
  DigiKeyboard.delay(4000);
  
  // Fullscreen
  DigiKeyboard.print("f");
  
  // Feedbackfinal com duas piscadas 
  for (int i = 0; i < 2; i++) {
      digitalWrite(1, HIGH);
      DigiKeyboard.delay(500);
      digitalWrite(1, LOW);
      DigiKeyboard.delay(500);
  }
}

void loop() {
  // Nada aqui
}