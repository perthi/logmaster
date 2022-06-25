// GUIGraphicalIndicator.h
// karl eirik bang fossberg

#ifndef GUI_GRAPHICAL_INDICATOR_H
#define GUI_GRAPHICAL_INDICATOR_H

#include <gui/common/GUIPainterClass.h>

class GUIGraphicalIndicator
    : public GUIPainterClass
{
public:
    GUIGraphicalIndicator();
    ~GUIGraphicalIndicator();

    void SetPosition(const int &value);

protected:
    virtual void paintEvent(QPaintEvent * /*event*/) override;

private:
    int m_indicatorPosition;
};

#endif // GUI_GRAPHICAL_INDICATOR_H
