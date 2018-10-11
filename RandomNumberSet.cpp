//
// Created by Amit Chaudhari on 10/6/18.
//

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class RandomNumberSet {

public:
    RandomNumberSet();
    RandomNumberSet(int n);
    std::bitset<100> randomNumberBitset;
    void reset();
    bool set(int n);
    int size() const;;
    vector <int> differenceVector;
    vector <bool> randomNumberBitVector;
    std::vector<int>::iterator difference;
    friend ostream& operator<<(ostream &out, const vector<int> &bitsetIndices);
    friend int operator-(const RandomNumberSet &randomNumberSet);

};


//<< operator overloading. Takes bitset
 ostream & operator<<(ostream &out, const vector<bool> &randomNumberBitVector)
{
    for (int i = 0; i < randomNumberBitVector.size(); i++) {
        if(randomNumberBitVector[i] == true){
            out << right << setw(3) << i << endl;
        }
    }

    return out;
}

int operator-(RandomNumberSet & randomNumberSet1, RandomNumberSet& randomNumberSet2 ) {

        if(randomNumberSet1.randomNumberBitVector == randomNumberSet2.randomNumberBitVector) {
            return 0;
        }

        else {
            return (randomNumberSet1.randomNumberBitset ^ randomNumberSet2.randomNumberBitset).count();

        }

}


RandomNumberSet :: RandomNumberSet() {
    randomNumberBitVector.resize(39);
    differenceVector.resize(0);
 }

RandomNumberSet ::RandomNumberSet(int n) {
     randomNumberBitVector.resize(n);
    differenceVector.resize(0);
}

void RandomNumberSet::reset() {
//    randomNumberBitset.reset();
//    bitsetIndices.clear();
    randomNumberBitVector.clear();
}

bool RandomNumberSet::set(int n) {
    if(0>=n<randomNumberBitVector.size()) {
        //return false when bit is already set
        if(randomNumberBitVector[n]== true) {
            return false;
        }
        //else set the bit and return true
        else {
            if(count(randomNumberBitVector.begin(),randomNumberBitVector.end(),true) < 5){
                randomNumberBitVector[n] = true;
                randomNumberBitset[n] = 1;
                return true;
            }

            else {
                return false;
            }
        }
    }

    //return false if you pass an integer less than 0 and greater than 39
    else{
        return false;
    }
}

int RandomNumberSet::size() const {
    return count(randomNumberBitVector.begin(),randomNumberBitVector.end(),true);
}


int main () {

     RandomNumberSet randomNumberSet1 = RandomNumberSet(100);
     randomNumberSet1.set(2);
     randomNumberSet1.set(3);
    randomNumberSet1.set(6);
    cout << randomNumberSet1.randomNumberBitVector << endl;


    RandomNumberSet randomNumberSet2 = RandomNumberSet(100);
    randomNumberSet2.set(1);
    randomNumberSet2.set(3);
    randomNumberSet2.set(6);

    cout << randomNumberSet2.randomNumberBitVector<< endl;

    int size = randomNumberSet1 - randomNumberSet2;
    cout << size;

 }











