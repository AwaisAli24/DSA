#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second

  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();
}

void loop() {
  int choice = getChoice();

  // Seed the random number generator with the current time
  randomSeed(analogRead(0));

  // Variable declarations for nutrient ranges
  int n_min, n_max, k_min, k_max, p_min, p_max;
  bool validChoice = true;

  // Determine nutrient ranges and crop types based on user choice
  switch (choice) {
    case 1:
      n_min = 60;
      n_max = 130;
      k_min = 100;
      k_max = 130;
      p_min = 30;
      p_max = 50;
      break;
    case 2:
      n_min = 1;
      n_max = 60;
      k_min = 1;
      k_max = 100;
      p_min = 1;
      p_max = 30;
      break;
    case 3:
      n_min = 130;
      n_max = 170;
      k_min = 130;
      k_max = 180;
      p_min = 50;
      p_max = 90;
      break;
    default:
      validChoice = false;
      break;
  }

  // Generate random nutrient values
  int nitrogen, phosphorus, potassium;
  if (validChoice) {
    nitrogen = random(n_min, n_max + 1);
    phosphorus = random(p_min, p_max + 1);
    potassium = random(k_min, k_max + 1);
  } else {
    nitrogen = random(0, 200); // Random value without range
    phosphorus = random(0, 100); // Random value without range
    potassium = random(0, 200); // Random value without range
  }

  // Generate random moisture value
  float moisture = random(3500, 5001) / 100.0;

  // Output the nutrient values to Serial Monitor
  Serial.print("N: ");
  Serial.println(nitrogen);
  Serial.print("P: ");
  Serial.println(phosphorus);
  Serial.print("K: ");
  Serial.println(potassium);
  Serial.print("pH: 7.12");
  Serial.print("\nMoisture: ");
  Serial.print(moisture);
  Serial.println("%");

  // Output the nutrient values to OLED display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("N: ");
  display.println(nitrogen);
  display.print("P: ");
  display.println(phosphorus);
  display.print("K: ");
  display.println(potassium);
  display.print("pH: 7.12");
  display.print("\nMoisture: ");
  display.print(moisture);
  display.println("%");
  display.println("Crops:");

  // Output the crops based on user choice to Serial Monitor and OLED display
  if (validChoice) {
    switch (choice) {
      case 1:
        Serial.println("Tomatoes\nCucumber\nWheat\nCorn");
        display.println("Tomatoes");
        display.println("Cucumber");
        display.println("Wheat");
        display.println("Corn");
        break;
      case 2:
        Serial.println("Radishes\nTurnips\nBuckwheat\nMillet");
        display.println("Radishes");
        display.println("Turnips");
        display.println("Buckwheat");
        display.println("Millet");
        break;
      case 3:
        Serial.println("Broccoli\nCabbage\nRice\nSoybeans");
        display.println("Broccoli");
        display.println("Cabbage");
        display.println("Rice");
        display.println("Soybeans");
        break;
    }
  } else {
    Serial.println("Random Crops:");
    display.println("Random Crops:");
    display.println("Crop 1");
    display.println("Crop 2");
    display.println("Crop 3");
    display.println("Crop 4");
  }

  display.display();
  delay(10000); // Wait for 10 seconds before restarting the loop
}

int getChoice() {
  unsigned long startTime = millis();
  bool messageShown = false;

  while (true) {
    if (Serial.available() > 0) {
      int choice = Serial.parseInt();
      return choice;
    }
    if (millis() - startTime > 10000 && !messageShown) { // 10 seconds timeout
      Serial.println("No input detected. Generating random output...");
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("No input detected.");
      display.println("Generating random output...");
      display.display();
      messageShown = true;
      delay(2000); // Wait for 2 seconds before returning
      return -1; // Indicate no valid input to generate random output
    }
  }
}
