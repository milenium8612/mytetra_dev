#ifndef __RECORDTABLEMODEL_H__
#define __RECORDTABLEMODEL_H__

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>
#include <QObject>
#include <QtXml>


class RecordTableData;

class RecordTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    RecordTableModel(QObject *pobj=0);
    ~RecordTableModel();

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    // Интерфейс модели, предоставление данных по указанному индексу
    QVariant data(const QModelIndex &index, int role) const;
    
    // Интерфейс модели, сохранение вводимых данных по указанному индексу
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    // Интерфейс модели, сколько записей в таблице
    int rowCount(const QModelIndex &parent=QModelIndex()) const;

    // Интерфейс модели, сколько столбцов в таблице
    int columnCount(const QModelIndex &parent=QModelIndex()) const;

    // Возвращение указателя на модель конечных записей, т.е. на себя
    QAbstractTableModel *getModel(void);

    // Установка указателя на таблицу данных, с которой нужно работать модели
    void setTableData(RecordTableData *rtData);
    
    // Ссылка на данные, с которыми работает модель
    RecordTableData *getTableData(void);
    
    // Добавление записей
    int addTableData(int mode,
                     int pos,
                     QMap<QString, QString> fields,
                     QString text,
                     QMap<QString, QByteArray> files);

    // Удаление записей
    void removeRowsByList(QVector<int> delIdx);
    
private:

    // Указатель на таблицу конечных записей
    RecordTableData *table;

};

#endif // __RECORDTABLEMODEL_H__