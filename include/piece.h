#ifndef PIECE_H
#define PIECE_H

class game;

class cmove;

class piece
{
    public:
        piece();
        virtual ~piece();
        char getLabel();
        void setLabel(char lab);
        virtual bool isMoveOk(game* g, cmove* m) const = 0;
        void setIsWhite(bool val);
        bool getIsWhite();
    protected:
    private:
        char m_label;
        bool m_isWhite;
};




#endif // PIECE_H
