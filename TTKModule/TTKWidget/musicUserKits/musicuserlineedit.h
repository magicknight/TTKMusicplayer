#ifndef MUSICUSERLINEEDIT_H
#define MUSICUSERLINEEDIT_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QLineEdit>
#include <QLabel>

#include "musicglobaldefine.h"

/*! @brief The class of the user lineedit.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_USER_EXPORT MusicUserLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    enum LabelType
    {
        User,       /*!< label type is user*/
        Passwd,     /*!< label type is password*/
        PasswdNew,  /*!< label type is new password*/
        PwdConfirm, /*!< label type is confirm password*/
        Mail        /*!< label type is mail*/
    };

    /*!
     * Object contsructor.
     */
    explicit MusicUserLineEdit(QWidget *parent = 0);

    /*!
     * Get class object name.
     */
    static QString getClassName();
    /*!
     * Set label and label type.
     */
    void setLabel(LabelType ty, QLabel *t, QLabel *s);
    /*!
     * Check the mail type valid.
     */
    inline bool getMailStatus() const { return m_mailContains;}
    /*!
     * Check the string type valid.
     */
    inline bool getStrStatus() const { return m_strContains;}

Q_SIGNALS:
    /*!
     * Check the new password strength.
     * -1 empty string, 0 weak, 1 middle, 2 strong
     */
    void checkPwdStrength(int code);

protected Q_SLOTS:
    /*!
     * Check the new password strength.
     */
    void checkPwdStrength();

protected:
    /*!
     * Override the widget event.
     */
    virtual void focusInEvent(QFocusEvent *event) override;
    virtual void focusOutEvent(QFocusEvent *event) override;
    /*!
     * Check the input valied when focus out.
     */
    void checkTheInput();
    /*!
     * Show mail label.
     */
    void showLabel();
    /*!
     * Show string label.
     */
    void showLabel(int s, int e);
    /*!
     * Show label info that means you input is valid or not.
     */
    void labelCheck(bool check);

    QLabel *m_tipsLabel;
    QLabel *m_statusLabel;
    LabelType m_type;
    bool m_mailContains;
    bool m_strContains;

};

#endif // MUSICUSERLINEEDIT_H
