// GUICringOperationsShowAll.h
// karl eirik bang fossberg
//
// Temporary class to show all widgets that use the GUICringOperationsBase
// baseclass side by side.
//

#ifndef GUI_CRING_OPERATIONS_SHOW_ALL_H
#define GUI_CRING_OPERATIONS_SHOW_ALL_H

#include <QtWidgets/QWidget>

#include <utilities/GDefinitions.h>


class GUICringOperationsShowAll : public QWidget
{
public:
    API GUICringOperationsShowAll();
    API ~GUICringOperationsShowAll();
};

#endif // GUI_CRING_OPERATIONS_SHOW_ALL_H