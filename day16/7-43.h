class NoDeault
{
    public:
        NoDeault(int i);
};

class C
{
    public:
        C(): nd(0) {}
    private:
        NoDeault nd;
};
