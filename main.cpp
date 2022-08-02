#include <iostream>

bool isCrossZeroDot(char chr){
    return ((chr=='X'||chr=='O'||chr=='.')?true:false);
}

bool isValidStr(std::string str){
    if (str.length()!=3) return false;
    for (int i=0;i<3;i++){
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
bool isValidGame(std::string s1,std::string s2,std::string s3){
    if (!isValidStr(s1)) return false;
    if (!isValidStr(s2)) return false;
    if (!isValidStr(s3)) return false;

    if (count(s1+s2+s3,'X')<count(s1+s2+s3,'O')) return false;
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

char isRowWin(std::string game){
    int cross=0,zero=0;
    if (game.length() != 9) return '\0';
    for (int k=0;k<3;k++) {
        for (int i = 0; i < 3; i++) {
            zero = cross = 0;
            if (game[i+k*3] == 'X')
                cross++;
            else if (game[i+k*3] == 'O')
                zero++;
            if (zero==3) return 'O';
            if (cross==3) return 'X';
        }
    }
    return '.';
}

char isColWin(std::string game){
    int cross=0,zero=0;
    if (game.length()!=9) return '\0';
    for (int k=0;k<3;k++) {
        for (int i = 0; i < 3; i++) {
            zero = cross = 0;
            if (game[i*3+k] == 'X')
                cross++;
            else if (game[i*3+k] == 'O')
                zero++;
            if (zero==3) return 'O';
            if (cross==3) return 'X';
        }
    }
    return '.';
}



char isDiagWin(std::string game){
    int cross=0,zero=0;
    if (game.length()!=9) return '\0';
    for (int i=3;i>0;i--) {
        zero = cross = 0;
        if (game[2*i] == 'X')
            cross++;
        else if (game[2*i] == 'O')
            zero++;
        if (zero==3) return 'O';
        if (cross==3) return 'X';
    }
    for (int i = 0; i < 3; i++) {
        zero = cross = 0;
        if (game[i*3+i] == 'X')
            cross++;
        else if (game[i*3+i] == 'O')
            zero++;
        if (zero==3) return 'O';
        if (cross==3) return 'X';
    }
    return '.';
}
char winner(std::string game){
    bool crossWin=false, zeroWin=false;
    if (isColWin(game)=='X' || isRowWin(game)=='X' || isDiagWin(game)=='X')
        crossWin=true;
    if (isColWin(game)=='O' || isRowWin(game)=='O' || isDiagWin(game)=='O')
        zeroWin=true;
    if (zeroWin && crossWin || (isColWin(game)=='.' && isRowWin(game)=='.' && isDiagWin(game)=='.')) return '0';
    else if (zeroWin) return 'O';
    else if (crossWin) return 'X';
    else return '\0';
}

void printWin(char winner){
    if (winner == 'X') std::cout << "Petya wins" << std::endl;
    if (winner == 'O') std::cout << "Vanya wins" << std::endl;
    if (winner == '0') std::cout << "Nobody wins" << std::endl;
    if (winner == '\0') std::cout << "Game is not ended" << std::endl;
}

int main() {
    std::string str1,str2,str3;
    std::cout << "Input Cross&Zero: " << std::endl;
    std::cin >> str1>>str2>>str3;
    if (isValidStr(str1)&& isValidStr(str2)&& isValidStr(str3)){
        str1 = gameStr(str1,str2,str3);
    }
    printWin(winner(str1));

    return 0;
}
