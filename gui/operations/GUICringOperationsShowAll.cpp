// GUICringOperationsShowAll.cpp
// karl eirik bang fossberg

#include "GUICringOperationsShowAll.h"

#include "GUICringOperationsBase.h"
#include "GUICringOperationsCoating.h"
#include "GUICringOperationsPatching.h"
#include "GUICringOperationsSurfacePrep.h"
#include "GUICringOperationsWrapping.h"
#include "GUICringOperationsSequencer.h"

#include <QtWidgets/QHBoxLayout>
#include <vector>

#include <api/api-hmi/APIHmiOperation.h>
#include <api/api-hmi/APIHmiOperationCoating.h>
#include <api/api-hmi/APIHmiOperationSurfacePrep.h>
#include <api/api-hmi/APIHmiOperationWrapping.h>
#include <api/api-hmi/APIHmiOperationPatching.h>




GUICringOperationsShowAll::GUICringOperationsShowAll()
{
    QHBoxLayout *pRootLayout = new QHBoxLayout();

    // SEQUENCER
    pRootLayout->addWidget(new GUICringOperationsSequencer());

    // OPERATIONS
    pRootLayout->addWidget(new GUICringOperationsPatching(std::make_shared<APIHmiOperationPatching>()));
    pRootLayout->addWidget(new GUICringOperationsCoating(std::make_shared<APIHmiOperationCoating>()));
    pRootLayout->addWidget(new GUICringOperationsWrapping(std::make_shared<APIHmiOperationWrapping>()));
    pRootLayout->addWidget(new GUICringOperationsSurfacePrep(std::make_shared<APIHmiOperationSurfacePrep>()));
    // pRootLayout->addWidget(new GUICringOperationsSurfacePrep(listOfSteps));
    // pRootLayout->addWidget(new GUICringOperationsBase(std::make_shared<APIHmiOperation>(eHMI_TYPE::UNKNOWN)));

    setLayout(pRootLayout);
    // setFixedWidth(520);
}

GUICringOperationsShowAll::~GUICringOperationsShowAll()
{
    //
}