#ifndef PLATEMODELFACTORY_H
#define PLATEMODELFACTORY_H

#include <QString>
#include "datasource.h"
#include "platemodel.h"
#include "provincequery.h"
#include "countyquery.h"
#include "cityquery.h"
#include "platecodequery.h"

class PlateModelFactory
{
public:
    static PlateModel *createPlateModel(DataSource *dataSource);
    static Plate* createPlate(int plateId);
};

#endif // PLATEMODELFACTORY_H
