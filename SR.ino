// Kode program Smart Home Speech Recognition

// Deklarasi Variabel
String voice;
int disko = 0;
const int led1 = 6;
const int led2 = 5;
const int led3 = 4;
const int led4 = 3;
const int led5 = 2;

void setup() {
  // Inisialisasi Serial
  Serial.begin(9600);
  // Inisialisasi Pin LED
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

// Prosedur Semua Lampu di Rumah Menyala
void semuamenyala() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
}

// Prosedur Semua Lampu di Rumah Mati
void semuamati() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}

// Prosedur untuk Rumah Disko

void loop() {
  // Pengecekan Teks
  while (Serial.available()) {
    delay(10);
    char inChar = Serial.read();
    if (inChar == '#') {break;}
    voice += inChar;
  }
  Serial.println(voice);
  delay(500);
  // Kendali Lampu
  if (voice == "*Nyalakan rumah") {
    semuamenyala();
  }
  else if(voice == "*matikan rumah") {
    semuamati();
    disko = 0;
  }
  else if(voice == "*ruang satu nyala" || voice == "*ruang 1 nyala") {
    digitalWrite(led1, HIGH);
  }
  else if(voice == "*ruang dua nyala" || voice == "*ruang 2 nyala") {
    digitalWrite(led2, HIGH);
  }
  else if(voice == "*ruang tiga nyala" || voice == "*ruang 3 nyala") {
    digitalWrite(led3, HIGH);
  }
  else if(voice == "*ruang empat nyala" || voice == "*ruang 4 nyala") {
    digitalWrite(led4, HIGH);
  }
  else if(voice == "*ruang lima nyala" || voice == "*ruang 5 nyala") {
    digitalWrite(led5, HIGH);
  }
  else if(voice == "*ruang satu mati" || voice == "*ruang 1 mati") {
    digitalWrite(led1, LOW);
  }
  else if(voice == "*ruang dua mati" || voice == "*ruang 2 mati") {
    digitalWrite(led2, LOW);
  }
  else if(voice == "*ruang tiga mati" || voice == "*ruang 3 mati") {
    digitalWrite(led3, LOW);
  }
  else if(voice == "*ruang empat mati" || voice == "*ruang 4 mati") {
    digitalWrite(led4, LOW);
  }
  else if(voice == "*ruang lima mati" || voice == "*ruang 5 mati") {
    digitalWrite(led5, LOW);
  }
  else if(voice == "*mode disko") {
    disko = 1;
  }
  if(disko==1){
    int acak = random(2, 6);
    digitalWrite(acak, HIGH);
    delay(100);
    digitalWrite(acak, LOW);  
  }
  voice ="";
}
