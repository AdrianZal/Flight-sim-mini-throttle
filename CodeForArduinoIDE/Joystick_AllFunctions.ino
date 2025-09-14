#include <Joystick.h>

const int SLIDER_PIN = 26;

const int NUM_BUTTONS = 12;
const int BUTTON_PINS[NUM_BUTTONS] = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};

const int sampleSize = 10;
int samples[sampleSize];
int sliderIndex = 0;

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  }

  pinMode(SLIDER_PIN, INPUT);
  analogReadResolution(10);
  Joystick.begin();
  Joystick.use10bit();

  for (int i = 0; i < sampleSize; i++) {
    samples[i] = analogRead(SLIDER_PIN);
  }
}

int getFilteredSlider() {
  samples[sliderIndex] = analogRead(SLIDER_PIN);
  sliderIndex = (sliderIndex + 1) % sampleSize;

  long sum = 0;
  for (int i = 0; i < sampleSize; i++) {
    sum += samples[i];
  }
  return sum / sampleSize;
}

void loop() {
  
  for (int i = 0; i < NUM_BUTTONS; i++) {
    Joystick.button(i + 1, digitalRead(BUTTON_PINS[i]) == LOW);
  }

  int val = getFilteredSlider();
  Joystick.sliderLeft(val);

}
