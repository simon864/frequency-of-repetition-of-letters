/*************************************
 * Автор: Богулянов Семен            *       
 * Дата: 26.12.2022                  *
 * Название: Частота повторения букв *
 *   и двухбуквенных сочетаний       *
 *************************************/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
  int lettersIndex = 0, letterRepeat = 1, letterRepeatArray[75],
  countTwoLetterComb = 0;
  
  char fileLine[100], fileLetters[75];
  
  FILE* file = fopen("english.txt", "r");
  
  if (file == NULL) {
    return 0;
  }
  
  while (!feof(file)) {
    fscanf(file, "%s", fileLine);
    
    for (int indexLetter = 0; indexLetter < strlen(fileLine); ++indexLetter) {
      if ((fileLine[indexLetter] >= 65 && fileLine[indexLetter] <= 90)
       || (fileLine[indexLetter] >= 97 && fileLine[indexLetter] <= 122)) {
        bool flag = 0;
        int indexLetterRepeated;
        
        if (indexLetter != strlen(fileLine) &&
           (fileLine[indexLetter] == fileLine[indexLetter + 1] || 
        abs(fileLine[indexLetter] -  fileLine[indexLetter + 1]) == 32)) {
          ++countTwoLetterComb;
        }
        
        for (int index = 0; index < lettersIndex; ++index) {
          if (fileLetters[index] == fileLetters[indexLetter] || 
          abs(fileLetters[index] -  fileLine[indexLetter]) == 32) {
            flag = 1;
            indexLetterRepeated = index;
          }
        }
        
        if (flag == 0) {
          if (!(fileLine[indexLetter] >= 65 && fileLine[indexLetter] <= 90)) {
            fileLine[indexLetter] -= 32;
          }
          
          fileLetters[lettersIndex] = fileLine[indexLetter];
          letterRepeatArray[lettersIndex] = letterRepeat;
          
          ++lettersIndex;
        } else {
          letterRepeatArray[indexLetterRepeated] += letterRepeat; 
        }
      }
    }
  }
  
  for (int indexOut = 0; indexOut < lettersIndex; ++indexOut) {
    cout << fileLetters[indexOut] << " — " << letterRepeatArray[indexOut] 
         << endl;
  }
  cout << endl;
  
  cout << "Кол-во двухбуквенный сочетаний " << countTwoLetterComb << endl;
}
