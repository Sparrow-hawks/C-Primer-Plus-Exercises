#include <iostream>
#include <cstring>
#include "dma.h"

DMA::DMA(const char *l, int r) : rating (r) {
  label = new char[strlen(l) + 1];

  strcpy(label, l);
}

// DMA::DMA() : rating(0) {
//   label = new char[1];
//   label[0] = '\0';
// }

DMA::~DMA() {
  delete [] label;
}

DMA::DMA(const DMA& dma) {
  label = new char[strlen(dma.label) + 1];
  strcpy(label, dma.label);
  rating = dma.rating;
}

DMA& DMA::operator=(const DMA& dma) {
  if (&dma != this) {
    delete [] label;
    label = new char [strlen(dma.label) + 1];
    strcpy(label, dma.label);
    rating = dma.rating;
  }
  return *this;
}

int DMA::getRating() const {
  return rating;
}

char* DMA::getLabel() const {
  return label;
}

std::ostream& operator<<(std::ostream& os, const DMA& dma) {
  os << "Label: " << dma.label << ", rating: " << dma.rating << ".";

  return os;
}



baseDMA::baseDMA(const char *l, int r) : DMA(l, r) {

}

baseDMA::baseDMA(const baseDMA& bdma) : DMA(bdma) {

}

baseDMA::~baseDMA() {

}

baseDMA& baseDMA::operator=(const baseDMA& bdma) {
  if (&bdma != this) {
    DMA::operator=(bdma);
  }
  return *this;
}

void baseDMA::View() {
  std::cout << "baseDMA object: " << std::endl;
  std::cout << "Label: " << DMA::getLabel() << ", rating: " << DMA::getRating() << "." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& dma) {
  os << "Label: " << dma.getLabel() << ", rating: " << dma.getRating() << ".";

  return os;
}



lacksDMA::lacksDMA(const char *c, const char *l, int r) : DMA(l, r) {
  strncpy(color, c, COL_LEN - 1);
  color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char *c, const DMA& dma) : DMA (dma) {
  strncpy(color, c, COL_LEN - 1);
  color[COL_LEN - 1] = '\0';
}

lacksDMA::~lacksDMA() {

}

lacksDMA::lacksDMA(const lacksDMA& ldma) : DMA(ldma) {
  strcpy(color, ldma.color);
}

lacksDMA& lacksDMA::operator=(const lacksDMA& ldma) {
  if (&ldma != this) {
    strcpy(color, ldma.color);
    DMA::operator=(ldma);
  }
  return *this;
}

void lacksDMA::View() {
  std::cout << "lacksDMA object: " << std::endl;
  std::cout << "Label: " << DMA::getLabel() << ", rating: " << DMA::getRating() << ", color: "
   << color << "." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ldma) {
  os << "Label: " << ldma.getLabel() << ", rating: " << ldma.getRating() << ", color: "
    << ldma.color << "." << std::endl;

  return os;
}



hasDMA::hasDMA(const char *s, const char *l, int r) : DMA(l, r) {
  style = new char[strlen(s) + 1];
  strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const DMA& dma) : DMA(dma) {
  style = new char[strlen(s) + 1];
  strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hdma) : DMA(hdma) {
  style = new char[strlen(hdma.style) + 1];
  strcpy(style, hdma.style);
}

hasDMA::~hasDMA() {
  delete [] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hdma) {
  if (&hdma != this) {
    delete [] style;
    style = new char[strlen(hdma.style) + 1];
    strcpy(style, hdma.style);
    DMA::operator=(hdma);
  }
  return *this;
}

void hasDMA::View() {
  std::cout << "hasDMA object: " << std::endl;
  std::cout << "Label: " << DMA::getLabel() << ", rating: " << DMA::getRating() << ", style: "
   << style << "." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hdma) {
  os << "Label: " << hdma.getLabel() << ", rating: " << hdma.getRating() << ", style: "
    << hdma.style << "." << std::endl;

  return os;
}
