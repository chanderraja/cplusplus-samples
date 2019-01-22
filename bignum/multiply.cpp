
/** @file multiply.cpp
 *  @brief Function to multiply two numeric strings 
 *
 *  This contains a function to multiply numeric strings. The product of the
 *  two numbers is also returned as a string.
 *
 *  @author Chander Raja (chanderraja)
 *  @author Fred Hacker (fhacker)
 *  @bug No known bugs.
 */


#include <string>
#include <cstring>  // for memset
#include <cctype>   // for isdigit

using namespace std;

/** @brief function to multiply numeric strings. The product of the
 *         two numbers is also returned as a string.
 *  @param num1 First operand string
 *         num2 Second operand string
 *  @return string containing the product of the two input numeric strings
 */
string multiply(string num1, string num2) {
   
  // the product string cannot be longer than the
  // sum of the sizes of the operand strings
  size_t n = num1.size() + num2.size();

  // allocate a char array from the stack
  char r[n+1];
  
  // clear the char array
  memset(r, 0, n+1);
  
  // Perform long multiplication
  for (int i = num1.size() - 1; i >= 0; i--) {
    for (int j = num2.size() - 1; j >= 0; j--) {
        if (!isdigit(num1[i]) || !isdigit(num2[j])) {
          return "0";
        }
        
        unsigned char op1 = num1[i] - '0';
        unsigned char op2 = num2[j] - '0';
        
        int prod = op1 * op2;
        
        int index = i+j+1;

        r[index] += prod;
        r[index-1] += r[index]/10; // carry over
        r[index] %= 10;

    }
  }

  // strip leading 0s from result
  char *p = r;
  while (*p == 0) {
      ++p;
      --n;
  }

  // 'stringify' the result
  for (int i = 0; i < n; ++i) {
      p[i]+= '0';
  }

  return p; 
}

