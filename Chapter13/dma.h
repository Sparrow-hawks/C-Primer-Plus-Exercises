#ifndef _DMA_H
#define _DMA_H

#include <iostream>

class DMA {
private:
  char *label;
  int rating;
protected:
  char* getLabel() const ;
  int getRating() const;

public:
  DMA(const char *l = "None", int r = 0);
  DMA(const DMA& dma);
  //DMA();
  virtual ~DMA();

  virtual void View() = 0;

  DMA& operator=(const DMA& dma);
  friend std::ostream& operator<<(std::ostream& os, const DMA& dma);
};

class baseDMA : public DMA {
private:

public:
  baseDMA(const char* l = "None", int r = 0);
  baseDMA(const baseDMA& bdma);

  virtual ~baseDMA();
  virtual void View();

  baseDMA& operator=(const baseDMA& bdma);

  friend std::ostream& operator<<(std::ostream& os, const baseDMA& bdma);
};

class lacksDMA : public DMA {
private:
  enum {COL_LEN = 40};
  char color[COL_LEN];

public:
  lacksDMA(const char *c = "None", const char *l = "None", int r = 0);
  lacksDMA(const char *c, const DMA& dma);
  lacksDMA(const lacksDMA& ldma);
  virtual ~lacksDMA();

  virtual void View();

  lacksDMA& operator=(const lacksDMA& ldma);
  friend std::ostream& operator<<(std::ostream& os, const lacksDMA& ldma);
};

class hasDMA : public DMA {
private:
  char *style;

public:
  hasDMA(const char* s = "None", const char * l = "None", int r = 0);
  hasDMA(const char *s, const DMA& dma);
  hasDMA(const hasDMA& hdma);

  ~hasDMA();

  virtual void View();

  hasDMA& operator=(const hasDMA& hdma);

  friend std::ostream& operator<<(std::ostream& os, const hasDMA& hdma);
};

#endif
