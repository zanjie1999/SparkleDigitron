class SparkleDigitron {
   private:
    int *pins;

    // 数码对应的脚操作 可以用test2.cpp测出来 大概不通用
    int indexM[7][7][2] = {
        // 4位数字
        {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {5, 4}},
        {{0, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {6, 4}},
        {{0, 2}, {1, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {6, 5}},
        {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 3}, {6, 3}, {4, 5}},
        {
            {0, 6},  // :
            {1, 6},  // .
        },
        {
            {0, 4},  // bt
            {0, 5},  // clock
            {1, 4},  // tf
            {1, 5},  // low bat
            {2, 4},  // fm
            {2, 5},  // full bat
            {3, 4},  // aux
        }};

    // 数字对应字模
    unsigned char charM[18][7] = {
        {1, 1, 1, 1, 1, 1, 0},  // 0
        {0, 1, 1, 0, 0, 0, 0},  // 1
        {1, 1, 0, 1, 1, 0, 1},  // 2
        {1, 1, 1, 1, 0, 0, 1},  // 3
        {0, 1, 1, 0, 0, 1, 1},  // 4
        {1, 0, 1, 1, 0, 1, 1},  // 5
        {1, 0, 1, 1, 1, 1, 1},  // 6
        {1, 1, 1, 0, 0, 0, 0},  // 7
        {1, 1, 1, 1, 1, 1, 1},  // 8
        {1, 1, 1, 1, 0, 1, 1},  // 9
        {1, 1, 1, 0, 1, 1, 1},  // A
        {0, 0, 1, 1, 1, 1, 1},  // b
        {1, 0, 0, 1, 1, 1, 0},  // C
        {0, 1, 1, 1, 1, 0, 1},  // d
        {1, 0, 0, 1, 1, 1, 1},  // E
        {1, 0, 0, 0, 1, 1, 1},  // F
        {0, 0, 0, 0, 0, 0, 1},  // -
        {0, 0, 0, 1, 0, 0, 0},  // _
    };

    bool scanM[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

   public:
    void init(int pins[7]);
    void scan();
    void clear();
    void showChar(int index, unsigned char num);
    void showIcon(int arrayIndex, int index);
    void delayScan(int ms);
};