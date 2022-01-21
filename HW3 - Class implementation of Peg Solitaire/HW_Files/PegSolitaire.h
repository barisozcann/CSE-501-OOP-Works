#include <vector>
#include <string>


using namespace std;

enum class cell { Empty = 0, Peg = 1, nonUsed = 2 }; //This is strong enum type of cell representation

class PegSolitaire{
public:
    PegSolitaire(); //No parameter constructor

    PegSolitaire(string fileName,bool isDiagonal=false); //string file name constructor

    PegSolitaire(const int& boardType,bool isDiagonal=false); //integer boardtype constructor


    virtual ~PegSolitaire(); //Destructor

    const string &getFileName() const; //fileName getter method

    void setFileName(const string &fileName); //fileName setter method

    bool isDiagonal1() const; //isDiagonal getter

    void setIsDiagonal(bool isDiagonal); //isDiagonal setter

    int getBoardType() const; //BoardType getter

    void setBoardType(int boardType); //BoardType setter

    class Cell{ //inner class Cell
    public:
        Cell(); //no parameter constructor of Cell class

        Cell(int x, int y, char cellState); //location and state constructor of Cell class

        virtual ~Cell(); //Deconstructor of Cell class

        int getX() const; //x getter method

        void setX(int x); //x setter method

        int getY() const; //y getter method

        void setY(int y); //y setter method

        char getCellState() const; //cellState getter method

        void setCellState(char cellState); //cellState setter method

    private:
        int x,y; //x and y coordinates of Cell class
        char cellState; //char value of Cell class
        cell currentCell; //strong enum type of Cell class
    };

    const vector<vector<Cell>> &getCurrentBoard() const; //getter method of 2D vector

    void setCurrentBoard(const vector<vector<Cell>> &currentBoard); //setter method of 2D vector

    void showBoard(bool isDiagonal=false); //This method delegation method. Original method is in private section.

    bool isLegal(string moveCommand); //This method delegation method. Original method is in private section.

    inline void readFile(string fileName); //This method reads the file

    void play(string moveCommand); //This method delegation method. Original method is in private section.

    int numberOfPegs(); //This method delegation method. Original method is in private section.

    int numberOfEmpty(); //This method delegation method. Original method is in private section.

    void play(); //This method delegation method. Original method is in private section.

    void playGame(); //This method delegation method. Original method is in private section.

    int numberOfPegs(const vector<vector<Cell>>& inputBoard); //This method returns number of pegs

    int numberOfEmpty(const vector<vector<Cell>>& inputBoard); //This method returns number of empty cells


    void playMenu(int personMove=0,int computerMove=0,bool isDiagonal=false); //This method delegation method. Original method is in private section.

    static void showFiles(); //This method shows all files in current directory

    vector<int> getStats(string fileName); //This method returns statistics about game

    vector<vector<Cell>> textToVectors(string fileName); //This method converts txt file into 2D vector(Board)

    static int totalActivePegs(); //This method returns number of pegs in all active classes

    bool hasMore(const PegSolitaire& otherClass); //This method compares number of pegs with another class

private:
    vector<vector<Cell>> currentBoard; //2D vector (Board)
    string fileName; //string filename
    bool isDiagonal; //isDiagonal. It's only true for Board 6. It activates diagonal moves.
    int boardType; //This is for stating board type 1-6
    static int totalNumberOfPegs; //This represents total number of pegs in all active classes
    static vector<int> totalPegs; //This vector holds number of pegs of different active classes

    void showBoard(vector<vector<Cell>> inputBoard, bool isDiagonal=false); //This method shows Board

    bool isLegal(vector<vector<Cell>> inputBoard, string moveCommand); //This method says if the move is legal for board1-5

    void play(vector<vector<Cell>>& inputBoard, string moveCommand); //This method makes move by taking string command

    vector<vector<int>> returnPegCoordinates(vector<vector<Cell>> inputBoard); //This method returns all coordinates of pegs in a board

    void play(vector<vector<Cell>>& inputBoard); //This method makes a single computer move

    int findIndexOfLetter(char letter) const; //This method converts string column names to integer values (A=0,B=1,C=2...)

    void movePegComputerHelper(vector<vector<Cell>>& inputBoard, string moveCommand); //Helper method of computer move

    bool isOver(vector<vector<Cell>> inputBoard); //This method returns true only if there is no available move

    bool isOver(); //Delegation method of the method above

    void playGame(vector<vector<Cell>>& inputBoard); //This method makes computer moves until the game ends

    int relativeToRealColumnBoard6(vector<vector<Cell>> inputBoard, int sourceRow, int sourceColumnRelative); //This method makes column conversion for board6

    int relativeToRealColumnBoard6(int sourceRow, int sourceColumnRelative); //Delegation method of the method above

    string numberToColumnName6(vector<vector<Cell>> inputBoard, int row, int inputColumn); //This method makes column conversion for board6

    string numberToColumnName6(int row, int inputColumn);//Delegation method of the method above

    bool isLegalBoard6(vector<vector<Cell>> inputBoard, string moveCommand); //This method says if the move is legal for only board6

    bool isLegalBoard6(string moveCommand); //Delegation method of the method above

    void play6(vector<vector<Cell>>& inputBoard, string moveCommand); //This method makes move by taking string command for only board6

    void play6(string moveCommand); //Delegation method of the method above

    void play6(vector<vector<Cell>>& inputBoard); //This method makes a single computer move for only board6

    void play6(); //Delegation method of the method above

    bool isOverBoard6(vector<vector<Cell>> inputBoard); //This method returns true only if there is no available move for board6

    bool isOverBoard6(); //This method returns true only if there is no available move for board6

    void playGame6(vector<vector<Cell>>& inputBoard); //This method makes computer moves until the game ends for board6

    void playGame6(); //Delegation method of the method above

    void showScore(int numberOfPegs); //This method shows the score of a game

    void saveGame(const vector<vector<Cell>>& inputBoard, int personMove, int computerMove, int pegNumbers, bool isDiagonal = false); //This method saves game in to a txt file

    void saveGame(int personMove, int computerMove, int pegNumbers, bool isDiagonal = false); //Delegation method of the method above

    int takenPegs(const int& initialPegs, const int& currentPegs) const; //This method calculates taken pegs in a game

    void playMenu(vector<vector<Cell>>& inputBoard,int personMove=0,int computerMove=0,bool isDiagonal=false); //This method provides a game menu to play

};