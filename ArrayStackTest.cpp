//Mike Blanchard
//Program 4
//csc1720/programs/program4
//This part of the program will convert a binary number to a decimal

#include <iostream>
#include "myStack.h"
  
using namespace std;

int main()
{
   //long int so binNum can be longer (tutor connor explained this to me)
   long int binNum;
   
   //declare rest of variables
   int digit;
   string junk;
   int i = 1;
   int weight = 0;
   int decimal = 0;
   int flag = 0;
   char ans;

   //creating the stack
   stackType<int> binaryStack(50);
   stackType<int> otherStack(50);     
   
  // while (i != 0){ ... for reference, I tried to use a master loop so you could keep entering conversions, i was unsuccessful (more code below)

      //display directions to the user
      cout << "Binary Number --> Decimal" << endl;
      cout << "=============================" << endl;
      cout << "Please enter a binary number: ";
      cin >> binNum;
      cout << endl;
  
      //second while loop to input numbers into the stack
      while (binNum != 0){
         digit = binNum % 10;
         binaryStack.push(digit); 
         binNum = binNum/10;

         //if and if else with bool flag to warn for faulty input
         if (digit !=0 && digit != 1){
            cout << "You entered a bad value! Remember, a binary number consists of ONLY 1s and 0s." << endl;
            cout << "The number must be positve and must contain more than only 0s. Please try again." << endl;
            //i = 1;
            binNum = 0;
            flag = 1;
         } 
      }
      
      //reverse the stack
      binaryStack.reverseStack(otherStack);

      //another while with math for the conversion 
      while (otherStack.isEmptyStack() == false){
         decimal += otherStack.top() * (int)pow(2.0, weight);
         weight ++;
         otherStack.pop();
      }
      
      //output (only when a good binary number is entered)      
      if (flag == 0){
         cout << "Decimal Conversion: " << decimal << endl;
      }

      /* more code so if the user typed in in y, you could convert another number
      //if and if else to see if user wants to go again, will loop again if types in Y, will stop if type in N
      cout << "Convert another? (Y/N)" << endl;
      cin >> ans;
      if (ans == 'y' || ans == 'Y'){
         i = 1;
         otherStack.pop();
      }
      else if (ans == 'n' || ans == 'N'){
         i = 0;
      }
   }*/
   
return 0;
}
