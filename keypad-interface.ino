#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4; // Jumlah baris pada Keypad
const byte COLS = 3; // Jumlah kolom pada Keypad

char keys[ROWS][COLS] = { // Menampung tombol-tombol Keypad ke dalam tipe data char
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'},
};

byte rowPins[ROWS] = {10, 9, 8, 7}; // Pin-pin yang terkoneksi dengan baris tombol pada Keypad
byte colPins[COLS] = {13, 12, 11}; // Pin-pin yang terkoneksi dengan kolom tombol pada Keypad

// Inisialisasi library dengan pin interface
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  lcd.begin(20, 4); // Mengatur jumlah baris dan kolom pada LCD
}

void loop() {
  char key = keypad.getKey(); // Mengambil karakter pada input keypad

  if(key) { // Jika salah satu tombol pada Keypad ditekan
    lcd.print(key); // Cetak karakter dari Keypad ke LCD
  }
}
