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
//    std::bitset<39> randomNumberBitset;
    vector<int> bitsetIndices;
    void reset();
    bool set(int n);
    int size() const;;
    vector<int> storeIndices();
    vector <int> differenceVector;
    vector <bool> randomNumberBitVector;
    friend ostream& operator<<(ostream &out, const vector<int> &bitsetIndices);
    friend int operator-(const RandomNumberSet &randomNumberSet);

};


//<< operator overloading. Takes bitset
 ostream & operator<<(ostream &out, const vector<int> &bitsetIndices)
{
    for (int i = 0; i < bitsetIndices.size(); i++) {
        out << right << setw(3) << bitsetIndices[i] << endl;
    }

    return out;
}

int operator-(RandomNumberSet & randomNumberSet1, RandomNumberSet& randomNumberSet2 ) {
        std::set_intersection(randomNumberSet1.randomNumberBitVector.begin(),randomNumberSet1.randomNumberBitVector.end()
                             ,randomNumberSet2.randomNumberBitVector.begin(),randomNumberSet2.randomNumberBitVector.end(),
                             std::back_inserter(randomNumberSet1.differenceVector));

        return count(randomNumberSet1.differenceVector.begin(),randomNumberSet1.differenceVector.end(),true);
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

vector<int> RandomNumberSet::storeIndices()  {
    //loop through bitset. If the bit is set, push this to a vector
    for (int i = 0; i <= randomNumberBitVector.size(); i++) {
        if(randomNumberBitVector[i]==1){
            bitsetIndices.push_back(i);
        }
    }

    return bitsetIndices;

}

int main () {

     RandomNumberSet randomNumberSet1 = RandomNumberSet(100);
     randomNumberSet1.set(34);
     randomNumberSet1.set(7);
     randomNumberSet1.set(1);
    randomNumberSet1.set(3);
    randomNumberSet1.set(78);
    cout << randomNumberSet1.storeIndices() << endl;


    RandomNumberSet randomNumberSet2 = RandomNumberSet(100);
    randomNumberSet2.set(70);
    randomNumberSet2.set(78);
    randomNumberSet2.set(11);
    randomNumberSet2.set(100);
    randomNumberSet2.set(3);
    //randomNumberSet2.set(7);
    //randomNumberSet2.set(35);
    cout << randomNumberSet2.storeIndices()<< endl;

    int size = randomNumberSet1 - randomNumberSet2;
    cout << size;
     return 0;

 }











