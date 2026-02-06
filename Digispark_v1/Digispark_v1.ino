#include "DigiKeyboard.h"

void setup() {

  //acha o pino
  pinMode(1, OUTPUT); 

  //acende o led para mostrar que ta rodando
      digitalWrite(1, HIGH);
      DigiKeyboard.delay(1000);
      digitalWrite(1, LOW);
      DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(0);
  
  // 1. Abre o Spotlight
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  // 2. Chama o Editor
  DigiKeyboard.print("Editor de Texto");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  // Espera a janela de "Seleção de Arquivos" abrir
  DigiKeyboard.delay(2000);
  
  // Envia Command + N para criar um "Novo Documento" imediatamente
  DigiKeyboard.sendKeyStroke(KEY_N, MOD_GUI_LEFT);
  
  // Espera a folha em branco aparecer
  DigiKeyboard.delay(1000);
  
  // 3. Agora sim, escreve
  DigiKeyboard.print("Hacking is primarily about logic, not force.");
  // A variavel 'i' é o contador
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