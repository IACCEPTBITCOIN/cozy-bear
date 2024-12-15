#ifndef AUI_H
#define AUI_H

class A_UI // inherit from UI
{
    public:
    void menu(/* B container */, /* A container */) const;    
    static void addB(/* A iterator */, /* B container */, /* B iterator */);
    static void dropB(/* A iterator */, /* B iterator */);         
};

#endif