// Квадратная матрица
struct matrix {
private:
    int size;
    double** array;
    
public:
    matrix(int size);

    void fillRandomly();

    void fillManually();

    void print();

    double det();
};