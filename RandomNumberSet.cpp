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
    std::set_intersection(randomNumberSet1.bitsetIndices.begin(),randomNumberSet1.bitsetIndices.end()
            ,randomNumberSet2.bitsetIndices.begin(),randomNumberSet2.bitsetIndices.end(),
                          std::back_inserter(randomNumberSet1.differenceVector));

    return randomNumberSet1.bitsetIndices.size() > randomNumberSet2.bitsetIndices.size() ?
           randomNumberSet1.bitsetIndices.size() - randomNumberSet1.differenceVector.size():randomNumberSet2.bitsetIndices.size()-randomNumberSet1.differenceVector.size();
}


RandomNumberSet :: RandomNumberSet() {
    randomNumberBitVector.resize(39,0);
}

RandomNumberSet ::RandomNumberSet(int n) {
    vector<bool> randomNumberBitVector (n,0);
}

void RandomNumberSet::reset() {
    randomNumberBitset.reset();
    bitsetIndices.clear();
}

bool RandomNumberSet::set(int n) {
    if(0>=n<randomNumberBitVector.size()) {
        //return false when bit is already set
        if(randomNumberBitset[n]==1) {
            return false;
        }
            //else set the bit and return true
        else {
            if(randomNumberBitset.count() < 5){
                randomNumberBitset[n] = 1;
                randomNumberBitVector[n] = true;
                bitsetIndices.push_back(n);
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
    return randomNumberBitset.count();
}

vector<int> RandomNumberSet::storeIndices()  {
    //loop through bitset. If the bit is set, push this to a vector
    for (int i = 0; i < randomNumberBitset.size(); i++) {
        if(randomNumberBitset[i]==1){
            bitsetIndices.push_back(i);
        }
    }

    return bitsetIndices;

}

int main () {

    RandomNumberSet randomNumberSet1;
    randomNumberSet1.set(1);
    randomNumberSet1.set(2);
    randomNumberSet1.set(3);
    randomNumberSet1.set(5);
    randomNumberSet1.set(11);

    cout << randomNumberSet1.randomNumberBitVector<< endl;

    RandomNumberSet randomNumberSet2;
    randomNumberSet2.set(1);
    randomNumberSet2.set(2);
    randomNumberSet2.set(3);
    randomNumberSet2.set(4);
    randomNumberSet2.set(11);

    cout << randomNumberSet2.randomNumberBitVector<< endl;

    int size = randomNumberSet1 - randomNumberSet2;
    cout << "Difference is: "<< size;
    return 0;

}











