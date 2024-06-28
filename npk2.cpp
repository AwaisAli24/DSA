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
      Serial.println("Invalid choice. Please enter 1, 2, or 3.");
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("Invalid choice.");
      display.println("Please enter 1, 2, or 3.");
      display.display();
      delay(5000); // Wait for 5 seconds before restarting the loop
      display.clearDisplay();
      return;
  }

  // Generate random nutrient values within the specified ranges
  int nitrogen = random(n_min, n_max + 1);
  int phosphorus = random(p_min, p_max + 1);
  int potassium = random(k_min, k_max + 1);

  // Output the nutrient values to Serial Monitor
  Serial.print("N: ");
  Serial.println(nitrogen);
  Serial.print("P: ");
  Serial.println(phosphorus);
  Serial.print("K: ");
  Serial.println(potassium);

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
  display.println("Crops:");

  // Output the crops based on user choice to Serial Monitor and OLED display
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

  display.display();
  delay(10000); // Wait for 10 seconds before restarting the loop
}

int getChoice() {
  unsigned long startTime = millis();
  bool messageShown = false;

  while (true) {
    if (Serial.available() > 0) {
      int choice = Serial.parseInt();
      if (choice >= 1 && choice <= 3) {
        return choice;
      } else {
        if (!messageShown) {
          Serial.println("Invalid choice. Please enter 1, 2, or 3:");
          display.clearDisplay();
          display.setTextSize(1);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(0, 0);
          // display.println("Invalid choice.");
          // display.println("Please enter 1, 2, or 3.");
          display.display();
          messageShown = true;
        }
      }
    }
    if (millis() - startTime > 10000) { // 10 seconds timeout
      if (!messageShown) {
        Serial.println("No input detected. Please enter 1, 2, or 3:");
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 0);
        display.println("No input detected.");
        display.println("Please enter 1, 2, or 3.");
        display.display();
        messageShown = true;
      }
    }
  }
}
