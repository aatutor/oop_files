
struct Fraction {
private:
    int ch_;
    int zn_;
public:
    void Init(int a, int b) {
        ch_ = a;
        zn_ = b;
    }
    double Sum(Fraction other) {
        return (ch_*other.zn_ + other.ch_*zn_)/(double)(zn_*other.zn_);
    }
    double Sub(Fraction other) {
        other.ch_ *= -1;
        return Sum(other);
    }
    double Mult(Fraction other) {
        return ch_ * other.ch_ / (zn_ * other.zn_);
    }
    double Div(Fraction other) {
        other.Init(other.zn_, other.ch_);
        return Mult(other);
    }
};