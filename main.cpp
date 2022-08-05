#include <iostream>

bool isCrossZeroDot(char chr){
    return ((chr=='X'||chr=='O'||chr=='.')?true:false);
}

bool isValidStr(std::string str,int length){
    if (str.length()!=length) return false;
    for (int i=0;i<length;i++){
        if (!isCrossZeroDot(str[i])) return false;
    }
    return true;
}
std::string gameStr(std::string s1,std::string s2,std::string s3){ return s1+s2+s3;}

int count(std::string str,char chr){
    int count=0;
    for (int i=0;i<str.length();i++){
        if(str[i]==chr) count++;
    }
    return count;
}
bool isValidGame(std::string game,bool crossWin,bool zeroWin){
    if(!isValidStr(game,9)) return false;
    int xCount=count(game,'X'),oCount=count(game,'O');
    if (xCount<oCount || oCount<(xCount-1) || (crossWin && oCount>=xCount) || (zeroWin && oCount>=(xCount-1)))
        return false;
    return true;
}
/*
 *     1   2   3
 *  1  .   .   .
 *  2  .   .   .
 *  3  .   .   .
 */

char chrOfGame(std::string game, int x, int y){
    return ((game.length()==9 && x>0 && x<4 && y>0 && y<4)?game[x-1+(y-1)*3]:'\0');
}

bool isGameWin(std::string game,char chr){
    int mark;
    bool markWin=false;
    if (game.length() != 9) return '\0';
//    Cols
    for (int k=0;k<3;k++) {
        mark = 0;
        for (int i = 0; i < 3; i++) {
            if (game[i+k*3] == chr)
                mark++;
            if (mark==3) markWin= true;
        }
    }
//    Rows
    for (int k=0;k<3;k++) {
        mark = 0;
        for (int i = 0; i < 3; i++) {
            if (game[i*3+k] == chr)
                mark++;
            if (mark==3) markWin= true;
        }
    }
//    Diags
    mark = 0;
    for (int i=3;i>0;i--) {
        if (game[2*i] == chr)
            mark++;
        if (mark==3) markWin= true;
    }
    mark = 0;
    for (int i = 0; i < 3; i++) {
        if (game[i*3+i] == chr)
            mark++;
        if (mark==3) markWin= true;
    }
    return markWin;
}


void winner(std::string game){
    bool crossWin=false, zeroWin=false;
    crossWin=isGameWin(game,'X');
    zeroWin= isGameWin(game,'O');
    if (!isValidGame(game,crossWin,zeroWin))  {
        std::cout << "Game incorrect" << std::endl;
        return;
    }
    if (zeroWin && crossWin || count(game,'.')==0)
        std::cout << "Nobody wins" << std::endl;
    else if (zeroWin)
        std::cout << "Vanya wins" << std::endl;
    else if (crossWin)
        std::cout << "Petya wins" << std::endl;
    else
        std::cout << "Game is not ended" << std::endl;
}


std::string inputGame(){
    while (true) {
        std::string game, str;
        bool isValid = true;
        std::cout << "Input Cross&Zero: " << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cin >> str;
            if (!isValidStr(str,3)) {
                isValid = false;
                break;
            }
            game += str;
        }
        if (isValid) {
            return game;
        } else {
            std::cout << "Wrong input! Use only \'.\' \'X\' \'O\'. Try again" << std::endl;
        }
    }
}

void test(std::string game){
    for (int i=0;i<game.length();i++){
        std::cout << game[i];
        if((i+1)%3==0)
            std::cout << std::endl;
    }
    winner(game);
}

int main() {
    std::string game;
    test("X..OXOOOO");
    test("X...X.OO.");
    test("XXOOOXXOX");
    test("XO.XO.X.O");
    test("OX.XOXX.O");
    test("..XOX.X.O");
    test("0........");

//    winner(inputGame());
    return 0;
}
