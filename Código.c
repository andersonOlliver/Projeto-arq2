int ligado = 1;
int desligado = 0;
int frente = 3;
int atras = 6;
int direita = 11;
int esquerda = 10;
char opcao = 'p';
int valorAceleracao = 0;
int valorRotacao = 120;

void p_atras(){
 digitalWrite(frente, ligado);
 analogWrite(atras, valorAceleracao);
 //digitalWrite(atras, desligado);
}

void p_frente(){
  digitalWrite(atras, ligado);
  analogWrite(frente,valorAceleracao);
  //digitalWrite(frente, desligado);
}

void p_direita(){
  digitalWrite(esquerda, ligado);
  analogWrite(direita, valorRotacao);
  //digitalWrite(direita, desligado);
}

void p_esquerda(){
  digitalWrite(direita, ligado);
  analogWrite(esquerda, valorRotacao);
  //digitalWrite(esquerda, desligado);
}

void direita_frente(){
  p_direita();
  p_frente();
}

void esquerda_frente(){
  p_esquerda();
  p_frente();
}

void esquerda_atras(){
  p_esquerda();
  p_atras();
}

void direita_atras(){
  p_direita();
  p_atras();
}

void p_parar(){
  digitalWrite(frente, ligado);
  digitalWrite(atras, ligado);
  digitalWrite(direita, ligado);
  digitalWrite(esquerda, ligado);
}

void setup() {
  Serial.begin(9600);
  pinMode(frente, OUTPUT);
  pinMode(atras, OUTPUT);
  pinMode(direita, OUTPUT);
  pinMode(esquerda, OUTPUT);  
}

void loop() {
   if (Serial.available()){
      opcao = Serial.read();
      Serial.println(opcao);
    
      switch(opcao){
        case 'F':
          p_frente();
          break;
          
        case 'B':
          p_atras();
          break;
          
        case 'L':
          p_esquerda();
          break;
          
        case 'R':
          p_direita();
          break;
          
        case 'G':
          esquerda_frente();
          break;
          
        case 'I':
          direita_frente();
          break;
          
        case 'J':
          direita_atras();
          break;
          
        case 'H':
          esquerda_atras();
          break;
          
        default :
          p_parar();
        break;
      }
  }
}
