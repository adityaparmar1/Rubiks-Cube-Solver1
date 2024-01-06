//
// Created by Aditya Parmar on 06-01-2024.
//

#include"RubiksCube.h"

class RubiksCube1dArray : public RubiksCube{
private :
    // Function that gives us index when FACE ind,row and col is known
    static inline int getIndex(int ind,int row,int col){
        return ((ind+8*ind) + ((3*row)+col));
    }

    void rotateFace(int ind){
        char temp[54] = {};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int index = getIndex(ind,i,j);
                temp[index] = cube[index];
            }
        }
        for(int i=0;i<3;i++) cube[getIndex(ind,0,i)] = temp[getIndex(ind,2-i,0)];
        for(int i=0;i<3;i++) cube[getIndex(ind,1,i)] = temp[getIndex(ind,2-i,1)];
        for(int i=0;i<3;i++) cube[getIndex(ind,2,i)] = temp[getIndex(ind,2-i,2)];

    }

public :
    char cube[54];

    RubiksCube1dArray(){ //constructor
        for(int i=0;i<6;i++){ //traverse for faces
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    int index = getIndex(i,j,k);
                    cube[index] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    bool isSolved() const override{
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    int index = getIndex(i,j,k);
                    if(this->cube[index] == getColorLetter(COLOR(i))) continue;
                    else return false;
                }
            }
        }
        return true;
    }

    COLOR getColor(FACE face,unsigned row,unsigned col) const override{
        int index = getIndex(int(face),int(row),int(col));
        char color = cube[index];
        switch(color){
            case 'W':
                return COLOR::WHITE;
            case 'G' :
                return COLOR :: GREEN;
            case 'R' :
                return COLOR :: RED;
            case 'B' :
                return COLOR :: BLUE;
            case 'O' :
                return COLOR :: ORANGE;
            case 'Y' :
                return COLOR :: YELLOW;
        }

    }

    RubiksCube &u() override{
        this->rotateFace(0);
        char temp[3]= {};

        for(int i=0;i<3;i++) temp[i] = cube[getIndex(4,0,i)];
        for(int i=0;i<3;i++) cube[getIndex(4,0,i)] = cube[getIndex(1,0,i)];
        for(int i=0;i<3;i++) cube[getIndex(1,0,i)] = cube[getIndex(2,0,i)];
        for(int i=0;i<3;i++) cube[getIndex(2,0,i)] = cube[getIndex(3,0,i)];
        for(int i=0;i<3;i++) cube[getIndex(3,0,i)] = temp[i];

        return *this;

    }

    RubiksCube &uPrime() override{
        this->u();
        this->u();
        this->u();

        return *this;

    }

    RubiksCube &u2() override{
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &l() override{
        this->rotateFace(1);

        char temp[3] = {};

        for(int i=0;i<3;i++) temp[i] = cube[getIndex(4,2-i,2)];
        for(int i=0;i<3;i++) cube[getIndex(4,2-i,2)] = cube[getIndex(5,i,0)];
        for(int i=0;i<3;i++) cube[getIndex(5,i,0)] = cube[getIndex(2,i,0)];
        for(int i=0;i<3;i++) cube[getIndex(2,i,0)] = cube[getIndex(0,i,0)];
        for(int i=0;i<3;i++) cube[getIndex(0,i,0)] = temp[i];

        return *this;

    }

    RubiksCube &lPrime() override{
        this->l();
        this->l();
        this->l();

        return  *this;
    }

    RubiksCube &l2() override{
        this->l();
        this->l();

        return  *this;
    }

    RubiksCube &f() override {
        this->rotateFace(2);

        char temp[3] = {};
        for(int i=0;i<3;i++) temp[i] = cube[getIndex(0,2,i)];
        for(int i=0;i<3;i++) cube[getIndex(0,2,i)] = cube[getIndex(1,2-i,2)];
        for(int i=0;i<3;i++) cube[getIndex(1,2-i,2)] = cube[getIndex(5,0,2-i)];
        for(int i=0;i<3;i++) cube[getIndex(5,0,2-i)] = cube[getIndex(3,i,0)];
        for(int i=0;i<3;i++) cube[getIndex(3,i,0)] = temp[i];

        return *this;
    }

    RubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &r() override {
        this->rotateFace(3);

        char temp[3] = {};
        for(int i=0;i<3;i++) temp[i] = cube[getIndex(0,i,2)];
        for(int i=0;i<3;i++) cube[getIndex(0,i,2)] = cube[getIndex(2,i,2)];
        for(int i=0;i<3;i++) cube[getIndex(2,i,2)] = cube[getIndex(5,i,2)];
        for(int i=0;i<3;i++) cube[getIndex(5,i,2)] = cube[getIndex(4,2-i,0)];
        for(int i=0;i<3;i++) cube[getIndex(4,2-i,0)] = temp[i];

        return *this;
    }

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }


    RubiksCube &b() override {
        this->rotateFace(4);

        char temp[3] = {};
        for(int i=0;i<3;i++) temp[i] = cube[getIndex(0,0,i)];
        for(int i=0;i<3;i++) cube[getIndex(0,0,i)] = cube[getIndex(3,i,2)];
        for(int i=0;i<3;i++) cube[getIndex(3,i,2)] = cube[getIndex(5,2,2-i)];
        for(int i=0;i<3;i++) cube[getIndex(5,2,2-i)] = cube[getIndex(1,2-i,0)];
        for(int i=0;i<3;i++) cube[getIndex(1,2-i,0)] = temp[i];


        return *this;
    }

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }



    RubiksCube &d() override {
        this->rotateFace(5);

        char temp[3] = {};
        for (int i = 0; i < 3; i++) temp[i] = cube[getIndex(2,2,i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2,2,i)] = cube[getIndex(1,2,i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1,2,i)] = cube[getIndex(4,2,i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4,2,i)] = cube[getIndex(3,2,i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3,2,i)] = temp[i];

        return *this;
    }

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }
};
