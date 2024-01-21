#include<bits/stdc++.h>
#include"Model/RubiksCube3dArray.cpp"
#include "Model/RubiksCube1dArray.cpp"
#include "Solver/DFSSolver.h"

using namespace std;
int main() {
        RubiksCube3dArray cubie1;
        //RubiksCube3dArray cubie2;

        vector<RubiksCube :: MOVE> movesToShuffle = cubie1.randonShuffleCube(5);
        cubie1.print();
        for(auto move : movesToShuffle) cout << cubie1.getMove(move) << " ";
        cout << endl;

        DFSSolver<RubiksCube3dArray,Hash_3d_Array> dfsSolver(cubie1,8);
        vector<RubiksCube :: MOVE> movesToSolve = dfsSolver.solve();
        dfsSolver.rubiksCube.print();
        for(auto move : movesToSolve) cout << cubie1.getMove(move) << " ";
        cout << endl;


//
//        if(cubie1==cubie2) cout << "Cubes are same" << "\n";
//        else cout << "Cubes are not same" << "\n";
//
//        cubie2.l();
//        if(cubie1==cubie2) cout << "Cubes are same" << "\n";
//        else cout << "Cubes are not same" << "\n";
//
//        cubie2 = cubie1;
//
//        if(cubie1==cubie2) cout << "Cubes are same" << "\n";
//        else cout << "Cubes are not same" << "\n";
//
//        unordered_map<RubiksCube3dArray,bool,Hash_3d_Array> mp1;
//
//        mp1[cubie1] = true;
//
//        if(mp1[cubie1]) cout << "Cubie 1 is present" << "\n";
//        else cout << "Cubie 1 is not present" << "\n";
//    cubie.print();
//    cubie.b();
//    cubie.print();

//    RubiksCube1dArray cubie;
//    cubie.b();
//    cubie.print();
//    cubie.bPrime();
//    cubie.print();
//    cubie.b2();
//    cubie.print();
//    cubie.b2();
//    cubie.print();

}
