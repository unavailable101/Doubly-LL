class List {
    public:
    virtual void addHead(int) = 0;
    virtual void addTail(int) = 0;
    virtual void addAt(int, int) = 0;
    virtual int remove(int) = 0;
    virtual int removeAt(int) = 0;
    virtual int removeAll(int) = 0;
    virtual int getNum(int) = 0;
    virtual int getPos(int) = 0;
    virtual void printHead() = 0;
    virtual void printTail() = 0;
};