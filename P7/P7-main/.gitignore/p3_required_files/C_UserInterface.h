#ifndef CUI_H
#define CUI_H

class C_UI // inherit from UI
{
    public:
    void menu(/* B container */, /* A container */) const;     
    static void addB(/* B container */); 
    static void dropB(/* B container */, /* B iterator */);    
};

#endif