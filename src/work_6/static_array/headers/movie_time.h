struct Time {
    int hour, minute;

    Time();
    Time(int, int);

    void printTime();

    bool operator==(const Time);
};
