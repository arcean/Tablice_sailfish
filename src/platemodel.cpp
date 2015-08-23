#include <QDebug>

#include "platemodel.h"

PlateModel::PlateModel(QObject *parent) :
    QAbstractListModel(parent)
{
}


QHash<int, QByteArray> PlateModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames[NameRole] = "name";
    roleNames[CategoryRole] = "category";
    roleNames[ProvinceRole] = "province";
    roleNames[CountyRole] = "county";
    roleNames[CityRole] = "city";

    return roleNames;
}


QVariant PlateModel::data(const QModelIndex &index, int role) const
{
    qDebug() << "Data asked for " << index.row() << " and role " << role;
    if (index.row() < 0 || index.row() >= m_list.size()) {
        qCritical() << "QModelIndex is not within list";
        return QVariant();
    }

    const Plate* plate = &m_list[index.row()];

    switch(role) {
    case NameRole:
         qDebug() << "returning NameRole " << plate->name();
        return plate->name();
    case CategoryRole:
        qDebug() << "returning CategoryRole " << plate->category();
        return plate->category();
    case ProvinceRole:
        qDebug() << "returning ProvinceRole " << plate->province();
        return plate->province();
    case CountyRole:
        qDebug() << "returning CountyRole " << plate->county();
        return plate->county();
    case CityRole:
        qDebug() << "returning CityRole " << plate->city();
        return plate->city();
    default:
        return QVariant();
    }
}

int PlateModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_list.count();
}

void PlateModel::addPlate(const Plate &plate)
{
    beginInsertRows(QModelIndex(), rowCount(QModelIndex()), rowCount(QModelIndex()));
    m_list.append(plate);
    endInsertRows();
}
