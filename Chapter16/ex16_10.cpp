// Book:      C++ Primer Plus
// Chapter:   16
// Exercise:  10

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

struct Review {
  std::string title;
  int rating;
  double price;
};

typedef std::shared_ptr<Review> ptrReview;

bool operator<(const ptrReview r1, const ptrReview r2);
bool worseThan(const ptrReview r1, const ptrReview r2);
bool priceThan(const ptrReview r1, const ptrReview r2);

bool FillReview(Review& rr);
void ShowReview(const std::shared_ptr<Review>& rr);
void ShowMenu();

int main() {
  using namespace std;

  vector<shared_ptr<Review>> books;
  Review temp;
  while (FillReview(temp)) {
    shared_ptr<Review> pTemp(new Review {temp});
    books.push_back(pTemp);
  }

  if (books.size() > 0) {
    vector<ptrReview> bookCopy (books);

    ShowMenu();
    int choose;
    while (cin >> choose && choose != 7) {
      switch(choose) {
        case 1:
          cout << "Ocena\tKsiążka\tCena\n";
          for_each(books.begin(), books.end(), ShowReview);
          break;
        case 2:
          cout << "Posortowane wg tytułu:\nOcena\tKsiążka\tCena\n";
          sort(bookCopy.begin(), bookCopy.end());
          for_each(bookCopy.begin(), bookCopy.end(), ShowReview);
          break;
        case 3:
          cout << "Posortowane wg oceny rosnoąco:\nOcena\tKsiążka\tCena\n";
          sort(bookCopy.begin(), bookCopy.end(), worseThan);
          for_each(bookCopy.begin(), bookCopy.end(), ShowReview);
          break;
        case 4:
          cout << "Posortowane wg oceny malejąco:\nOcena\tKsiążka\tCena\n";
          sort(bookCopy.rbegin(), bookCopy.rend(), worseThan);
          for_each(bookCopy.begin(), bookCopy.end(), ShowReview);
          break;
        case 5:
          cout << "Posortowane wg ceny rosnąco:\nOcena\tKsiążka\tCena\n";
          sort(bookCopy.begin(), bookCopy.end(), priceThan);
          for_each(bookCopy.begin(), bookCopy.end(), ShowReview);
          break;
        case 6:
          cout << "Posortowane wg ceny rosnąco:\nOcena\tKsiążka\tCena\n";
          sort(bookCopy.rbegin(), bookCopy.rend(), priceThan);
          for_each(bookCopy.begin(), bookCopy.end(), ShowReview);
          break;
        default:
          cout << "Nie ma takiej opcji!" << std::endl;
          break;
      }
      ShowMenu();
    }
  } else {
    cout << "Brak danych" << endl;
  }
  cout << "*** Koniec ***" << endl;

  return 0;
}

bool operator<(const ptrReview r1, const ptrReview r2) {
  return r1->title < r2->title;
}

bool worseThan(const ptrReview r1, const ptrReview r2) {
  return r1->rating < r2->rating;
}

bool priceThan(const ptrReview r1, const ptrReview r2) {
  return r1->price < r2->price;
}

bool FillReview(Review& rr) {
  std::cout << "Wpisz tytuł książki (koniec, aby zakończyć): ";
  std::getline(std::cin, rr.title);
  if (rr.title == "koniec")
    return false;
  std::cout << "Wpisz ocenę: ";
  std::cin >> rr.rating;
  if (!std::cin)
    return false;
  while (std::cin.get() != '\n')
    continue;
  std::cout << "Wpisz cenę: ";
  std::cin >> rr.price;
  if (!std::cin)
    return false;
  while (std::cin.get() != '\n')
    continue;

  return true;
}

void ShowReview(const std::shared_ptr<Review>& rr) {
  std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}

void ShowMenu() {
  std::cout << "*** MENU ***" << std::endl;
  std::cout << "1) Wg wprowadzania  2) Tytuł alfabetycznie\n"
            << "3) Ocena rosnąco    4) Ocena malejąco\n"
            << "5) Cena rosnoco     6) Cena malejąco\n"
            << "7) Wyjście\n";
}
