//#include <iostream>
//#include "RandomNumberSet.h"
//
//using namespace std;
//#define M 32
//
//int main() {
////    //default constructor initializes with all bits 0
////    bitset<39> bset1;
////
////    //bset2 is initialized with bits of 20
////    bitset<39> bset2 (20);
////
////    //bset3 is initialized with bits of specified binary string
////    bitset<39> bset3(string("1100"));
////
////    //cout prints the exact bits representation of bitset
////    cout << bset1 << endl; // 00000000000000000000000000000000
////    cout << bset2 << endl; // 00000000000000000000000000010100
////    cout << bset3 << endl; // 00000000000000000000000000001100
////    cout << bset2[3]<<endl;
////    cout << endl;
////
////    bitset<8> set8;
////
////    set8[1] = 1;
////    set8[4] = set8[1];
////    cout << "Set8 is" <<set8 <<endl;
////    //count function returns number of bits set in bitset
////    int numberOf1 = set8.count();
////
////            //size function returns total number of bits in bitset. So their difference will give us the number of unset(0) bits in bitset
////    int numberOf0 = set8.size() - numberOf1;
////
////    if(!set8.any())
////        cout << set8.operator<<()
////        cout << "\nSet8 has no bit set";
////
////    if(!bset1.any())
////        cout << "\nBset1 has no bit set";
////
////    //none function returns true if no bit is set
////    if(bset1.none())
////        cout<< "\nBset1 has no bit set";
////
////    //reset function makes all bits 0
////    cout << set8.reset(2) << endl;
////    cout <<bset1.reset() << endl;
////
////    //flip function flips all bits
////    cout << set8.flip(2) << endl;
////    cout << set8.flip() << endl;
////
////    //Converting decimal number to binary number using bitset
////    int num = 100;
////    cout << "\n Decimal Number: "<< num
////        << "Binary equivalent: " << bitset<8> (num);
//
//RandomNumberSet randomNumberSet;
//
//randomNumberSet.set(4);
//randomNumberSet.set(10);
//randomNumberSet.set(20);
//
//RandomNumberSet randomNumberSet1;
//randomNumberSet1.set(10);
//randomNumberSet1.set(20);
//cout << "The set indices are"<< endl;
//cout << randomNumberSet.getIndices() << endl;
////int difference = randomNumberSet1 - randomNumberSet;
//return 0;
//}