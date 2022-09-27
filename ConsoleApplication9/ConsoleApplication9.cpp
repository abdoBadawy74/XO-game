#include<iostream>
#include<conio.h>
using namespace std;
char player = 'X'; //player x | o
char matrix[3][3] = {   '1','2','3'
                        ,'4','5','6'
                        ,'7','8','9' };





void print_matrix() //to print intial matrix
{
    system("cls");
    for (int i = 0;i < 3;i++)
    {
        cout << " " << "-------------" << endl;
        cout << " | ";
        for (int j = 0; j < 3;j++)
        {
            cout << matrix[i][j] << " | ";
        }
        cout << endl;
    }
    cout << " " << "-------------" << endl;
}
////////////////////////////////////////////////////

void play()
{

    int position;  //to define which num selected and replace it 
    cout << "it's " << player << " turn" << endl;
    cout << "Enter a number between [1, 9] (inclusive)." << endl;

    cin >> position;//1--9

    int mat[3][3] = {  1,2,3
                      ,4,5,6
                      ,7,8,9 };
    while (position > 9 || position < 1) {
        cout << "invalid choice!" << endl;
        cin >> position;
    }
    for (int i = 0; i < 3;i++)//to check position with matrix
    {
        for (int j = 0; j < 3;j++)
        {
            

            if (position == mat[i][j])
            {
                if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                {
                    matrix[i][j] = player;
                    if (player == 'X')   //to replace player x | o
                        player = 'O';
                    else
                        player = 'X';
                }
                else
                {

                    cout << "invalid choice!" << endl;
                    cin >> position;
                    i = -1;
                    j = -1;
                }
            }
        }
    }

}
/////////////////////////////////////////////////////////////

char win()
{
    int Xcounter = 0, Ocounter = 0;

    int no_win_counter = 0;

    for (int i = 0; i < 3;i++)//for rows
    {
        for (int j = 0; j < 3;j++)
        {
            if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                no_win_counter++;

            if (matrix[i][j] == 'X')
            {
                Xcounter++;
            }
            if (matrix[i][j] == 'O')
            {
                Ocounter++;
            }
        }
        if (Xcounter == 3 || Ocounter == 3)
        {
            print_matrix();

            if (Xcounter > Ocounter) {
                player = 'X';
                return 'X';
            }
            else {
                player = 'O';
                return 'O';
            }
        }

        else
        {
            Xcounter = 0;
            Ocounter = 0;
        }
    }

    /* ***********************************************/

    for (int i = 0; i < 3;i++)//for columns
    {
        for (int j = 0; j < 3;j++)
        {
            if (matrix[j][i] == 'X')
            {
                Xcounter++;
            }
            if (matrix[j][i] == 'O')
            {
                Ocounter++;
            }
        }
        if (Xcounter == 3 || Ocounter == 3)
        {
            print_matrix();
            if (Xcounter > Ocounter) {
                player = 'X';
                return 'X';
            }
            else {
                player = 'O';
                return 'O';
            }
        }
        else
        {
            Xcounter = 0;
            Ocounter = 0;
        }
    }

    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') {
        print_matrix();
        player = 'X';
        return 'X';
    }
    else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') {
        print_matrix();
        player = 'O';
        return 'O';
    }
    else if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X') {

        print_matrix();
        player = 'X';
        return 'X';
    }
    else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O') {

        print_matrix();
        player = 'O';
        return 'O';
    }
    if (no_win_counter == 0)
    {
        print_matrix();
        return 'N';
    }
    return 'A';
}
/**********************************************/
void reform()
{
    char n = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = n++;
        }
    }
}
int main()
{
    int n;
    do {

        while (win() == 'A')
        {
            print_matrix();
            play();
        }

        if (win() == 'X')
            cout << "X is winner" << endl;
        else if (win() == 'O')
            cout << "O is winner" << endl;
        else
            cout << "draw" << endl;

        cout << "enter 0 to exit, 1 to continue : ";
        cin >> n;
        reform();
    } while (n == 1);
}
/*
 -------------
 | 1 | 2 | 3 |
 -------------
 | 4 | 5 | 6 |
 -------------
 | 7 | 8 | 9 |
 -------------
*/