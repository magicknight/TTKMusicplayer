#ifndef MUSICEXTRACTWRAP_H
#define MUSICEXTRACTWRAP_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musicglobaldefine.h"

class MusicBackgroundImage;

/*! @brief The class of the extract data wrap.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_CORE_EXPORT MusicExtractWrap
{
public:
    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Transfer file to image data.
     */
    static bool outputThunderSkin(QPixmap &image, const QString &path);

    /*!
     * Transfer file to image data.
     */
    static bool outputSkin(MusicBackgroundImage *image, const QString &path);
    /*!
     * Transfer image data to file.
     */
    static bool inputSkin(MusicBackgroundImage *image, const QString &path);

    /*!
     * Transfer file to data.
     */
    static bool outputText(QByteArray &data, const QString &path);
    /*!
     * Transfer data to file.
     */
    static bool inputText(const QByteArray &data, const QString &path);

};

#endif // MUSICEXTRACTWRAP_H
