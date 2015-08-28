#include <QDebug>

#include "platemodel.h"

PlateModel::PlateModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

PlateModel::PlateModel(const PlateModel &plateModel):
    m_list(plateModel.m_list)
{
}

PlateModel& PlateModel::operator= (const PlateModel &plateModel)
{
    if (this == &plateModel)
        return *this;

    m_list = plateModel.m_list;

    return *this;
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
    if (index.row() < 0 || index.row() >= m_list.size()) {
        qCritical() << "QModelIndex is not within list";
        return QVariant();
    }

    const Plate* plate = &m_list[index.row()];

    switch(role) {
    case NameRole:
        return plate->name();
    case CategoryRole:
        return plate->category();
    case ProvinceRole:
        return plate->province();
    case CountyRole:
        return plate->county();
    case CityRole:
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
