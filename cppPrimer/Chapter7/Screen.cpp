#include <iostream>
#include <string>

using namespace std;



class Screen {
public:
    using pos = std::string::size_type;


private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

public:
    Screen() = default;
    Screen(pos h, pos w) : height(h), width(w), contents(h * w,' ') {}
    Screen& move(pos r, pos c) {
        cursor = r * width + c;
        return *this;}

    Screen& set(char c) {
        contents[cursor] = c;
        return *this;}

    Screen& set(pos r, pos c, char ch) {
        contents[r * width + c] = ch;
        return *this;}

    Screen& display(ostream& os) {
        do_display(os);
        return *this;}
    const Screen& display(ostream& os) const {
        do_display(os);
        return *this;}
private:
    void do_display(ostream& os) const {
        for (pos r = 0; r < height; ++r) {
            for (pos c = 0; c < width; ++c) {
                os << contents[r * width + c];
            }
            os << '\n';
        }
    }



};


int main(){

    Screen myScreen(2, 5);
    Screen::pos cursor = 0;
    Screen a = {1,2};
    myScreen.move(0, 0).set(1, 1, 'e').set(1, 2, 'l').set(1, 3, 'l').set(1, 4, 'o').display(cout);
    
    return 0;
}