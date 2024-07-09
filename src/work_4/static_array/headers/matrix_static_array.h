struct matrix {
private:
    static const int MAX_SIZE = 10;
    int size;
    double array[MAX_SIZE][MAX_SIZE];
    
public:
    matrix(int size);

    void fillRandomly();

    void fillManually();

    void print();

    double det();
};