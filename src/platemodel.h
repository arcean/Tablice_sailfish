#ifndef PLATEMODEL_H
#define PLATEMODEL_H

#include <QAbstractListModel>
#include "plate.h"

class PlateModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PlateModel(QObject *parent = 0);
    PlateModel(const PlateModel &plateModel);

    enum PlateRoles {
        NameRole = Qt::UserRole + 1,
        CategoryRole,
        ProvinceRole,
        CountyRole,
        CityRole
    };

    QHash<int, QByteArray> roleNames() const;

    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    void addPlate(const Plate &plate);

    PlateModel &operator =(const PlateModel &plateModel);

private:
    QList<Plate> m_list;
};

#endif // PLATEMODEL_H
