#include "platemodelfactory.h"

Plate* PlateModelFactory::createPlate(int plateId)
{
    ProvinceQuery provinceQuery;
    CountyQuery countyQuery;
    CityQuery cityQuery;
    PlateCodeQuery plateCodeQuery;
    QString city = cityQuery.getDataForId(plateId);

    const QString province = provinceQuery.getDataForId(plateId);
    const QString county = countyQuery.getDataForId(plateId);
    const QString plateCode = plateCodeQuery.getDataForId(plateId);
    // FIXME: is category still needed ? Last plateCode is treated as category
    return new Plate(plateCode, city, county, province, plateCode);
}

PlateModel* PlateModelFactory::createPlateModel(DataSource *dataSource)
{
    int numberOfEntries = dataSource->getNumberOfEntries();
    Plate *plate;
    PlateModel *plateModel = new PlateModel();

    for (int i = 0; i < numberOfEntries; i++) {
        plate = createPlate(i);
        plateModel->addPlate(*plate);
    }

    return plateModel;
}
