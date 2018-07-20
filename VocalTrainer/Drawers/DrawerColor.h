#ifndef DRAWERCOLOR_H
#define DRAWERCOLOR_H


#import "MidiEvent.h"

class DrawerColor
{
    uchar rgba[4];
public:
    static DrawerColor white();
    static DrawerColor black();

    DrawerColor();
    DrawerColor(uchar r, uchar g, uchar b, uchar a = 255);
    static DrawerColor fromHex(int hex);

    uchar operator[] (int index) const;
    uchar& operator[] (int index);

    uchar r() const;
    uchar g() const;
    uchar b() const;
    uchar a() const;

    uchar& r();
    uchar& g();
    uchar& b();
    uchar& a();

    bool operator==(const DrawerColor &rhs) const;

    bool operator!=(const DrawerColor &rhs) const;
};

#endif // DRAWERCOLOR_H