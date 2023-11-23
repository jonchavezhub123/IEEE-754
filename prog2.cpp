#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cmath>
using namespace std;
//Function Declaration
void printBinFloat(uint32_t x);


int main()
{
        uint32_t x; // Will grab the input from the input file.

        while(cin >> hex >> x) // Read your input from stdin
        {
           printBinFloat(x);
        }
}

//**************************************************************************
// print a detailed description of the floating point value that they
// represent by extracting and showing the sign, exponent, and
// significand from the 32-bit value
//
// uses the C bitwise operators to interpret, extract, and shift the fields of the IEEE number
// First I shifted each bit in the hexadecimal and outputted 1 or zero if the bit matched the one
// in the right_shift variable. Then I shifted it and kept on doing this until I finished the loop.
// Did this to print the binary value.
// Sign was pretty easy tbh all I had to was shift it 31 bits in order to grab the most significant bit
// Did something similar with extracting the exponent and if the bit equaled one I squared it based off my current
// count. My extraction of Sig pretty much takes the sum of the last 23 bits. The an cascading if and else if
// follows in order to print the floating the point number
//
// @param x Hexadecimal file grabbed from the input.
//
// @return nothing
//****************************************************************************

void printBinFloat(uint32_t x)
{
//Prints hexadecimal value
    uint32_t right_shift = 0x80000000;
    cout << "0x";
    cout << hex << setw(8) << setfill('0') << x << " = ";
// Prints binary value
       for(int i = 1; i <= 32; i++)
        {
             cout << (x & right_shift ? '1' : '0');
             right_shift = right_shift >> 1;
             if(i % 4 == 0 && i != 0 && i != 32)
                cout << " ";
        }
  cout << endl;
  int sign ((x >> 31) & 1); // Most significant is the sign bit;

 //Prints sign
  if(sign == 1)
  {
    cout << "sign: " << sign;
  }

  else
  {
    cout << "sign: " << sign;
  }

  cout << endl;
  int count = 0;
  int exp = 0;
 //There are 8 exp bits that' why I started at 23 and end my loop 31
  for(int i = 23; i < 31; i++)
  {
     int bit ((x >> i) & 1);
     if(bit)
     {
         exp += pow(2, count);
     }
     ++count;
  }
  // The rules for IEEE dictate that we subtract by 127
   exp -= 127;
 //Prints exponent
  cout << " exp: ";
  cout << "0x";
  cout << hex << setw(8) << setfill('0') << exp << " ";
  cout << dec << "(" << exp << ")" << endl;

  int sum_2 = 0;
  // Grabs sig. Which pretty much is the sum of the last 23 bits
  for(int i = 0; i < 23; i++)
  {
    int bit ((x >> i) & 1);
     if(bit)
     {
         sum_2 += pow(2, i);
     }
  }
//Prints Sig
  cout << " sig: 0x" << hex << setw(8) << setfill('0') << sum_2 << endl;
// Checks the sign
  if(sign == 0)
  {
   cout << "+";
  }
  else
  {
   cout << "-";
  }
// Checks if its infinity
  if(exp == 128 && sum_2 == 0)
  {
    cout << "inf";
  }
  else if(exp == 128 && sum_2 == 0 )
  {
   cout << "inf";
  }
 // Checks the condition when it's zero
 else if(exp == -127 && sum_2 == 0 )
 {
  cout << "0";
 }

  else if(exp == -127 && sum_2 == 0)
  {
  cout << "0";
  }
// If exp is zero I automatically print 1. Since there is no need to add zeros before the decimal
  else if(exp == 0)
  {
    cout << "1.";

   uint32_t right_shift = 0x00400000;

   for(int i = 1; i <= 23; i++)
   {
        cout << (x & right_shift ? '1' : '0');
        right_shift = right_shift >> 1;
   }
}
// Adds zeros past the decimal points if negative depending on the exponent value.
  else if(exp < 0)
 {
    int max = -1 * exp;

    cout << "0.";

  for(int i = 1; i < max; i++)
  {
    cout << "0";
  }
    cout << "1";

  uint32_t right_shift = 0x00400000;

   for(int i = 1; i <= 23; i++)
   {
        cout << (x & right_shift ? '1' : '0');
        right_shift = right_shift >> 1;
   }
}
// If exponent is positive we add zeros past the one
  else if (exp > 0)
  {
    cout << "1";

    if(exp > 23)
   {
      uint32_t right_shift = 0x00400000;

   for(int i = 1; i <= 23; i++)
   {
        cout << (x & right_shift ? '1' : '0');
        right_shift = right_shift >> 1;
   }

     uint32_t max = exp-23;

     for(unsigned int i = 1; i <= max; i++)
     {
       cout << "0";
     }
   }
// My other condition to consider another condition that wasn't included in the assignment prompt but I added just in case
 else
  {
    uint32_t right_shift = 0x00400000;
   for(int i = 1; i <= exp; i++)
   {
        cout << (x & right_shift ? '1' : '0');
        right_shift = right_shift >> 1;
   }
  }
  cout << ".0";
}
cout << endl;
}
