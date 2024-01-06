//
// Created by Aditya Parmar on 03-01-2024.
//
#include"RubiksCube.h"

class RubiksCube3dArray : public RubiksCube {
private :
    //this cannot be accessed by the objects of this class
    //we write all the auxiliary/helper functions here
    void rotateFace(int ind){
        char temp[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp[i][j] = cube[ind][i][j];
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cube[ind][i][j] = temp[2-j][i];
            }
        }
//        for(int i=0;i<3;i++) cube[ind][0][i] = temp[2-i][0];
//        for(int i=0;i<3;i++) cube[ind][1][i] = temp[2-i][1];
//        for(int i=0;i<3;i++) cube[ind][2][i] = temp[2-i][2];

    }
public :
    char cube[6][3][3];
    RubiksCube3dArray(){ //constructor
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    bool isSolved() const override{
        // write the code here
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    else return false;
                }
            }
        }
        return true;
    }

    COLOR getColor(FACE face,unsigned row,unsigned col) const override{
        //write the code here
        char color = cube[int(face)][row][col];
        switch(color){
            case 'W':
                return COLOR :: WHITE;
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

        char temp[3] = {};
        for(int i=0;i<3;i++) temp[i] = cube[4][0][i];
        for(int i=0;i<3;i++) cube[4][0][i] = cube[1][0][i];
        for(int i=0;i<3;i++) cube[1][0][i] = cube[2][0][i];
        for(int i=0;i<3;i++) cube[2][0][i] = cube[3][0][i];
        for(int i=0;i<3;i++) cube[3][0][i] = temp[i];

        return *this;
    }

    RubiksCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &l() override{
        this->rotateFace(1);

        char temp[3] = {};
        for(int i=0;i<3;i++) temp[i] = cube[4][2-i][2];
        for(int i=0;i<3;i++) cube[4][2-i][2] = cube[5][i][0];
        for(int i=0;i<3;i++) cube[5][i][0] = cube[2][i][0];
        for(int i=0;i<3;i++) cube[2][i][0] = cube[0][i][0];
        for(int i=0;i<3;i++) cube[0][i][0] = temp[i];

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
        for(int i=0;i<3;i++) temp[i] = cube[0][2][i];
        for(int i=0;i<3;i++) cube[0][2][i] = cube[1][2-i][2];
        for(int i=0;i<3;i++) cube[1][2-i][2] = cube[5][0][2-i];
        for(int i=0;i<3;i++) cube[5][0][2-i] = cube[3][i][0];
        for(int i=0;i<3;i++) cube[3][i][0] = temp[i];

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
        for(int i=0;i<3;i++) temp[i] = cube[0][i][2];
        for(int i=0;i<3;i++) cube[0][i][2] = cube[2][i][2];
        for(int i=0;i<3;i++) cube[2][i][2] = cube[5][i][2];
        for(int i=0;i<3;i++) cube[5][i][2] = cube[4][2-i][0];
        for(int i=0;i<3;i++) cube[4][2-i][0] = temp[i];

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
        for(int i=0;i<3;i++) temp[i] = cube[0][0][i];
        for(int i=0;i<3;i++) cube[0][0][i] = cube[3][i][2];
        for(int i=0;i<3;i++) cube[3][i][2] = cube[5][2][2-i];
        for(int i=0;i<3;i++) cube[5][2][2-i] = cube[1][2-i][0];
        for(int i=0;i<3;i++) cube[1][2-i][0] = temp[i];


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
        for (int i = 0; i < 3; i++) temp[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp[i];

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

