//Mike Blanchard
//Linked list stack
//Program 4
//csc1720/program/program4
//This part of the program converts a decimal to a binary number
 
#include <iostream>
#include "linkedStack.h"
   
using namespace std; 
 
int main()
{  
   //creates the stack otherStack
   linkedStackType<int> otherStack;
   
   //declare other variables
   int dec;
   int newDec;
   int i = 0;  

   //output to the user
   cout << "Decimal ---> Binary" << endl;
   cout << "====================" << endl;
   cout << "Enter a decimal: ";
   cin >> dec; 
 
 //master while loop
 while (i == 0){
   //if statement to validate input
   if (dec <= 0){
      cout << "Input a positive integer:" << endl;
      cin >> dec;
   }
   else{
   
   //while loop to push a 1 or 0 into the stack based on the remainder
   while (dec != 0){ 
      if (dec % 2 > 0){
         otherStack.push(1);
      } 
      else if (dec % 2 == 0){
         otherStack.push(0);
      }
      dec /= 2;
   }
  
   //loop to output the stack through pop and top
   cout << "Decimal converted to a binary Number: " << endl;
   while (otherStack.isEmptyStack() == false){ 
         cout << otherStack.top(); 
         otherStack.pop();
   }

   cout << endl;
   i = 1;
   }
 }  
   return 0;
}
