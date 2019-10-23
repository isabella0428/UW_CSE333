class IntPair{
    public:
        IntPair(int x, int y);
        void get(int *x, int *y) const;
        void set(const int const&x, const int const&y);

    private:
        int x_, y_;
};