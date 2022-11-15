/*
Autor:  Michał Herbut
Grupa:  WT/N 11:15     (Wtorek nieparzysty godz 11:15)
Temat:  Program z laboratorium 3
Data:   14 listopada 2022 r.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define ROZMIAR 5

using namespace std;

void readArray(float array[]) {
  for (int i = 0; i < ROZMIAR; i++) {
    printf("Tab[%d] = ", i);
    scanf("%f", &array[i]);
  }
}

void printArray(float array[]) {
  printf("\nTab = [");
  for (int i = 0; i < ROZMIAR; i++)
    printf("  %2.1f", array[i]);
  printf("  ]\n\n");
}

void avgArray(float array[]) {
  int numNegative = 0, numPositive = 0;
  float sumNegative = 0, sumPositive = 0, avgNegative, avgPositive;

  for (int i = 0; i < ROZMIAR; i++) {
    if (array[i] > 0) {
      sumPositive += array[i];
      numPositive++;
    } else if (array[i] < 0) {
      sumNegative += array[i];
      numNegative++;
    }
  }
  avgNegative = sumNegative / numNegative;
  avgPositive = sumPositive / numPositive;

  if (numPositive > 0) {
    printf("W tablicy jest %d liczb dodatnich.\n", numPositive);
    printf("Suma liczb dodatnich = %f.\n", sumPositive);
    printf("Srednia liczb dodatnich = %f.\n\n", avgPositive);
  } else
    printf("W tablicy nie ma liczb dodatnich.\n\n");

  if (numNegative > 0) {
    printf("W tablicy jest %d liczb ujemnych.\n", numNegative);
    printf("Suma liczb ujemnych = %f.\n", sumNegative);
    printf("Srednia liczb ujemnych = %f.\n\n", avgNegative);
  } else
    printf("W tablicy nie ma liczb ujemnych.\n\n");
}

void infoArray(float array[]) {
  int asc = 0, desc = 0, constant = 0;

  for (int i = 0; i < ROZMIAR - 1; i++) {
    if (array[i] == array[i+1]) constant++;
    if (array[i] > array[i+1]) desc++;
    if (array[i] < array[i+1]) asc++;
  }
  if (asc == ROZMIAR - 1) printf("elementy tablicy sa uporzadkowane rosnaco\n");
  else if (desc == ROZMIAR - 1) printf("elementy tablicy sa uporzadkowane malejaco\n");
  else if (constant == ROZMIAR - 1) printf("elementy tablicy maja jednakowa wartosc\n");
  else if (desc && constant && !asc) printf("elementy tablicy sa uporzadkowane nierosnaco\n");
  else if (asc && constant && !desc) printf("elementy tablicy sa uporzadkowane niemalejaco\n");
  else if (asc && desc) printf("elementy tablicy sa nieuporzadkowane\n");
}

void task1(float array[]) {
  printf("\n--------------------------------\n\n");
  printf("Program drukuje wczytane elementy tablicy oraz liczbe, sume i srednia elementow ujemnych i dodatnich oraz ich uporzadkowanie.\n");

  readArray(array);
  printArray(array);
  avgArray(array);
  infoArray(array);
}

void randomArray(float array[]) {
  float min, max;
  printf("Podaj min: ");
  scanf("%f", &min);
  printf("Podaj max: ");
  scanf("%f", &max);
  srand(time(NULL));
  for (int i = 0; i < ROZMIAR; i++)
    array[i] = min + (max - min) * rand() / RAND_MAX ;
}

void task2(float array[]) {
  printf("\n--------------------------------\n\n");
  printf("Program drukuje z podanego przedzialu losowe elementy tablicy oraz liczbe, sume i srednia elementow dodatnich i ujemnych oraz ich uporzadkowanie.\n");

  randomArray(array);
  printArray(array);
  avgArray(array);
  infoArray(array);
}

void bubbleSort(float array[]) {
  for (int i = 0; i < ROZMIAR - 1; i++)
    for (int j = 0; j < ROZMIAR - i - 1; j++)
      if (array[j] > array[j+1]) {
        float temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
}

void task3(float array[]) {
  printf("\n--------------------------------\n\n");
  printf("Program drukuje z podanego przedzialu posortowane rosnaco, losowe elementy tablicy oraz liczbe, sume i srednia elementow dodatnich i ujemnych oraz ich uporzadkowanie.\n");

  randomArray(array);
  bubbleSort(array);
  printArray(array);
  avgArray(array);
  infoArray(array);
}

void printAlphabetArray(char alphabetArray[]) {
  for (int i = 0; i < 26; i++) {
    printf("litera %c %d ", 'A'+i, alphabetArray[i]);
    for (int j = 0; j < alphabetArray[i]; j++)
      printf("#");
    printf("\n");
  }
}

void task4() {
  char alphabetArray[26] = {}, letter;
  int letterCounter = -1;

  printf("\n--------------------------------\n\n");
  printf("Program drukuje ilosc poszczegolnych, wczytanych liter.\n");
  printf("Wpisuj litery, zakoncz naciskajac escape: ");
  do {
    letter=getch();
    printf("%c", letter);
    letterCounter++;
    if (letter >= 'A' && letter <= 'Z') alphabetArray[letter-'A']++;
    else if (letter >= 'a' && letter <= 'z') alphabetArray[letter-'a']++;
  } while (letter != 27);
  
  if (letterCounter > 0) {
    printf("\n\nWpisano ogolem %d znakow w tym:\n", letterCounter);
    printAlphabetArray(alphabetArray);  
  } else
    printf("\n\nNic nie wpisano!\n");
}

int main() {
  float array[ROZMIAR];
  int programNumber;
  do {
    printf("---------------------------------\n\n");
    printf("Autor: Michal Herbut (WT/N 11:15) \n\n");
    printf("1 | operacje na tablicy\n");
    printf("2 | operacje na losowej tablicy\n");
    printf("3 | sortowanie\n");
    printf("4 | licznik liter\n\n");
    printf("0 | zamknij program\n\n");
    printf("Jaki program? ");

		scanf("%d", &programNumber);
		switch(programNumber){
      case 1:
        task1(array); break;
      case 2:
        task2(array); break;
      case 3:
        task3(array); break;
      case 4:
        task4(); break;
      case 0:
        break;
      default:
        printf("\n--------------------------------\n");
        printf("\nPODAJ NUMER OD 0 Do 4!!!\n\n");
        break;
		}
	} while(programNumber);
  return 0;
}