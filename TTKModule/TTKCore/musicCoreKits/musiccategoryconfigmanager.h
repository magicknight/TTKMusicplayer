#ifndef MUSICCATEGORYCONFIGMANAGER_H
#define MUSICCATEGORYCONFIGMANAGER_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musicabstractxml.h"

/*! @brief The class of the playlist category item.
 * @author Greedysky <greedysky@163.com>
 */
typedef struct MUSIC_CORE_EXPORT MusicPlaylistCategoryItem
{
    QString m_id;
    QString m_name;

    MusicPlaylistCategoryItem()
    {

    }

    MusicPlaylistCategoryItem(const QString &id, const QString &name)
    {
        m_id = id;
        m_name = name;
    }
}MusicPlaylistCategoryItem;
MUSIC_DECLARE_LISTS(MusicPlaylistCategoryItem)


/*! @brief The class of the playlist category core.
 * @author Greedysky <greedysky@163.com>
 */
typedef struct MUSIC_CORE_EXPORT MusicPlaylistCategory
{
    QString m_category;
    MusicPlaylistCategoryItems m_items;
}MusicPlaylistCategory;
MUSIC_DECLARE_LISTS(MusicPlaylistCategory)


/*! @brief The class of the category Config Manager.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_CORE_EXPORT MusicCategoryConfigManager : public MusicAbstractXml
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicCategoryConfigManager(QObject *parent = 0);

    /*!
     * Get class object name.
     */
    static QString getClassName();
    /*!
     * Read user datas from xml file by given name.
     */
    inline bool readCategoryConfig() { return readConfig(":/data/playlist"); }
    /*!
     * Read user datas into xml file.
     */
    void readCategoryConfig(MusicPlaylistCategorys &records, const QString &key);

};

#endif // MUSICCATEGORYCONFIGMANAGER_H
