#ifndef MUSICSPLITITEMCLICKEDLABEL_H
#define MUSICSPLITITEMCLICKEDLABEL_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QLabel>
#include "musicglobaldefine.h"

/*! @brief The class of the split item clicked widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicSplitItemClickedLabel : public QLabel
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicSplitItemClickedLabel(QWidget *parent = 0);

    /*!
     * Get class object name.
     */
    static QString getClassName();

private:
    /*!
     * Override the widget event.
     */
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    QRectF m_lineGeometry;
    QString m_currentString;

};

#endif // MUSICSPLITITEMCLICKEDLABEL_H
