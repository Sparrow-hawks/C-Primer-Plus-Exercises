// Book:      C++ Primer Plus
// Chapter:   7
// Exercise:  3

#include <iostream>

struct Box {
  char maker[40];
  float height;
  float width;
  float length;
  float volume;
};

void show(Box box);
void calculateVolume(Box *box);

int main(void) {

  Box box {"Lontex", 10, 20, 30};

  show(box);

  calculateVolume(&box);

  show(box);

  return 0;
}

void show(Box box) {
  std::cout << "Pudełko: " << std::endl;
  std::cout << "Producent: " << box.maker << std::endl;
  std::cout << "Wysokość:  " << box.height << " cm" << std::endl;
  std::cout << "Szerokość: " << box.width << " cm" << std::endl;
  std::cout << "Długość:   " << box.length << " cm" << std::endl;
  std::cout << "Pojemność: " << box.volume << " cm^3" << std::endl;
}

void calculateVolume(Box *box) {
  box->volume = box->height * box->width * box->length;
}
